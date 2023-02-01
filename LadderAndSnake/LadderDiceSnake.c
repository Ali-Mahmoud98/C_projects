#include<stdio.h>
#include<stdlib.h>
#include "func.h"

void displayChart(int currentPosition, char player[4]);
char randVal();
void SnackAndLaddersPositions();
void chooseWhoStartFisrt();
void checkDice(char a, char turn);

void main()
{
    char player1Position =0;
    char player2Position =0;
    char diceVal=0;
    char option =0;
    char turn =0;

    while (1)
    {
        SnackAndLaddersPositions();
        chooseWhoStartFisrt();
        scanf("%s", &option);

        switch (option)
        {
        case '1':
            system("cls"); //clear cmd
            diceVal = randVal();
            printf("\t\t\tPlayer One dice value = %d \n", diceVal);
            turn =1;
            checkDice(diceVal, turn);
            player1Position += diceVal;
                if(player1Position<101){
                    if(player1Position==1){
                        player1Position=23;
                        displayChart(23 ,"{A}");//ladder
                    }else if(player1Position==5) {
                        player1Position=26;
                        displayChart(26,"{A}");//ladder
                    }else if(player1Position==8){
                        player1Position=14;
                        displayChart(14,"{A}");//ladder
                    }else if(player1Position==9){
                        player1Position=31;
                        displayChart(31,"{A}");//ladder
                    }else if(player1Position==36){
                        player1Position=58;
                        displayChart(58,"{A}");//ladder
                    }else if(player1Position==48){
                        player1Position=87;
                        displayChart(87,"{A}");//ladder
                    }else if(player1Position== 65){
                        player1Position=84;
                        displayChart(84, "{A}");//ladder
                    }else if(player1Position==62){
                        player1Position=62;
                        displayChart(62,"{A}");//ladder
                    }else if(player1Position==70){
                        player1Position=70;
                        displayChart(70,"{A}");//ladder
                    }else if(player1Position==99){
                        player1Position=77;
                        displayChart(77,"{A}");//snake
                    }else if(player1Position==94){
                        player1Position=47;
                        displayChart(47,"{A}");//snake
                    }else if(player1Position==92){
                        player1Position=49;
                        displayChart(49,"{A}");//snake
                    }else if(player1Position==63){
                        player1Position=37;
                        displayChart(37,"{A}");//snake
                    }else if(player1Position==56){
                        player1Position=27;
                        displayChart(27,"{A}");//snake
                    }else if(player1Position==41){
                        player1Position=3;
                        displayChart(3,"{A}");//snake
                    }else if(player1Position==33){
                        player1Position=10;
                        displayChart(10,"{A}");//snake
                    }else if(player1Position==24){
                        player1Position=4;
                        displayChart(4,"{A}");//snake
                    }else{
                        displayChart(player1Position,"{A}");
                    }
                }else{
                    player1Position=player1Position-diceVal;
                    printf("Range exceeded of Player %d.\n",1);
                    displayChart(player1Position,"{A}");
                }
            break;

        case '2':
            system("cls"); //clear cmd
            diceVal = randVal();
            printf("\t\t\tPlayer Two dice value = %d \n", diceVal);
            turn =2;
            checkDice(diceVal, turn);
            player2Position += diceVal;
                if(player2Position<101){
                    if(player2Position==1){
                        player2Position=23;
                        displayChart(23 ,"{B}");//ladder

                    }else if(player2Position==5) {
                        player2Position=26;
                        displayChart(26,"{B}");//ladder

                    }else if(player2Position==8){
                        player2Position=14;
                        displayChart(14,"{B}");//ladder

                    }else if(player2Position==9){
                        player2Position=31;
                        displayChart(31,"{B}");//ladder

                    }else if(player2Position==36){
                        player2Position=58;
                        displayChart(58,"{B}");//ladder

                    }else if(player2Position==48){
                        player2Position=87;
                        displayChart(87,"{B}");//ladder

                    }else if(player2Position== 65){
                        player2Position=84;
                        displayChart(84, "{B}");//ladder

                    }else if(player2Position==62){
                        player2Position=97;
                        displayChart(97,"{B}");//ladder

                    }else if(player2Position==70){
                        player2Position=91;
                        displayChart(91,"{B}");//ladder

                    }else if(player2Position==99){
                        player2Position=77;
                        displayChart(77,"{B}");//snake

                    }else if(player2Position==94){
                        player2Position=47;
                        displayChart(47,"{B}");//snake
                    }else if(player2Position==92){
                        player2Position=49;
                        displayChart(49,"{B}");//snake
                    }else if(player2Position==63){
                        player2Position=37;
                        displayChart(37,"{B}");//snake
                    }else if(player2Position==56){
                        player2Position=27;
                        displayChart(27,"{B}");//snake
                    }else if(player2Position==41){
                        player2Position=3;
                        displayChart(3,"{B}");//snake
                    }else if(player2Position==33){
                        player2Position=10;
                        displayChart(10,"{B}");//snake
                    }else if(player2Position==24){
                        player2Position=4;
                        displayChart(4,"{B}");//snake
                    }else{
                        displayChart(player2Position,"{B}");
                    }
                }else{
                    player2Position=player2Position-diceVal;
                    printf("Range exceeded of Player %d.\n",2);
                    displayChart(player2Position,"{B}");
                }
            break;

        case '3':
            exit(0);
            break;

        default:
            printf("Try Again, you should Enter numbers 1, 2, or 3\n");
            break;
        }
        printf("player 1 position --> %d \n", player1Position);
        printf("player 2 position --> %d \n", player2Position);
    }
}

