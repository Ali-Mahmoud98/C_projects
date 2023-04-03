file1 = main.c
file1 += examApp.c


Display:
	@echo "The Application is Starting"

Compile: Display
	gcc $(file1) -o Application

run: Compile
	Application.exe

clean:
	@cls
	@del *.exe
	@echo "The All .exe files are deleted"