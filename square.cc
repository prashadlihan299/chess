#include "square.h"
#include "piece.h"
Square::Square(){
}
int Square::getX(){
	return m_x;
}
int Square::getY(){
	return m_y;
}

void Square::addWhiteAttack(){
            attack.addWhiteAttack();
        }
        void Square::addBlackAttack(){
            attack.addBlackAttack();
        }
        int Square::getWhiteAttack(){
            return attack.getWhiteAttack();
        }
        int Square::getBlackAttack(){
            return attack.getBlackAttack();
        }
        void Square::resetAttack(){
            attack.resetAttack();
        }