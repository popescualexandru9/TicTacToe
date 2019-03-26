#ifndef PLAYER_H
#define PLAYER_H
#include <string>

class player
{
	friend class game;
	std::string name;
	char id;

public:
	player();
	player(std::string nameIn, char ID);

	void winner();
	char getId() { return id; }
	std::string getName() { return name; }
};

#endif
