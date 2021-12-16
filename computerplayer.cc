#include "computerplayer.h"
#include "square.h"
#include "piece.h"
#include<random>
#include<iostream>
#include<vector>
#include<ctime>


std::unique_ptr<Move> ComputerPlayer::move(Board &board, Square &kingPos, bool white){
    Square end;
    Square start;
    std::vector<Move> moves;
    for(int x=0;x<8;x++){
        for(int y=0;y<8;y++){
            Piece *piece = board.getPiece(x, y);
            if(piece != nullptr && piece->isWhite() == white){
                start = board.getBox(x, y);
                
                std::vector<Square> pieceMoves = piece->validMoves(board);
                for(int i=0;i<pieceMoves.size();i++){
                    
                    //check if move puts king in check
                    if(white){
        if(board.isKingCheck(start, pieceMoves[i], kingPos, true)){
            continue;
        }
        
    }
    else{
        if(board.isKingCheck(start, pieceMoves[i], kingPos, false)){
            continue;
        }
    }
                    moves.push_back(Move(board.getBox(x, y), board.getBox(pieceMoves[i].getX(), pieceMoves[i].getY())));
                }
            }
        }
    }
    if(moves.size() == 0){
        return nullptr;
    }
    srand (time(NULL));
    int index = rand() % moves.size();
    return std::make_unique<Move>(moves[index].getStart(), moves[index].getEnd());
   
}
