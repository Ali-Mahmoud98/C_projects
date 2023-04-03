#include "X_O_Game.h"

// check each turn if there is a winner or not
extern char locatioArr[10];

int winChecker()
{
    if (locatioArr[1] == locatioArr[2] && locatioArr[2] == locatioArr[3])
        return 1;

    else if (locatioArr[4] == locatioArr[5] && locatioArr[5] == locatioArr[6])
        return 1;

    else if (locatioArr[7] == locatioArr[8] && locatioArr[8] == locatioArr[9])
        return 1;

    else if (locatioArr[1] == locatioArr[4] && locatioArr[4] == locatioArr[7])
        return 1;

    else if (locatioArr[2] == locatioArr[5] && locatioArr[5] == locatioArr[8])
        return 1;

    else if (locatioArr[3] == locatioArr[6] && locatioArr[6] == locatioArr[9])
        return 1;

    else if (locatioArr[1] == locatioArr[5] && locatioArr[5] == locatioArr[9])
        return 1;

    else if (locatioArr[3] == locatioArr[5] && locatioArr[5] == locatioArr[7])
        return 1;

    else if (locatioArr[1] != '1' && locatioArr[2] != '2' && locatioArr[3] != '3' &&
        locatioArr[4] != '4' && locatioArr[5] != '5' && locatioArr[6] != '6' && locatioArr[7]
        != '7' && locatioArr[8] != '8' && locatioArr[9] != '9'){
            return 0;
        }

    else
        return  - 1;
}
// draw the game board
void gameBoard()
{
    system("cls");
    printf("\n\n\tTic Tac Toe Game\n");
    printf("\t****************\n\n");

    printf("*************************************\n");
    printf("Player 1 (X)  -  Player 2 (O)\n");
    printf("*************************************\n\n\n");

    
    printf("     |     |     \n");
    printf("  %c  |  %c  |  %c \n", locatioArr[1], locatioArr[2], locatioArr[3]);

    printf("_____|_____|_____\n");
    printf("     |     |     \n");

    printf("  %c  |  %c  |  %c \n", locatioArr[4], locatioArr[5], locatioArr[6]);

    printf("_____|_____|_____\n");
    printf("     |     |     \n");

    printf("  %c  |  %c  |  %c \n", locatioArr[7], locatioArr[8], locatioArr[9]);

    printf("     |     |     \n\n");
}
