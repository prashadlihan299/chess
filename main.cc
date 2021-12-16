#include<iostream>
#include<string>
#include "gamemaster.h"

using namespace std;
int main(){
    //get users name (blank if computer)
    string name1, name2;
    GameMaster gameMaster;
    cout<<"Enter player 1 name (blank if computer): ";
    getline(cin, name1);
    cout<<"Enter player 2 name (blank if computer): ";
    getline(cin, name2);
    gameMaster.initialize(name1, name2);
    gameMaster.play();
}