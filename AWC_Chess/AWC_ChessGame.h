#pragma once
class AWC_ChessGame
{
	friend class ConsoleOutput;
	friend class MainMoves;
	friend class SpecialMoves;

private:
	short int field[8][8];
	short int possibleMoves[8][8];
public:
	void MainGame();
	void LoadStandardGame();
	void CheckPossibleMoves();
};
