#ifndef LADDER_DICE_SNAKE_H_
#define LADDER_DICE_SNAKE_H_

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void displayChart(int currentPosition, char player[4]);
char randVal();
void SnackAndLaddersPositions();
void chooseWhoStartFisrt();
void checkDice(char a, char turn);

#endif
