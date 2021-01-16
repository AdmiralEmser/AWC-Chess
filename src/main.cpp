#include "ChessGame.hpp"
#include <iostream>

int main(){
    // defining variables
    AWC_ChessGame cg;
    char *user_input = "none";

    
    // loading standard game
    cg.loadStandardGame();

	// default game loop until player calls EXIT COMMAND
	while (true) {
        cg.graphicsOutput();
        
        /*switch (user_input) {
            case "save":
                cg.save();
                break;
            default:
                // TO DO: OUTPUT MESSAGE: error
        }*/

        cg.resetPossibleMoves();
        // ADD CHECKS FOR MOVES USING IF
	}
    return 0;
}