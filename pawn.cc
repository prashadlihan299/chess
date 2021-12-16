#include "pawn.h"
#include<iostream>
Pawn::Pawn(bool white, int x, int y): Piece(white, x, y){ 
	setType(PieceType::PAWN);
    enPassant = false;
}

std::vector<Square> Pawn::attackSquares(Board &board){
        
        std::vector<Square> squares;
        if(isWhite()){
            if(getY() == 7) return squares;
            if(getX() != 0) squares.push_back(Square(getX()-1, getY()+1));
            if(getX() != 7) squares.push_back(Square(getX()+1, getY()+1));
        }
        else{
            if(getY() == 0) return squares;
            if(getX() != 0) squares.push_back(Square(getX()-1 , getY()-1));
            if(getX() != 7) squares.push_back(Square(getX()+1, getY()-1));
        }
        if(getX() != 0 && board.getPiece(getX()-1, getY()) != nullptr && board.getPiece(getX()-1, getY())->getType() == PieceType::PAWN 
        && (board.getPiece(getX()-1, getY())->isWhite() != isWhite()) && board.getPiece(getX()-1, getY())->getEnPassant()){
          
            if(isWhite()) squares.push_back(Square(getX()-1, getY()+1));
            else squares.push_back(Square(getX()-1, getY()-1));
        }
        if(getX() != 7 && board.getPiece(getX()+1, getY()) != nullptr && board.getPiece(getX()+1, getY())->getType() == PieceType::PAWN 
        && (board.getPiece(getX()+1, getY())->isWhite() != isWhite()) && board.getPiece(getX()+1, getY())->getEnPassant()){
            if(isWhite()) squares.push_back(Square(getX()+1, getY()+1));
            else squares.push_back(Square(getX()+1, getY()-1));
        }
        return squares;
    }

std::vector<Square> Pawn::validMoves(Board &board){
    
    std::vector<Square> squares;
    std::vector<Square> temp;
        temp = attackSquares(board);
        
        for(int i=0;i<temp.size();i++){
            //add en passant logic
            if(temp[i].getX() != getX()){
                if(temp[i].getX() < getX()){
                    if(board.getPiece(getX()-1, getY()) != nullptr && board.getPiece(getX()-1, getY())->getType() == PieceType::PAWN 
                    && (board.getPiece(getX()-1, getY())->isWhite() != isWhite()) && board.getPiece(getX()-1, getY())->getEnPassant()){
                        squares.push_back(temp[i]);
                    }
                }
                else{
                    if(board.getPiece(getX()+1, getY()) != nullptr && board.getPiece(getX()+1, getY())->getType() == PieceType::PAWN 
                    && (board.getPiece(getX()+1, getY())->isWhite() != isWhite()) && board.getPiece(getX()+1, getY())->getEnPassant()){
                        squares.push_back(temp[i]);
                    }
                }
            }
            if(board.getPiece(temp[i].getX(), temp[i].getY())== nullptr || board.getPiece(temp[i].getX(), temp[i].getY())->getInvisible()) continue;
            if(board.getPiece(temp[i].getX(), temp[i].getY())->isWhite() == isWhite()) continue;
            squares.push_back(temp[i]);
        }
        
        if(isWhite()){
            if(getY() != 7 && (board.getPiece(getX(), getY()+1) == nullptr || board.getPiece(getX(), getY()+1)->getInvisible())) squares.push_back(Square(getX(), getY()+1));
            if(getY() == 1 && (board.getPiece(getX(), getY()+2) == nullptr || board.getPiece(getX(), getY()+2)->getInvisible())) squares.push_back(Square(getX(), getY()+2));
        }
        else{
            if(getY() != 0 && (board.getPiece(getX(), getY()-1) == nullptr || board.getPiece(getX(), getY()-1)->getInvisible())) squares.push_back(Square(getX(), getY()-1));
            if(getY() == 6 && (board.getPiece(getX(), getY()-2) == nullptr || board.getPiece(getX(), getY()-2)->getInvisible())) squares.push_back(Square(getX(), getY()-2));
        }
        return squares;
}

bool Pawn::getEnPassant(){
    return enPassant;
}
    void Pawn::setEnPassant(bool enPassant){
        this->enPassant = enPassant;
    }

