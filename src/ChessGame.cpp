#include "ChessGame.hpp"
#include <iostream>
// #include <string>
// include piece macros
#include "pieces.hpp"
#include "players.hpp"

void AWC_ChessGame::specialCommands(const char **user_input){
	if (*user_input == "save"){
		// ADD SAVE
	}
}

void AWC_ChessGame::loadStandardGame() {
	/* recreating standard positions of the pieces on the field;
	* for further information about numbers: Check documentation */
	// resetting 1 (WHITE)
	field[0][0] = WhiteTower;
	field[0][1] = WhiteKnight;
	field[0][2] = WhiteBishop;
	field[0][3] = WhiteKing;
	field[0][4] = WhiteQueen;
	field[0][5] = WhiteBishop;
	field[0][6] = WhiteKnight;
	field[0][7] = WhiteTower;

	// resetting 2 (WHITE)
	for (short int i = 0; i < 8; i++)
	{
		field[1][i] = WhitePawn;
	}

	// resetting (BLACK)
	field[7][0] = BlackTower;
	field[7][1] = BlackKnight;
	field[7][2] = BlackBishop;
	field[7][3] = BlackQueen;
	field[7][4] = BlackKing;
	field[7][5] = BlackBishop;
	field[7][6] = BlackKnight;
	field[7][7] = BlackTower;
	
	// resetting 7 (BLACK)
	for (short int i = 0; i < 8; i++)
	{
		field[6][i] = BlackPawn;
	}

	// resetting 3-6
	for (short int i = 2; i < 6; i++)
	{
		for (short int j = 0; j < 8; j++)
		{
			field[i][j] = clear_location;
		}
	}
}

void AWC_ChessGame::graphicsOutput() {

	// TO DO

}
