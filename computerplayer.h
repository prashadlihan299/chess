#ifndef COMPUTERPLAYER_HEADER
#define COMPUTERPLAYER_HEADER
#include "move.h"
#include "board.h"
#include<memory>
class ComputerPlayer{

    public:
        std::unique_ptr<Move> move(Board &board, Square &kingPos, bool white);
};
#endif