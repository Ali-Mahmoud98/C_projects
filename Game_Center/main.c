#include "./LadderAndSnake/start_Ladder_And_Snake_Game.h"
#include "./TicTacTeoGame/startXO_Game.h"

void main(){

    char option;

    do
    {
        system("cls");
        printf("--------------------------------\n");
        printf("\t\t=>Welcom from our gaming center ^_^\n");
        printf("\t\t\t--------------------------------\n\n");
        printf("\t1-> Play ladder and Snake game.\n");
        printf("\t2-> Play Tic Tac Teo game.\n");
        printf("\t3-> Exit.\n");
        printf("\n--------------------------------\n");
        printf("\t=> Enter you option :");
        scanf("%d", &option);

        switch (option)
        {
        case 1:
            system("cls");
            printf("--------------------------------\n");
            printf("\t\t Ladder And Snake Game\n");
            printf("\t\t\t--------------------------------\n\n");
            start_Ladder_And_Snake_Game();
            break;
        case 2:
            system("cls");
            printf("--------------------------------\n");
            printf("\t\t Tic Tac Teo Game\n");
            printf("\t\t\t--------------------------------\n\n");
            starXO_Game();
            break;
        case 3:
            system("cls");
            printf("--------------------------------\n");
            printf("\t\t GOOD BYE\n");
            printf("\t\t\t--------------------------------\n\n");
            break;
        
        default:
            system("cls");
            printf("\n\t=> Invalid Input\n\n");
            break;
        }

    } while (option != 3);

    system("pause");
}