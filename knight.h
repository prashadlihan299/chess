#ifndef KNIGHT_HEADER
#define KNIGHT_HEADER
#include "piece.h"
#include<vector>
class Knight: public Piece{
public:
	Knight(bool white, int x, int y);
	std::vector<Square> attackSquares(Board &board);
    // std::vector<Square> getBlockSquares(Square square, Board board);
    std::vector<Square> validMoves(Board &board);
};
#endif