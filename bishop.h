#ifndef BISHOP_HEADER
#define BISHOP_HEADER
#include "piece.h"
#include<vector>
class Bishop: public Piece{
public:
	Bishop(bool white, int x, int y);
	std::vector<Square> attackSquares(Board &board);
    // std::vector<Square> getBlockSquares(Square square, Board board);
    std::vector<Square> validMoves(Board &board);
};
#endif