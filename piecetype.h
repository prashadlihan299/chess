#ifndef PIECETYPE_HEADER
#define PIECETYPE_HEADER
class PieceType{
    public:
        enum Name{
    QUEEN,
    ROOK,
    BISHOP,
    KNIGHT,
    KING,
    PAWN
};
virtual ~PieceType() = 0;
};
#endif