#include "king.h"

King::King(bool white, int x, int y): Piece(white, x, y){
	castlingDone = false; 
	setType(PieceType::KING);
}

  std::vector<Square> King::attackSquares(Board &board){
        std::vector<Square> squares;
        int x1 = std::max(getX()-1, 0);
        int y1 = std::max(getY()-1, 0);
        int x2 = std::min(getX() + 1, 7);
        int y2 = std::min(getY() + 1, 7);
        for(int x=x1;x<=x2;x++){
        for(int y=y1; y<=y2;y++){
            int ax = std::abs(x - getX());
            int ay = std::abs(y - getY());
            if(ax+ay==1){
                squares.push_back(Square(x, y));
            }
        }
    }
    return squares;
    }

    std::vector<Square> King::validMoves(Board &board){
    std::vector<Square> squares;
    std::vector<Square> temp;
        temp = attackSquares(board);
        for(int i=0;i<temp.size();i++){
            Piece *tempPiece = board.getPiece(temp[i].getX(), temp[i].getY());
            if(tempPiece != nullptr && tempPiece->isWhite() == isWhite()) continue;
            squares.push_back(temp[i]);
        }
        return castlingMoves(squares, board);
}

std::vector<Square> King::castlingMoves(std::vector<Square> &squares, Board &board){
    //make castlingDone true when piece is moved
    if(castlingDone) return squares;
    if(board.getPiece(7, getY()) == nullptr || board.getPiece(7, getY())->getType() != PieceType::ROOK || board.getPiece(7, getY())->getCastlingDone()) return squares;
    for(int x=getX();x<6;x++){
        if(x-getX() <= 2){
            if((isWhite() && board.getBox(x, getY()).getBlackAttack() != 0) || (!isWhite() && board.getBox(x, getY()).getWhiteAttack() != 0)) return squares;
        }
        if(x!= getX() && board.getPiece(x, getY()) != nullptr) return squares;
    }
    squares.push_back(Square(getX() + 2, getY()));

    if(board.getPiece(0, getY()) == nullptr || board.getPiece(0, getY())->getType() != PieceType::ROOK || board.getPiece(0, getY())->getCastlingDone()) return squares;
    for(int x=getX();x>=1;x--){
        if(getX() - x <= 2){
            if((isWhite() && board.getBox(x, getY()).getBlackAttack() != 0) || (!isWhite() && board.getBox(x, getY()).getWhiteAttack() != 0)) return squares;
        }
        if(x!= getX() && board.getPiece(x, getY()) != nullptr) return squares;
    }

    squares.push_back(Square(getX() - 2, getY()));
    return squares;
}

bool King::getCastlingDone(){
    return castlingDone;
}

void King::setCastlingDone(bool castlingDone){
    this->castlingDone = castlingDone;
}