all: solver

fichier.o:	fichier.c fichier.h
	gcc -c fichier.c

pile.o: pile.c pile.h
	gcc -c pile.c

jeu.o: jeu.c jeu.h
	gcc -c jeu.c

solvermain.o: solvermain.c
	gcc -c solvermain.c

solver: solvermain.o pile.o fichier.o jeu.o
	gcc -o solver solvermain.o pile.o fichier.o jeu.o

clean:
	rm *.o solver
