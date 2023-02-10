
prog : main.o fonction.o
	gcc main.o fonction.o -o prog -lSDL -lSDL_image -lSDL_ttf -lSDL_mixer -g
	
main.o: main.c
	gcc -c main.c -g  

fonction.o: fonction.c
	gcc -c fonction.c -g  



