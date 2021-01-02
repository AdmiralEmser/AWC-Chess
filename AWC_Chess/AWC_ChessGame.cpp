#include "AWC_ChessGame.h"
// Due to the fact that this is a console game, including console output:
#include "ConsoleOutput.h"
#include <iostream>


void AWC_ChessGame::MainGame() {
	ConsoleOutput co;
	co.StartScreen();
	AWC_ChessGame::LoadStandardGame();

	co.UpdateField(&field); //GIVES AN ERROR!

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

}