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

void AWC_ChessGame::resetPossibleMoves(){
	for (short int i = 0; i < 8; i++)
	{
		for (short int j = 0; j < 8; j++)
		{
			possibleMoves[i][j] = false;
		}
	}
}

bool AWC_ChessGame::checkRequestedMoveInField(){
	if (posXtarget >= 0 && posXtarget <= 7 && posYtarget >= 0 && posYtarget <= 7) {
		return true;
	} else {
		return false;
	}
}

bool AWC_ChessGame::checkRequestedMoveNotSamePosition(){
	if (posX == posXtarget && posY == posYtarget){
		return false;
	} else {
		return true;
	}
}

bool AWC_ChessGame::checkRequestedMoveAllowedStandard(){
	// no piece
	if (field[posX][posY] == 0) return false;
	
	// Kings
	if (field[posX][posY] == 1 || field[posX][posY] == 7){
		for (short int i = (posX - 1) ; i <= (posX + 1); i++)
		{
			for (short int j = (posY - 1); j <= (posY + 1); j++)
			{
				if (checkPieceOnFieldPosIsEnemy(&i, &j)) {
					possibleMoves[i][j] = true;
				}
				if (checkPieceOnFieldPosIsEnemy(&i, &j)) {
					possibleMoves[i][j] = true;
				}
			}
		}
	}

	// Queens
	if (field[posX][posY] == 2 || field[posX][posY] == 8){
		// horizontal & vertical
		for (short int i = posX; i < 8; i++)
		{
			if (field[i][posY] == 0){
				possibleMoves[i][posY] = true;
			} else {
				if (checkPieceOnFieldPosIsEnemy(&i, &posY))
				{
					possibleMoves[i][posY] = true;
				}
				break;
			}
		}
		for (short int i = posX; i >= 0; i--)
		{
			if (field[i][posY] == 0){
				possibleMoves[i][posY] = true;
			} else {
				if (checkPieceOnFieldPosIsEnemy(&i, &posY))
				{
					possibleMoves[i][posY] = true;
				}
				break;
			}
		}
		for (short int i = posY; i < 8; i++)
		{
			if (field[posX][i] == 0){
				possibleMoves[posX][i] = true;
			} else {
				if (checkPieceOnFieldPosIsEnemy(&posX, &i))
				{
					possibleMoves[posX][i] = true;
				}
				break;
			}
		}
		for (short int i = posY; i >= 0; i--)
		{
			if (field[posX][i] == 0){
				possibleMoves[posX][i] = true;
			} else {
				if (checkPieceOnFieldPosIsEnemy(&posX, &i))
				{
					possibleMoves[posX][i] = true;
				}
				break;
			}
		}

		// diagonal
		for (short int i = posX; i < 8; i++)
		{
			for (short int j = posY; i < 8; i++){
				if (field[i][j] == 0){
					possibleMoves[i][j] = true;
				} else {
					if (checkPieceOnFieldPosIsEnemy(&i, &j))
					{
						possibleMoves[i][j] = true;
					}
					break;
				}
			}
			break;
		}
		for (short int i = posX; i < 8; i++)
		{
			for (short int j = posY; i >= 0; i--){
				if (field[i][j] == 0){
					possibleMoves[i][j] = true;
				} else {
					if (checkPieceOnFieldPosIsEnemy(&i, &j))
					{
						possibleMoves[i][j] = true;
					}
					break;
				}
			}
			break;
		}
		for (short int i = posX; i >= 0; i++)
		{
			for (short int j = posY; i < 8; i++){
				if (field[i][j] == 0){
					possibleMoves[i][j] = true;
				} else {
					if (checkPieceOnFieldPosIsEnemy(&i, &j))
					{
						possibleMoves[i][j] = true;
					}
					break;
				}
			}
			break;
		}
		for (short int i = posX; i >= 0; i++)
		{
			for (short int j = posY; i >= 0; i++){
				if (field[i][j] == 0){
					possibleMoves[i][j] = true;
				} else {
					if (checkPieceOnFieldPosIsEnemy(&i, &j))
					{
						possibleMoves[i][j] = true;
					}
					break;
				}
			}
			break;
		}
	}

	// Towers
	if (field[posX][posY] == 3 || field[posX][posY] == 9){
		// horizontal & vertical
		for (short int i = posX; i < 8; i++)
		{
			if (field[i][posY] == 0){
				possibleMoves[i][posY] = true;
			} else {
				if (checkPieceOnFieldPosIsEnemy(&i, &posY))
				{
					possibleMoves[i][posY] = true;
				}
				break;
			}
		}
		for (short int i = posX; i >= 0; i--)
		{
			if (field[i][posY] == 0){
				possibleMoves[i][posY] = true;
			} else {
				if (checkPieceOnFieldPosIsEnemy(&i, &posY))
				{
					possibleMoves[i][posY] = true;
				}
				break;
			}
		}
		for (short int i = posY; i < 8; i++)
		{
			if (field[posX][i] == 0){
				possibleMoves[posX][i] = true;
			} else {
				if (checkPieceOnFieldPosIsEnemy(&posX, &i))
				{
					possibleMoves[posX][i] = true;
				}
				break;
			}
		}
		for (short int i = posY; i >= 0; i--)
		{
			if (field[posX][i] == 0){
				possibleMoves[posX][i] = true;
			} else {
				if (checkPieceOnFieldPosIsEnemy(&posX, &i))
				{
					possibleMoves[posX][i] = true;
				}
				break;
			}
		}
	}

	//Bishops
	if (field[posX][posY] == 4 || field[posX][posY] == 10)
	{
		for (short int i = posX; i < 8; i++)
		{
			for (short int j = posY; i < 8; i++){
				if (field[i][j] == 0){
					possibleMoves[i][j] = true;
				} else {
					if (checkPieceOnFieldPosIsEnemy(&i, &j))
					{
						possibleMoves[i][j] = true;
					}
					break;
				}
			}
			break;
		}
		for (short int i = posX; i < 8; i++)
		{
			for (short int j = posY; i >= 0; i--){
				if (field[i][j] == 0){
					possibleMoves[i][j] = true;
				} else {
					if (checkPieceOnFieldPosIsEnemy(&i, &j))
					{
						possibleMoves[i][j] = true;
					}
					break;
				}
			}
			break;
		}
		for (short int i = posX; i >= 0; i++)
		{
			for (short int j = posY; i < 8; i++){
				if (field[i][j] == 0){
					possibleMoves[i][j] = true;
				} else {
					if (checkPieceOnFieldPosIsEnemy(&i, &j))
					{
						possibleMoves[i][j] = true;
					}
					break;
				}
			}
			break;
		}
		for (short int i = posX; i >= 0; i++)
		{
			for (short int j = posY; i >= 0; i++){
				if (field[i][j] == 0){
					possibleMoves[i][j] = true;
				} else {
					if (checkPieceOnFieldPosIsEnemy(&i, &j))
					{
						possibleMoves[i][j] = true;
					}
					break;
				}
			}
			break;
		}
	}

	// Knights
	if (field[posX][posY] == 5 || field[posX][posY] == 11)
	{
		if (posXtarget == posX + 2 && posYtarget == posY - 1){
			if (checkPieceOnFieldPosIsEnemy(&posXtarget, &posYtarget)){
				possibleMoves[posXtarget][posYtarget] = true;
			}
		}
		if (posXtarget == posX + 1 && posYtarget == posY - 2){
			if (checkPieceOnFieldPosIsEnemy(&posXtarget, &posYtarget)){
				possibleMoves[posXtarget][posYtarget] = true;
			}
		}
		if (posXtarget == posX - 2 && posYtarget == posY - 1){
			if (checkPieceOnFieldPosIsEnemy(&posXtarget, &posYtarget)){
				possibleMoves[posXtarget][posYtarget] = true;
			}
		}
		if (posXtarget == posX - 1 && posYtarget == posY - 2){
			if (checkPieceOnFieldPosIsEnemy(&posXtarget, &posYtarget)){
				possibleMoves[posXtarget][posYtarget] = true;
			}
		}
		if (posXtarget == posX + 2 && posYtarget == posY + 1){
			if (checkPieceOnFieldPosIsEnemy(&posXtarget, &posYtarget)){
				possibleMoves[posXtarget][posYtarget] = true;
			}
		}
		if (posXtarget == posX + 1 && posYtarget == posY + 2){
			if (checkPieceOnFieldPosIsEnemy(&posXtarget, &posYtarget)){
				possibleMoves[posXtarget][posYtarget] = true;
			}
		}
		if (posXtarget == posX - 2 && posYtarget == posY + 1){
			if (checkPieceOnFieldPosIsEnemy(&posXtarget, &posYtarget)){
				possibleMoves[posXtarget][posYtarget] = true;
			}
		}
		if (posXtarget == posX - 1 && posYtarget == posY + 2){
			if (checkPieceOnFieldPosIsEnemy(&posXtarget, &posYtarget)){
				possibleMoves[posXtarget][posYtarget] = true;
			}
		}
	}

	// Pawns
	if (field[posX][posY] == 6) // WHITE PAWNS
	{

	}
	if (field[posX][posY] == 12) // BLACK PAWNS
	{

	}

	// check if requested position is allowed
	if (possibleMoves[posXtarget][posYtarget]){
		return true;
	} else {
		return false;
	}
}

bool AWC_ChessGame::checkPieceOnFieldPosIsEnemy(short int* i, short int* j){	
	if (checkPieceOfPlayerX(&posX, &posY) != checkPieceOfPlayerX(&posXtarget, &posYtarget)) {
		return true;
	} else {
		return false;
	}
}

short int AWC_ChessGame::checkPieceOfPlayerX(short int* i, short int* j){
	if (field[*i][*j] == 0){
		return 0;
	} if (field[*i][*j] > 0 && field[*i][*j] < 7)
	{
		return 1;
	} else if (field[*i][*j] > 6 && field[*i][*j] < 13)
	{
		return 2;
	}
}

bool AWC_ChessGame::checkRequestedMoveAllowedSpecial(){

}
