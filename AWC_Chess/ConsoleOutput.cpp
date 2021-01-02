#include "ConsoleOutput.h"
#include <iostream>

void ConsoleOutput::StartScreen() {
	std::cout << "\n\n	Welcome to AWS's Chess! This is the ALPHA VERSION,\n	so it might not work perfectly fine. However,\n	have fun!\n\n\n";
	system("pause");
}

void ConsoleOutput::UpdateField(short int*field[8][8]) {

}

void ConsoleOutput::UpdatePossibleMoves(short int *possibleMoves[8][8]) {

}
