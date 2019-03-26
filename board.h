#ifndef BOARD_H
#define BOARD_H
#define width 4
#define height 4
#include "player.h"

class game
{
	char **board;

public:

	game();
	~game();

	void print();
	void addMove(player &obj);
	int restart();
	bool fullBoard();
	bool checkFour(player &obj);
};



#endif
