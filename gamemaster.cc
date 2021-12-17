#include "gamemaster.h"
#include<iostream>
using namespace std;
void GameMaster::initialize(std::string name1, std::string name2){
    this->name1 = name1;
    this->name2 = name2;
    whiteTurn = true;
    gameState = GameState::PLAYING;
    whiteKingPos = Square(4, 0);
    blackKingPos = Square(4, 7);
    
    // textView.displayBoard(board);
    textView.displayBoard(board);
}

void GameMaster::play(){
    updateKingState();
    observeStateChange();
    while(!cin.eof()){
        bool moved = false;
        
        if(whiteTurn){
            
            //check if human or computer
            if(name1 == ""){
                //get move from computer
                std::unique_ptr<Move> move = compPlayer.move(board, whiteKingPos, true);
                if(move == nullptr){
                    cout<<"Black wins!"<<endl;
            break;
                }
               
                //make move
                moved = makeMove(move->getStart(), move->getEnd());
            }
            else{
                string move1, move2;
                //get move from human
                cin>>move1;
                if(move1 == "O-O" || move1 == "O-O-O"){
                    
                    moved = makeMove(move1, "");
                }
                else{
                    cin>>move2;
                //make move
                moved = makeMove(move1, move2);
                }
            }
        }
        else{
            //check if human or computer
            if(name2 == ""){
                 //get move from computer
                std::unique_ptr<Move> move = compPlayer.move(board, blackKingPos, false);
                if(move == nullptr){
                    cout<<"White wins!"<<endl;
            break;
                }
                //make move
                moved = makeMove(move->getStart(), move->getEnd());
            }
            else{
                string move1, move2;
                //get move from human
                cin>>move1;
                
                if(move1 == "O-O" || move1 == "O-O-O"){
                    
                    moved = makeMove(move1, "");
                }
                else{
                    cin>>move2;
                //make move
                moved = makeMove(move1, move2);
                }
            }
        }

        //change turns if moved
        if(moved) {
            
            textView.displayBoard(board);
            if(observeStateChange()) break;
            whiteTurn = !whiteTurn;
            }

    }
}

bool GameMaster::makeMove(std::string move1, std::string move2){
    //convert string moves to start and end squares
    //pass into general move function
    if(move1 == "O-O"){
        int x = 4;
        int y = 7;
        if(whiteTurn){
            y = 0;
        }
        return makeMove(Square(x, y), Square(x+2, y));
    }
    if(move1 == "O-O-O"){
        int x = 4;
        int y = 7;
        if(whiteTurn){
            y = 0;
        }
        return makeMove(Square(x, y), Square(x-2, y));
    }
    if(move1.length() != 2){
			std::cout<<"Invalid move"<<std::endl;
			return false;
		}
		int x = move1[0]-'a';
        
		if(x>7 || x < 0){
			std::cout<<"Invalid move"<<std::endl;
			return false;
		}
		int y = move1[1] - '1';
		if(y>7 || y < 0){
			std::cout<<"Invalid move"<<std::endl;
			return false;
		}
		Square start = board.getBox(x, y);
        
        
		if(move2.length() != 2){
			std::cout<<"Invalid move"<<std::endl;
			return false;
		}
		x = move2[0]-'a';
		if(x>7 || x < 0){
		 	std::cout<<"Invalid move"<<std::endl;
			return false;
		}
		y = move2[1] - '1';
		if(y>7 || y < 0){
			std::cout<<"Invalid move"<<std::endl;
			return false;
		}
		Square end = board.getBox(x, y);

        return makeMove(start, end);
    
}

bool GameMaster::makeMove(Square start, Square end){
    
    //check if start and end positions of player are the same
    if(start.getX() == end.getX() && start.getY() == end.getY()){
			cout<<"Invalid move"<<endl;
			return false;
	}
    Piece *piece = board.getPiece(start.getX(), start.getY());
    //check if there is no piece on start position
    if(piece == nullptr){
        cout<<"Invalid move"<<endl;
			return false;
    }
    //check if piece matches turn colour
    if(piece->isWhite() != whiteTurn){
        std::cout<<"Invalid move"<<std::endl;
        return false;
    }
    
    //check if start to end is a valid move for the given piece
     if(!piece->canMove(board, end)){
			std::cout<<"Invalid move"<<std::endl;
			std::cout<<"can't move"<<std::endl;
			return false;
		}

        
    
    //check if move puts own king in check
    //if king moved might go into check
    //if piece moved might go into check
    //move without deleting anything, calculate attacks to see if king is in check
    if(whiteTurn){
        if(board.isKingCheck(start, end, whiteKingPos, true)){
            std::cout<<"Invalid move"<<std::endl;
            return false;
        }
        
    }
    else{
        if(board.isKingCheck(start, end, blackKingPos, false)){
            std::cout<<"Invalid move"<<std::endl;
            return false;
        }
    }
    //make move
    board.makeMove(start, end);
    // if(board.getPiece(end.getX(), end.getY())->getType() == PieceType::QUEEN && board.getPiece(end.getX(), end.getY())->isWhite()) std::cout<<"Reached"<<std::endl;
    gameState = GameState::PLAYING;
    //update king pos
            if(whiteTurn && piece->getType() == PieceType::KING){
                whiteKingPos = end;
            }
            else if(!whiteTurn && piece->getType() == PieceType::KING){
                blackKingPos = end;
            }
    //   cout<<board.getBox(blackKingPos.getX(), blackKingPos.getY()).getWhiteAttack()<<endl;      
    //check if other king is in check
    updateKingState();
    
    return true;
}

void GameMaster::setup(){
    string command = "";
    while(!cin.eof()){
        textView.displayBoard(board);
        cout<<"Enter command (quit to exit): "<<endl;
        cin>>command;
        if(command == "quit"){
            break;
        }
        if(command == "reset"){
            board.reset();
            continue;
        }
        if(command.length() != 4){
            cout<<"Invalid command"<<endl;
            continue;
        }
        if(command[0] != '+' && command[0] != '-'){
            cout<<"Invalid command"<<endl;
            continue;
        }
        int x = command[2] - 'a';
        int y = command[3] - '1';
        
        if(x>7 || x < 0){
			std::cout<<"Invalid command"<<std::endl;
			continue;
		}
        if(y>7 || y < 0){
			std::cout<<"Invalid command"<<std::endl;
			continue;
		}
        Square square = Square(x, y);
        if(isupper(command[1])){
            switch(command[1]){
                case 'Q':
                board.addPiece(PieceType::QUEEN, square, true);
                continue;
                break;
                case 'K':
                board.addPiece(PieceType::KING, square, true);
                whiteKingPos = square;
                continue;
                break;
                case 'B':
                board.addPiece(PieceType::BISHOP, square, true);
                continue;
                break;
                case 'N':
                board.addPiece(PieceType::KNIGHT, square, true);
                continue;
                break;
                case 'R':
                board.addPiece(PieceType::ROOK, square, true);
                continue;
                break;
                case 'P':
                board.addPiece(PieceType::PAWN, square, true);
                continue;
                break;
                default:
                cout<<"Invalid choice"<<endl;
                continue;
            }
        }
        else{
            switch(command[1]){
                case 'q':
                board.addPiece(PieceType::QUEEN, square, false);
                continue;
                break;
                case 'k':
                board.addPiece(PieceType::KING, square, false);
                blackKingPos = square;
                continue;
                break;
                case 'b':
                board.addPiece(PieceType::BISHOP, square, false);
                continue;
                break;
                case 'n':
                board.addPiece(PieceType::KNIGHT, square, false);
                continue;
                break;
                case 'r':
                board.addPiece(PieceType::ROOK, square, false);
                continue;
                break;
                case 'p':
                board.addPiece(PieceType::PAWN, square, false);
                continue;
                break;
                default:
                cout<<"Invalid choice"<<endl;
                continue;
            }
        }
        // cout<<"Reached";
        
    }
}

void GameMaster::updateKingState(){
    

        if(board.getBox(blackKingPos.getX(), blackKingPos.getY()).getWhiteAttack() != 0){
            
            gameState = GameState::BLACK_CHECK;
        }
        // std::cout<<board.getBox(whiteKingPos.getX(), whiteKingPos.getY()).getBlackAttack();
        if(board.getBox(whiteKingPos.getX(), whiteKingPos.getY()).getBlackAttack() != 0){
            
            gameState = GameState::WHITE_CHECK;
        }
    
    
    
    //check if checkmate
    if(gameState == GameState::WHITE_CHECK){
        if(!board.canKingMove(whiteKingPos, true)){
            gameState = GameState::BLACK_WINS;
            
        }
    }
    else if(gameState == GameState::BLACK_CHECK){
        if(!board.canKingMove(blackKingPos, false)){
            gameState = GameState::WHITE_WINS;
          
        }
    }
}

bool GameMaster::observeStateChange(){
    if(gameState == GameState::WHITE_CHECK){
                cout<<"White is in check!"<<endl;
            }
            else if(gameState == GameState::BLACK_CHECK){
                cout<<"Black is in check!"<<endl;
            }
            else if(gameState == GameState::WHITE_WINS){
            cout<<"White wins!"<<endl;
            return false;
        }
        else if(gameState == GameState::BLACK_WINS){
            cout<<"Black wins!"<<endl;
            return false;
        }
        return true;
}