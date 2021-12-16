#include "textview.h"
#include "board.h"
#include<iostream>
#include "piece.h"
void TextView::displayBoard(Board &board){
	// if(board.getPiece(3, 7)->getType() == PieceType::QUEEN && board.getPiece(3, 7)->isWhite()) std::cout<<"Reached"<<std::endl;
    std::cout<<std::endl;
	//iterate through the squares on a chess board
	for(int y=7;y>=0;y--){
		std::cout<<(y+1)<<" ";
		for(int x=0;x<8;x++){
            Piece *piece = board.getPiece(x, y);
            if(x == 3 && y == 7){
				// if(board.getPiece(x, y)->getType() == PieceType::QUEEN && board.getPiece(x, y)->isWhite()) std::cout<<piece->getInvisible()<<std::endl;
			}
	// 		Piece *tempPiece = board.getBox(j, i).getPiece();
			if(piece != nullptr && !piece->getInvisible()){
				if(piece->getType() == PieceType::KING){
					if(piece->isWhite()) std::cout<<"K";
					else std::cout<<"k";
				}
				else if(piece->getType() == PieceType::QUEEN){
					if(piece->isWhite()) std::cout<<"Q";
					else std::cout<<"q";
				}
				else if(piece->getType() == PieceType::ROOK){
					if(piece->isWhite()) std::cout<<"R";
					else std::cout<<"r";
				}
				else if(piece->getType() == PieceType::BISHOP){
					if(piece->isWhite()) std::cout<<"B";
					else std::cout<<"b";
				}
				else if(piece->getType() == PieceType::KNIGHT){
					if(piece->isWhite()) std::cout<<"N";
					else std::cout<<"n";
				}
				else if(piece->getType() == PieceType::PAWN){
					if(piece->isWhite()) std::cout<<"P";
					else std::cout<<"p";
				}
			}
			else{
			// 	if(board.getBox(x, y).getWhiteAttack() != 0){
			// 	std::cout<<board.getBox(x, y).getWhiteAttack();
			// 	continue;
			// }
                //logic for black and white squares
			if(x%2!=0 && y%2==0 || x%2 == 0 && y%2 != 0)std::cout<<" ";
			else std::cout<<"_";
			
	// 		
		}
		}
		std::cout<<std::endl;
	}
	std::cout<<std::endl<<"  ";
	for(char i='a';i<='h';i++){
		std::cout<<i;
	}
	std::cout<<std::endl;
}