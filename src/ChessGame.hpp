#pragma once

class AWC_ChessGame
{
private:
	short int field[8][8];
	bool possibleMoves[8][8];
	short int player;
	short int posX, posY, posXtarget, posYtarget;
public:
	AWC_ChessGame() = default;
	virtual ~AWC_ChessGame() = default;

	// main functions for base game
	void specialCommands(const char **user_input);
	void loadStandardGame();

	// funcs for checking allowed moves
	bool isActualPos();
	bool destinatedPosIsAllowed();
	void graphicsOutput();

	// check if targeted move is allowed
	void resetPossibleMoves();
	bool checkRequestedMoveInField();
	bool checkRequestedMoveNotSamePosition();
	bool checkRequestedMoveAllowedStandard();
	bool checkRequestedMoveAllowedSpecial();
	bool checkPieceOnFieldPosIsEnemy(short int* i, short int* j);

	// piece & player checkups
	short int checkPieceOfPlayerX(short int* i, short int* j);
};
