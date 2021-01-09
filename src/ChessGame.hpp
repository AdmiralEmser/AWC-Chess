#pragma once

class AWC_ChessGame
{
private:
	short int field[8][8];
	short int player;
public:
	AWC_ChessGame() = default;
	virtual ~AWC_ChessGame() = default;

	// main functions for base game
	void specialCommands(const char **user_input);
	void loadStandardGame();

	// funcs for checking allowed moves
	bool isActualPos();
	bool destinatedPosIsAllowed();
};
