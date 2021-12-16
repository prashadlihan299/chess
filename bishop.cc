#include "bishop.h"
#include<iostream>
Bishop::Bishop(bool white, int x, int y): Piece(white, x, y){
	setType(PieceType::BISHOP);
}

std::vector<Square> Bishop::attackSquares(Board &board){
        std::vector<Square> squares;
        bool up = false;
        bool down = false;
        int y1 = getY()-1;
        int y2=getY()+1;
        for(int x = getX()+1; x<8;x++){
            if(!up && y1 >= 0){
                squares.push_back(Square(x, y1));
                if(board.getPiece(x, y1) != nullptr && !board.getPiece(x, y1)->getInvisible()) up = true;
                y1--;
            }
            if(!down && y2 < 8){
                squares.push_back(Square(x, y2));
                if(board.getPiece(x, y2) != nullptr && !board.getPiece(x, y2)->getInvisible()) down = true;
                y2++;
            }
        }
        up = false;
        down = false;
        y1 = getY()-1;
        y2 = getY()+1;

        for(int x = getX()-1; x>=0;x--){
            if(!up && y1 >= 0){
                squares.push_back(Square(x, y1));
                if(board.getPiece(x, y1) != nullptr && !board.getPiece(x, y1)->getInvisible()) up = true;
                y1--;
            }
            if(!down && y2 < 8){
                squares.push_back(Square(x, y2));
                if(board.getPiece(x, y2) != nullptr && !board.getPiece(x, y2)->getInvisible()) down = true;
                y2++;
            }
        }
        return squares;
    }

	std::vector<Square> Bishop::validMoves(Board &board){
    std::vector<Square> squares;
    std::vector<Square> temp;
        temp = attackSquares(board);
        for(int i=0;i<temp.size();i++){
            Piece *tempPiece = board.getPiece(temp[i].getX(), temp[i].getY());
            if(tempPiece != nullptr && tempPiece->isWhite() == isWhite()) continue;
            squares.push_back(temp[i]);
        }
        return squares;
}

