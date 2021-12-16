#ifndef ATTACK_HEADER
#define ATTACK_HEADER
class Attack{
    int whiteAttack;
    int blackAttack;
    public:
        Attack();
        Attack(int whiteAttack, int blackAttack);
        void addWhiteAttack();
        void addBlackAttack();
        int getWhiteAttack();
        int getBlackAttack();
        void resetAttack();
};
#endif