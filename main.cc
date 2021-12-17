#include<iostream>
#include<string>
#include "gamemaster.h"

using namespace std;
int main(){
    //get users name (blank if computer)
    string name1, name2;
    GameMaster gameMaster;
    std::cout<<"Enter player 1 name (blank if computer): ";
    std::getline(cin, name1);
    std::cout<<"Enter player 2 name (blank if computer): ";
    std::getline(cin, name2);
    gameMaster.initialize(name1, name2);
    bool play = false;
    while(!cin.eof() && !play){
        string mode;
        std::cout<<"Choose mode (play, setup): "<<endl;
        cin>>mode;
        if(mode == "play"){
             play = true;
            break;
        }
        else if(mode == "setup"){
            gameMaster.setup();
        }
        else{
            std::cout<<"Invalid mode"<<std::endl;
        }
    }
    
    gameMaster.play();
}