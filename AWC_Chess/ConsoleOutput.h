#pragma once
class ConsoleOutput
{
public:
	void StartScreen();
	void UpdateField(short int *field[8][8]);
	void UpdatePossibleMoves(short int *possibleMoves[8][8]);
};

