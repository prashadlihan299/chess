#include "rook.h"

Rook::Rook(bool white, int x, int y): Piece(white, x, y){
	castlingDone = false; 
	setType(PieceType::ROOK);
}

std::vector<Square> Rook::attackSquares(Board &board){
        std::vector<Square> squares;
        bool xdir = false;
        bool ydir = false;
        int x = getX()+1;
        int y = getY()+1;
        int start = std::min(x, y);
        while(start != 8){
            if(!xdir && x < 8){
                squares.push_back(Square(x, getY()));
                if(board.getPiece(x, getY()) != nullptr && !board.getPiece(x, getY())->getInvisible()) xdir = true;
                x++;
            }
            if(!ydir && y < 8){
                squares.push_back(Square(getX(), y));
                if(board.getPiece(getX(), y) != nullptr && !board.getPiece(getX(), y)->getInvisible()) ydir = true;
                y++;
            }
            start++;
        }

        
        xdir = false;
        ydir = false;
        x = getX()-1;
        y = getY()-1;
        
        start = std::max(x, y);

        while(start >= 0){
            if(!xdir && x>=0){
                squares.push_back(Square(x, getY()));
                if(board.getPiece(x, getY()) != nullptr && !board.getPiece(x, getY())->getInvisible()) xdir = true;
                x--;
            }
            if(!ydir && y>=0){
                squares.push_back(Square(getX(), y));
                if(board.getPiece(getX(), y) != nullptr && !board.getPiece(getX(), y)->getInvisible()) ydir = true;
                y--;
            }
            start--;
        }
        return squares;
    }

	std::vector<Square> Rook::validMoves(Board &board){
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

bool Rook::getCastlingDone(){
    return castlingDone;
}

void Rook::setCastlingDone(bool castlingDone){
    this->castlingDone = castlingDone;
}
