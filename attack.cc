#include "attack.h"
Attack::Attack(){
    whiteAttack = 0;
    blackAttack = 0;
}
    
Attack::Attack(int whiteAttack, int blackAttack){
    this->whiteAttack = whiteAttack;
    this->blackAttack = blackAttack;
}
        void Attack::addWhiteAttack(){
            whiteAttack++;
        }
        void Attack::addBlackAttack(){
            blackAttack++;
        }
        int Attack::getWhiteAttack(){
            return whiteAttack;
        }
        int Attack::getBlackAttack(){
            return blackAttack;
        }
        void Attack::resetAttack(){
            whiteAttack = 0;
            blackAttack = 0;
        }