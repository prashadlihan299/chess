#include "knight.h"

Knight::Knight(bool white, int x, int y): Piece(white, x, y){
	setType(PieceType::KNIGHT);
}

std::vector<Square> Knight::attackSquares(Board &board){
    std::vector<Square> squares;
    int x1 = std::max(getX()-2, 0);
    int y1 = std::max(getY()-2, 0);
    int x2 = std::min(getX() + 2, 7);
    int y2 = std::min(getY() + 2, 7);
    for(int x=x1;x<=x2;x++){
        for(int y=y1; y<=y2;y++){
            int ax = std::abs(x - getX());
            int ay = std::abs(y - getY());
            if(ax*ay==2){
                squares.push_back(Square(x, y));
            }
        }
    }
    return squares;
}



    std::vector<Square> Knight::validMoves(Board &board){
    std::vector<Square> squares;
    std::vector<Square> temp;
        temp = attackSquares(board);
        for(int i=0;i<temp.size();i++){
            Piece *tempPiece = board.getPiece(temp[i].getX(), temp[i].getY());
            if(tempPiece != nullptr && tempPiece->isWhite() == isWhite()) continue;
            squares.push_back(temp[i]);
        }
        return squares;
}