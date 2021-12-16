#ifndef QUEEN_HEADER
#define QUEEN_HEADER
#include "piece.h"
#include<vector>
class Queen: public Piece{
public:
	Queen(bool white, int x, int y);
	std::vector<Square> attackSquares(Board &board);
    // std::vector<Square> getBlockSquares(Square square, Board board);
    std::vector<Square> validMoves(Board &board);
};
#endif