#include "startXO_Game.h"

char locatioArr[10] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9' };

void starXO_Game(){
    int player = 1, i = -1, num =0;

    char mark;
    do
    {
        gameBoard();
        player = (player % 2) ? 1 : 2;

        printf("Player %d turn, Enter a number:  ", player);
        scanf("%d", &num);

        mark = (player == 1) ? 'X' : 'O';

        if (num == 1 && locatioArr[1] == '1')
            locatioArr[1] = mark;

        else if (num == 2 && locatioArr[2] == '2')
            locatioArr[2] = mark;

        else if (num == 3 && locatioArr[3] == '3')
            locatioArr[3] = mark;

        else if (num == 4 && locatioArr[4] == '4')
            locatioArr[4] = mark;

        else if (num == 5 && locatioArr[5] == '5')
            locatioArr[5] = mark;

        else if (num == 6 && locatioArr[6] == '6')
            locatioArr[6] = mark;

        else if (num == 7 && locatioArr[7] == '7')
            locatioArr[7] = mark;

        else if (num == 8 && locatioArr[8] == '8')
            locatioArr[8] = mark;

        else if (num == 9 && locatioArr[9] == '9')
            locatioArr[9] = mark;

        else
        {
            printf("Invalid move ");

            player--;
            getch();
        }
        i = winChecker();

        player++;
    }while (i ==  - 1);

    gameBoard();

    if (i == 1)
        printf("==>\aCongratulation Player %d win ", --player);
    else
        printf("==>\aThere is No winner");

    getch();
}