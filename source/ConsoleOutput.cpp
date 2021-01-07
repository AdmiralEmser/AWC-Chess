#include "ConsoleOutput.hpp"
#include <iostream>
// including necessary files:
#include "AWC_ChessGame.hpp"

void ConsoleOutput::StartScreen() {
	std::cout << "\n\n	Welcome to AWS's Chess! This is the ALPHA VERSION,\n	so it might not work perfectly fine. However,\n	have fun!\n\n\n";
	system("pause");
}

void ConsoleOutput::UpdateField() {
	AWC_ChessGame cg;
	cg.field;
}

void ConsoleOutput::UpdatePossibleMoves() {

}
