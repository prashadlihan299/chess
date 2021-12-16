#include "move.h"
Move::Move(Square s1, Square s2){
    start = s1;
    end = s2;
}

Square Move::getStart(){
    return start;
}
Square Move::getEnd(){
    return end;
}