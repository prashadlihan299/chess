#ifndef KING_HEADER
#define KING_HEADER
#include "piece.h"
#include<vector>
class King: public Piece{
	bool castlingDone;
public:
	King(bool white, int x, int y);
	std::vector<Square> attackSquares(Board &board);
    // std::vector<Square> getBlockSquares(Square square, Board board);
    std::vector<Square> validMoves(Board &board);
	std::vector<Square> castlingMoves(std::vector<Square> &squares, Board &board);
	bool getCastlingDone();
	void setCastlingDone(bool castlingDone);
};
#endif