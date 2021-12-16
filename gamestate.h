#ifndef GAMESTATE_HEADER
#define GAMESTATE_HEADER
class GameState{
    public:
        enum State{
    PLAYING,
    WHITE_CHECK,
    BLACK_CHECK,
    WHITE_WINS,
    BLACK_WINS
};
virtual ~GameState() = 0;
};
#endif