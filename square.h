#ifndef SQUARE_HEADER
#define SQUARE_HEADER
#include<vector>
#include<memory>
#include "attack.h"
class Piece;
class Square{
	int m_x;
	int m_y;
	Attack attack;
	// int whiteAttack;
	// int blackAttack;
	// std::vector<Piece *> whiteAttackPieces;
	// std::vector<Piece *> blackAttackPieces;
public:
	Square();
	Square(int x, int y): m_x(x), m_y(y){
        // whiteAttack=0;blackAttack=0;
        };
	int getX();
	int getY();
	void addWhiteAttack();
    void addBlackAttack();
    int getWhiteAttack();
    int getBlackAttack();
    void resetAttack();
	// void addAttack(bool white);
	// void addAttackPiece(bool white, Piece *piece);
	// std::vector<Piece *> getAttackPieces(bool white);
	// void resetAttack();
	// int getWhiteAttack();
	// int getBlackAttack();
};
#endif