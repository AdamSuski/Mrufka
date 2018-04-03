#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>
#include "board.h"
#include "AntMovement.h"
#include "display.h"

int main (int argc, char **argv){
    //read from file
    int boardSize, antCounter, handlingLenght;
    int* x;
    int* y;
    int* heading;
    char* handling;
	FILE * file;
	file = fopen( argv[1] , "r");
	fscanf(file, "%d", &boardSize);
	fscanf(file, "%d", &antCounter);
	x = malloc(sizeof(int) * antCounter);
	y = malloc(sizeof(int) * antCounter);
	heading = malloc(sizeof(int) * antCounter);

	for(int i = 0;i < antCounter; i++){
        fscanf(file, "%d", &x[i]);
        fscanf(file, "%d", &y[i]);
        fscanf(file, "%d", &heading[i]);
	}
	fscanf(file, "%d", &handlingLenght);
	handling = malloc(sizeof(char) * handlingLenght);
    int Z;
    Z=fgetc(file);
	for(int i=0; i < handlingLenght; i++){
        Z=fgetc(file);
        (char)Z;
        handling[i]=Z;
	}
	fclose(file);
	//
    int **board = boardGenerate(boardSize);
    if(board==NULL){
        printf("Blad alokacji pamieci!\n");
        return EXIT_FAILURE;
    }
    //

    antAlgorithm(x,y,antCounter,heading,board,boardSize,handlingLenght,handling);
    //
    return EXIT_SUCCESS;
}
