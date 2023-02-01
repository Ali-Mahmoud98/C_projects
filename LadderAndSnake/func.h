
// game grid, players positions, and checking end game function
void displayChart(int currentPosition, char player[4]) {
    if (currentPosition == 100) {
        printf("---------------^Congratulations^---------------\n\n\nPlayer %s wins\n", player);
        return;
    }

    int xCheck =0;
    int diceResult;
    int c,t;

    for (int i = 10; i > 0; i--) {
        t = i-1;
        if (xCheck%2 == 0)
        {
            c =0;
            for (int j = 10; j >0; j--) {
                diceResult=(i*j)+(t*c++);
                if(currentPosition== diceResult)
					printf("%s\t",player);
				else
				printf("%d\t",diceResult);
            }
            xCheck++;
        }else{
            c=9;
            for(int j=1;j<=10;j++)
			{
				diceResult=(i*j)+(t*c--);
                if(currentPosition== diceResult)
					printf("%s\t",player);
				else
				printf("%d\t",diceResult);
			}
            xCheck++;
        }
        
        printf("\n\n");
    }
    printf("--------------------------------------------------------------------------\n");
}

// dice value function gives nums from 1 to 6
char randVal(){
    return (rand() % 6) + 1; //return number between 0 and 5 then add 1 to get random number from 1 to 6
}

// ladders and snakes positions function 
void SnackAndLaddersPositions(){
    printf("\t\t -> Welcom This is Snake And Ladder Game ^_^ <- \n");
	printf("Snakes\n");
    printf("99-->77 \t 94-->47 \t 92-->49 \n63-->37 \t 56-->27 \t 41-->3 \n33-->10 \t 24-->4 \n\n");
	printf("Ladders\n");
    printf("01-->23 \t 05-->26 \t 08-->14 \n09-->31 \t 36-->58 \t 48-->87 \n65-->84 \t 62-->97 \t 70-->91 \n");
}

void chooseWhoStartFisrt(){
    printf("Choose player to play turn\n");
    printf("Enter 1 or 2\n");
	printf("1. Player 1 plays with symbole {A}\n");
	printf("2. Player 2 plays with symbole {B}\n");
    printf("For Exiting the Game Enter 3\n");
}

//Check if the player can play another turn or the second player will play
void checkDice(char a, char turn){
    if (a == 6)
    {
        printf("Good Dice=6 you can play another game ^_^\n");
        printf("Player %d second turn\n", turn);
    }else{
        turn = (turn ==1)? 2:1;
        printf("Player %d turn\n", turn);
    }
}