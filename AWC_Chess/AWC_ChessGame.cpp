#include "AWC_ChessGame.h"
#include <iostream>
// including necessary files:
#include "ConsoleOutput.h"
#include "MainMoves.h"
#include "SpecialMoves.h"

void AWC_ChessGame::MainGame() {
	ConsoleOutput co;
	co.StartScreen();
	AWC_ChessGame::LoadStandardGame();

	// default game loop until player calls EXIT COMMAND
	while (true) {

	}
}

void AWC_ChessGame::LoadStandardGame() {
	// resetting possible moves array
	for (short int i = 0; i < 8; i++){
		for (short int j = 0; j < 8; j++) {
			possibleMoves[i][j] = 0;
		}
	}

	/* recreating standard positions of the pieces on the field;
	* for further information about numbers: Check documentation */
	// resetting 1
	field[0][0] = 2;
	field[0][1] = 3;
	field[0][2] = 4;
	field[0][3] = 5;
	field[0][4] = 6;
	field[0][5] = 4;
	field[0][6] = 3;
	field[0][7] = 2;

	// resetting 8
	field[7][0] = 2;
	field[7][1] = 3;
	field[7][2] = 4;
	field[7][3] = 5;
	field[7][4] = 6;
	field[7][5] = 4;
	field[7][6] = 3;
	field[7][7] = 2;

	// resetting 2
	for (short int i = 0; i < 8; i++)
	{
		field[1][i] = 1;
	}
	
	// resetting 7
	for (short int i = 0; i < 8; i++)
	{
		field[6][i] = 1;
	}

	// resetting 3-6
	for (short int i = 2; i < 6; i++)
	{
		for (short int j = 0; j < 8; j++)
		{
			field[i][j] = 0;
		}
	}
}
