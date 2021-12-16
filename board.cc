#include "board.h"
#include "pawn.h"
#include "queen.h"
#include "king.h"
#include "rook.h"
#include "knight.h"
#include "bishop.h"
#include<iostream>
#include<string>
Board::Board() {
	
	this->resetBoard();
    
}

void Board::resetBoard(){
    enPassantSquare = nullptr;
    //remove pieces from board
    for(int i=0;i<8;i++){
		for(int j=0;j<8;j++){
            pieces[i][j] = nullptr;
        }
	} 
        for(int i=0;i<8;i++){
		for(int j=0;j<8;j++){
            boxes[i][j] = Square(j, i);
        }
	}

    for(int x=0;x<8;x++){
        setPiece(new Pawn(true, x, 1));
        setPiece(new Pawn(false, x, 6));
    }  

    setPiece(new Rook(true, 0, 0));
    setPiece(new Rook(false, 0, 7));
    setPiece(new Rook(true, 7, 0));
    setPiece(new Rook(false, 7, 7));

    setPiece(new Knight(true, 1, 0));
    setPiece(new Knight(false, 1, 7));
    setPiece(new Knight(true, 6, 0));
    setPiece(new Knight(false, 6, 7));

    setPiece(new Bishop(true, 2, 0));
    setPiece(new Bishop(false, 2, 7));
    setPiece(new Bishop(true, 5, 0));
    setPiece(new Bishop(false, 5, 7));

    setPiece(new Queen(true, 3, 0));
    setPiece(new Queen(false, 3, 7));
    
    setPiece(new King(true, 4, 0));
    setPiece(new King(false, 4, 7));

    calculateAttacks();
}

void Board::setPiece(Piece *piece){
        pieces[piece->getX()][piece->getY()].reset(piece); 
}

void Board::resetPiece(int x, int y){
    pieces[x][y].reset();
}

Square Board::getBox(int x, int y){
	return boxes[y][x];
}

Piece *Board::getPiece(int x, int y){
    return pieces[x][y].get();
}

void Board::makeMove(Square start, Square end){
    if(enPassantSquare != nullptr){
        if(pieces[enPassantSquare->getX()][enPassantSquare->getY()] != nullptr)
        pieces[enPassantSquare->getX()][enPassantSquare->getY()]->setEnPassant(false);
    }
    Piece *piece = getPiece(start.getX(), start.getY());
    if(piece != nullptr && piece->getType() == PieceType::PAWN){
        if(abs(start.getY() - end.getY()) == 2){
            
            pieces[start.getX()][start.getY()]->setEnPassant(true);
            enPassantSquare = std::make_unique<Square>(end.getX(), end.getY());
        }
        else if(end.getX() != start.getX() && pieces[end.getX()][end.getY()] == nullptr){
            if(end.getX() < start.getX()) resetPiece(start.getX()-1, start.getY());
            else resetPiece(start.getX()+1, start.getY());
        }
    }
    piece->setPos(end.getX(), end.getY());
    pieces[end.getX()][end.getY()] = pieces[start.getX()][start.getY()];
    resetPiece(start.getX(), start.getY());
    if(piece->getType() == PieceType::KING && abs(start.getX() - end.getX())  == 2){
   
        if(end.getX() > start.getX()) makeMove(Square(7, start.getY()), Square(end.getX()-1, start.getY()));
        else makeMove(Square(0, start.getY()), Square(end.getX()+1, start.getY()));
    }
    if(piece->getType() == PieceType::PAWN){
        if(piece->isWhite() && end.getY() == 7){
            std::cout<<"Which piece do you want to promote to (Queen: q, Knight: n, Bishop: b, Rook: r, default: Queen)"<<std::endl;
            char promotion;
            std::cin>>promotion;
            if(std::tolower(promotion) == 'q'){
                
                resetPiece(end.getX(), end.getY());
                
                setPiece(new Queen(true, end.getX(), end.getY()));
                // std::cout<<"Reached"<<std::endl;
                
            }
            else if(std::tolower(promotion) == 'n'){
                resetPiece(end.getX(), end.getY());
                setPiece(new Knight(true, end.getX(), end.getY()));
            }
            else if(std::tolower(promotion) == 'b'){
                resetPiece(end.getX(), end.getY());
                setPiece(new Bishop(true, end.getX(), end.getY()));
            }
            else if(std::tolower(promotion) == 'r'){
                resetPiece(end.getX(), end.getY());
                setPiece(new Rook(true, end.getX(), end.getY()));
            }
            else{
                
                resetPiece(end.getX(), end.getY());
                setPiece(new Queen(true, end.getX(), end.getY()));
            
            }
            piece = getPiece(end.getX(), end.getY());
        }
        else if(!piece->isWhite() && end.getY() == 0){
            std::cout<<"Which piece do you want to promote to (Queen: q, Knight: n, Bishop: b, Rook: r, default: Queen)"<<std::endl;
            char promotion;
            std::cin>>promotion;
            if(std::tolower(promotion) == 'q'){
                resetPiece(end.getX(), end.getY());
                setPiece(new Queen(false, end.getX(), end.getY()));
                
            }
            else if(std::tolower(promotion) == 'n'){
                resetPiece(end.getX(), end.getY());
                setPiece(new Knight(false, end.getX(), end.getY()));
            }
            else if(std::tolower(promotion) == 'b'){
                resetPiece(end.getX(), end.getY());
                setPiece(new Bishop(false, end.getX(), end.getY()));
            }
            else if(std::tolower(promotion) == 'r'){
                resetPiece(end.getX(), end.getY());
                setPiece(new Rook(false, end.getX(), end.getY()));
            }
            else{
                
                resetPiece(end.getX(), end.getY());
                setPiece(new Queen(false, end.getX(), end.getY()));
            
            }
            piece = getPiece(end.getX(), end.getY());
        }
    }

    calculateAttacks();
    
    if(piece != nullptr && (piece->getType() == PieceType::KING || piece->getType() == PieceType::ROOK)) piece->setCastlingDone(true);
}

void Board::calculateAttacks(){
    for(int x=0;x<8;x++){
        for(int y=0;y<8;y++){
            boxes[x][y].resetAttack();
        }
    }
    for(int x=0;x<8;x++){
        for(int y=0;y<8;y++){
            
            Piece *piece = getPiece(x, y);
            if(piece == nullptr) continue;
            std::vector<Square> squares = piece->attackSquares(*this);
            for(int i=0;i<squares.size();i++){
                if(piece->isWhite()){
                     boxes[squares[i].getY()][squares[i].getX()].addWhiteAttack();
                }
                else{
                     boxes[squares[i].getY()][squares[i].getX()].addBlackAttack();
                }
            }
        }
    }
}

bool Board::isKingCheck(Square start, Square end, Square kingPos, bool white){
    bool check = false;
    bool endNull = pieces[end.getX()][end.getY()] == nullptr;
    if(getPiece(start.getX(), start.getY())->getType() == PieceType::KING){
        kingPos = end;
    }
    //swap end and start pointers
    pieces[start.getX()][start.getY()].swap(pieces[end.getX()][end.getY()]);
    
    //set start piece invisible
    if(!endNull) pieces[start.getX()][start.getY()]->setInvisible(true);
    //calculate attacks
    
    calculateAttacks();
    
    //check if king is in check
    if(white){
        if(getBox(kingPos.getX(),kingPos.getY()).getBlackAttack() != 0) check = true;
    }
    else{
        if(getBox(kingPos.getX(),kingPos.getY()).getWhiteAttack() != 0) check = true;
    }
    
    //swap start and end pointers
    pieces[start.getX()][start.getY()].swap(pieces[end.getX()][end.getY()]);
    //make end piece visible
    if(!endNull) pieces[end.getX()][end.getY()]->setInvisible(false);
    return check;
}

bool Board::canKingMove(Square kingPos, bool white){
    
    bool canMove = false;
    for(int x=0;x<8;x++){
        for(int y=0;y<8;y++){
            
            Piece *piece = getPiece(x, y);
            Square start = Square(x, y);
            if(piece != nullptr && piece->isWhite() == white){
                   
                
            
                std::vector<Square> moves = piece->validMoves(*this);
             
                // std::cout<<moves.size()<<std::endl;
                for(int i=0;i<moves.size();i++){
                    
                    if(!isKingCheck(start, moves[i], kingPos, white)){
                        // std::cout<<start.getX()<<", "<<start.getY()<<", "<<moves[i].getX()<<", "<<moves[i].getY()<<", "<<std::endl;
                        canMove = true;
                        break;
                    }
                    
                }
                if(canMove) break;
            }
        }
        if(canMove) break;
    }
    
    return canMove;
}