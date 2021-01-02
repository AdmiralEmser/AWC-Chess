#pragma once
class AWC_ChessGame
{
private:
public:
	short int field[8][8];
	short int possibleMoves[8][8];
//public:
	void MainGame();
	void LoadStandardGame();
	void CheckPossibleMoves();
};

