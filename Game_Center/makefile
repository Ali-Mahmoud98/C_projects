file1 = main.c
file1 += ./TicTacTeoGame/startXO_Game.c
file1 += ./TicTacTeoGame/X_O_Game.c
file1 += ./LadderAndSnake/LadderDiceSnake.c
file1 += ./LadderAndSnake/start_Ladder_And_Snake_Game.c

Display:
	@echo "The Game Center is Starting"

Compile: Display
	gcc $(file1) -o Game_Center

run: Compile
	Game_Center.exe

clean:
	@cls
	@del *.exe
	@echo "The All .exe files are deleted"