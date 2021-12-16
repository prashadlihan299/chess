#ifndef PIECE_HEADER
#define PIECE_HEADER
#include "board.h"
#include "square.h"
#include "piecetype.h"
#include<string>
#include<vector>
class Board;
class Piece{
	bool white;
    bool invisible;
	PieceType::Name type;
	int c_x, c_y;

public:
    Piece();
	Piece(bool white, int x, int y);
	virtual ~Piece(){};
	void setWhite(bool white);
	bool isWhite();
	void setPos(int x, int y);
	int getX();
	int getY();
	PieceType::Name getType();
	void setType(PieceType::Name type);
    void setInvisible(bool invisible);
    bool getInvisible();
	bool canMove(Board &board, Square &end);
	virtual std::vector<Square> attackSquares(Board &board)=0;
	virtual std::vector<Square> validMoves(Board &board)=0;
	virtual bool getCastlingDone(){
		 return true;
 };
 virtual void setCastlingDone(bool castlingDone){};
 virtual bool getEnPassant(){
		 return false;
 };
 virtual void setEnPassant(bool enPassant){};
	// virtual std::vector<Square> getBlockSquares(Square square, Board board)=0;
};
#endif