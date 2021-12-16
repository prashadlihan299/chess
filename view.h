#ifndef VIEW_HEADER
#define VIEW_HEADER
#include "board.h"
class View{	
public:
	virtual ~View(){};
	virtual void displayBoard(Board &board)=0;
};
#endif