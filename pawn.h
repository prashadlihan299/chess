#ifndef PAWN_HEADER
#define PAWN_HEADER
#include "piece.h"
#include<vector>
class Pawn: public Piece{
    bool enPassant;
public:
	Pawn(bool white, int x, int y);
	// bool canMove(Board &board, Square &end);
    std::vector<Square> attackSquares(Board &board);
    // std::vector<Square> getBlockSquares(Square square, Board board);
    std::vector<Square> validMoves(Board &board);
    bool getEnPassant();
    void setEnPassant(bool enPassant);
};
#endif