#include "pch.h"
#include <iostream>
#include <string>
#include "board.h"

game::game()
{
	board = new char*[height];
	for (int i = 0; i < height; i++)
		board[i] = new char[width];

	for (int i = 0; i < height; i++)
		for (int j = 0; j < width; j++)
			board[i][j] = '_';
}

game::~game()
{
	for (int i = 0; i < height; i++)
		delete[] board[i];
	delete[]board;
}

void game::print()
{   
	std::cout << "\n\n";
	std::cout << "   |";
	for (int i = 0; i < height; i++)
		std::cout << i + 1 << "|";
	std::cout << "\n\n";

	for (int i = 0; i < height; i++)
	{ 
		std::cout << i + 1 << "  |";
		for (int j = 0; j < width; j++)
			std::cout << board[i][j] << "|";
		std::cout << "\n";
	}
	std::cout << "\n";
}

void game::addMove(player &obj)
{
	int x, y;
	std::cout << "Select the position where you would like to place an " <<obj.id << ".Please enter the horizontal position first and then the vertical position.\n";
dumbX:	
	std::cout << "Horizontal position : ";
	std::cin >> x;
	if (x < 1 || x>4)
		goto dumbX;
dumbY:
	std::cout << "Vertical position : ";
	std::cin >> y;
	if (y < 1 || y>4)
		goto dumbY;
	
	x--;
	y--;
	
	if(board[x][y] == '_')
		board[x][y] = obj.id;
	else
	{
		std::cout << "Please enter a valid position\n";
		goto dumbX;
	}
}

bool game::checkFour(player &obj)
{
	char check = obj.id;

	for (int i = 0; i < height; i++)
		if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][2] == board[i][3] && board[i][0] == check)
			return true;

	for (int i = 0; i < width; i++)
		if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[2][i] == board[3][i] && board[0][i] == check )
			return true;

	if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[2][2] == board[3][3] && board[0][0]==check)
		return true;

	if (board[0][3] == board[1][2] && board[1][2] == board[2][1] && board[2][1] == board[3][0] && board[0][3]== check)
		return true;

	return false;
}


bool game::fullBoard()
{

	for (int i = 0; i < height; i++)
		for (int j = 0; j < width; j++)
			if (board[i][j] == '_')
				return false;
	return true;
}

int game::restart()
{
	int res;
	std::cout << "\nDo you want to restart the game? [1] YES / NO [2] : ";
	std::cin >> res;
	if (res == 1)
	{
		for (int i = 0; i < height; i++)
			for (int j = 0; j < width; j++)
				board[i][j] = '_';
	}
	else
		std::cout << "\nGood Bye!\n";

	std::cout << "\n";
	return res;
}