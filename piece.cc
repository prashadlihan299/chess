#include "piece.h"
#include "board.h"
#include "square.h"
#include<vector>
Piece::Piece(){
    
}
Piece::Piece(bool white, int x, int y){
	this->white = white;
    invisible = false;
	c_x = x;
	c_y = y;
}
void Piece::setWhite(bool white){
	this->white = white;
}

bool Piece::isWhite(){
	return this->white;
}
void Piece::setType(PieceType::Name type){
	this->type = type;
}
PieceType::Name Piece::getType(){
	return type;
}

void Piece::setPos(int x, int y){
	c_x = x;
	c_y = y;
}
int Piece::getX(){
	return c_x;
}
int Piece::getY(){
	return c_y;
}

void Piece::setInvisible(bool invisible){
    this->invisible = invisible;
}
 bool Piece::getInvisible(){
     return invisible;
 }

 bool Piece::canMove(Board &board, Square &end){
	 std::vector<Square> squares = validMoves(board);
	bool can = false;
	for(int i=0;i<squares.size();i++){
		if(squares[i].getX() == end.getX() && squares[i].getY() == end.getY()){
			can = true;
			break;
		}
	}
	return can;
 }
