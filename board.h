#ifndef BOARD_HEADER
#define BOARD_HEADER
#include "square.h"
#include "piece.h"
#include "piecetype.h"
#include<vector>
#include<memory>
class Board{
	Square boxes[8][8];
    std::shared_ptr<Piece> pieces[8][8];
	std::unique_ptr<Square> enPassantSquare;
	// bool alreadyInitialized;

public:
	Board();
	Square getBox(int x, int y);
    Piece *getPiece(int x, int y);
    void setPiece(Piece *piece);
	void makeMove(Square start, Square end);
	// Square getBoxTemp(int x, int y);
	// Piece *movePiece(int row1, int col1, int row2, int col2, bool del);
	void resetBoard();
	void resetPiece(int x, int y);
	bool isKingCheck(Square start, Square end, Square kingPos, bool white);
	bool canKingMove(Square kingPos, bool white);
	void reset();
	void addPiece(PieceType::Name type, Square &square, bool white);
	// bool canBlock(std::vector<std::vector<Square> > blockSquares, bool white);
private:
	void calculateAttacks();
};
#endif