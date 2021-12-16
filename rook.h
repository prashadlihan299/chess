#ifndef ROOK_HEADER
#define ROOK_HEADER
#include "piece.h"
#include<vector>
class Rook: public Piece{
	bool castlingDone;
public:
	Rook(bool white, int x, int y);
	std::vector<Square> attackSquares(Board &board);
    // std::vector<Square> getBlockSquares(Square square, Board board);
    std::vector<Square> validMoves(Board &board);
	bool getCastlingDone();
	void setCastlingDone(bool castlingDone);
};
#endif