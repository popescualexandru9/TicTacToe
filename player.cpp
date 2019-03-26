#include "pch.h"
#include <iostream>
#include <string>
#include "player.h"

player::player()
{
	name = "Unknown";
	id = '*';
}

player::player(std::string nameIn, char ID)
{
	name = nameIn;
	id = ID;
}

void player::winner()
{
	std::cout << "\n\n";
	std::cout << "Congratulations , player " << name << "[" << id << "]" << " has won!";
	std::cout << "\n\n";
}