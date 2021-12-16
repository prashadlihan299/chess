#ifndef MOVE_HEADER
#define MOVE_HEADER
#include "square.h"
class Move{
    Square start;
    Square end;
    public:
        Move(Square s1, Square s2);
        Square getStart();
        Square getEnd();
};
#endif