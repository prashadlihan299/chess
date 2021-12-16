#ifndef TEXTVIEW_HEADER
#define TEXTVIEW_HEADER
#include "view.h"
class TextView: public View{
public:
	TextView() {};
	void displayBoard(Board &board);
};
#endif