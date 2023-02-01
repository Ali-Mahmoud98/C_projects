#include<stdio.h>
#include <conio.h>

/*
The library <conio.h> is a header file for the C programming language that provides functions for console input/output on a text-mode display.
The most commonly used function from this library is getch() which reads a single character from the console without echoing it to the screen.

Note that <conio.h> is not a standard C library and is only available on some systems,
particularly older versions of Microsoft Windows.
On most other systems, you need to use alternative methods, such as getchar() or non-blocking I/O with select() or poll(),
to achieve similar functionality.
*/

char locatioArr[10] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9' };

int winChecker();
void gameBoard();

int main()
{
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

    return 0;
}

// check each turn if there is a winner or not
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
