#include "queen.h"
#include<iostream>
Queen::Queen(bool white, int x, int y): Piece(white, x, y){ 
	setType(PieceType::QUEEN);
}

std::vector<Square> Queen::attackSquares(Board &board){
        std::vector<Square> squares;
        bool xdir = false;
        bool ydir = false;
        int x = getX()+1;
        int y = getY()+1;
        int start = std::min(x, y);
        while(start != 8){
            if(!xdir && x < 8){
                squares.push_back(Square(x, getY()));
                if(board.getPiece(x, getY()) != nullptr && !board.getPiece(x, getY())->getInvisible()) xdir = true;
                x++;
            }
            if(!ydir && y < 8){
                squares.push_back(Square(getX(), y));
                if(board.getPiece(getX(), y) != nullptr && !board.getPiece(getX(), y)->getInvisible()) ydir = true;
                y++;
            }
            start++;
        }

        
        xdir = false;
        ydir = false;
        x = getX()-1;
        y = getY()-1;
        
        start = std::max(x, y);

        while(start >= 0){
            if(!xdir && x>=0){
                squares.push_back(Square(x, getY()));
                if(board.getPiece(x, getY()) != nullptr && !board.getPiece(x, getY())->getInvisible()) xdir = true;
                x--;
            }
            if(!ydir && y>=0){
                squares.push_back(Square(getX(), y));
                if(board.getPiece(getX(), y) != nullptr && !board.getPiece(getX(), y)->getInvisible()) ydir = true;
                y--;
            }
            start--;
        }

		bool up = false;
        bool down = false;
        int y1 = getY()-1;
        int y2= getY()+1;
        for(int i = getX()+1; i<8;i++){
            if(!up && y1 >= 0){
                squares.push_back(Square(i, y1));
                if(board.getPiece(i, y1) != nullptr && !board.getPiece(i, y1)->getInvisible()) up = true;
                // std::cout<<y1<<std::endl;
				y1--;
            }
            if(!down && y2 < 8){
                squares.push_back(Square(i, y2));
                if(board.getPiece(i, y2) != nullptr && !board.getPiece(i, y2)->getInvisible()) down = true;
                
                // if(!down) std::cout<<"still going"<<std::endl;
                // else std::cout<<"stopped: "<<board.getBox(x, y2)->getPiece()->getName()<<std::endl;
                y2++;
            }
        }
        up = false;
        down = false;
        y1 = getY()-1;
        y2 = getY()+1;

        for(int i = getX()-1; i>=0;i--){
            if(!up && y1 >= 0){
                squares.push_back(Square(i, y1));
                if(board.getPiece(i, y1) != nullptr && !board.getPiece(i, y1)->getInvisible()) up = true;
                y1--;
            }
            if(!down && y2 < 8){
                squares.push_back(Square(i, y2));
                if(board.getPiece(i, y2) != nullptr && !board.getPiece(i, y2)->getInvisible()) down = true;
                y2++;
            }
        }
		return squares;
   }

   std::vector<Square> Queen::validMoves(Board &board){
    std::vector<Square> squares;
    std::vector<Square> temp;
        temp = attackSquares( board);
        for(int i=0;i<temp.size();i++){
            Piece *tempPiece = board.getPiece(temp[i].getX(), temp[i].getY());
            if(tempPiece != nullptr && tempPiece->isWhite() == isWhite()) continue;
            squares.push_back(temp[i]);
        }
        return squares;
} 