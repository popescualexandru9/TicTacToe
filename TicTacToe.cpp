#include "pch.h"
#include <iostream>
#include <string>
#include "board.h"

int main()
{
	std::string playerOneName, playerTwoName;
	char playerOneSymbol,playerTwoSymbol;

	std::cout << "Player One ,what is your name?\nAnswear : ";
	std::cin >> playerOneName;
dumb:
	std::cout << "Player One, what symbol would you like to use? Please input [X] or [O]\nAnswear : ";
	std::cin >> playerOneSymbol;
	if (playerOneSymbol != 'X' && playerOneSymbol != 'O')
		goto dumb;

	std::cout << "\nPlayer Two ,what is your name?\nAnswear : ";
	std::cin >> playerTwoName;
	(playerOneSymbol == 'X') ? playerTwoSymbol = 'O' : playerTwoSymbol = 'X';

	player playerOne(playerOneName, playerOneSymbol);
	player playerTwo(playerTwoName, playerTwoSymbol);
	game play;

	do
	{
		play.print();
		play.addMove(playerOne);
		if (play.checkFour(playerOne))
		{
			play.print();
			playerOne.winner();
			if (play.restart() == 2)
				break;
		}

		play.print();
		play.addMove(playerTwo);
		if (play.checkFour(playerTwo))
		{
			play.print();
			playerTwo.winner();
			if (play.restart() == 2)
				break;
		}

		if (play.fullBoard())
		{
			play.print();
			std::cout << "\nGame over! It is a tie.\n\n";
			if (play.restart() == 2)
				break;
		}


	} while (1);



	return 0;
}