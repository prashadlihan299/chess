#ifndef GAMEMASTER_HEADER
#define GAMEMASTER_HEADER
#include<string>

#include "gamestate.h"
#include "textview.h"
#include "computerplayer.h"


class GameMaster{
    std::string name1, name2;
    bool whiteTurn;
    GameState::State gameState;
    Square whiteKingPos;
    Square blackKingPos;
    
    Board board;
    TextView textView;
    ComputerPlayer compPlayer;
    public:
        void initialize(std::string name1, std::string name2);
        void play();
        bool makeMove(std::string move1, std::string move2);
        bool makeMove(Square start, Square end);
        
};
#endif