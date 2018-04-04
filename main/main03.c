#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>
#include "board.h"
#include "AntMovement.h"
#include "display.h"
#include "initialization.h"

int main (int argc, char **argv){
    if(argc!=2){
        printf("Nie moge znalezc pliku\n");
        return EXIT_FAILURE;
    }
    int boardSize;
    int* antCounter;
    int* handlingLenght;
    int* x;
    int* y;
    int* heading;
    char* handling;
    char* plik=argv[1];
	boardSize=readFromFile(x, y, antCounter, heading, boardSize, handlingLenght, handling, plik);
	if(boardSize==0){
        printf("Koncze prace programu\n");
        return EXIT_FAILURE;
	}
	//
    int **board = boardGenerate(boardSize);
    if(board==NULL){
        printf("Blad alokacji pamieci!\n");
        return EXIT_FAILURE;
    }
    //
    (int)antCounter;
    (int)handlingLenght;

    //
    antAlgorithm(x,y,antCounter,heading,board,boardSize,handlingLenght,handling);
    //
    printf("TU\n");
//    free(*antCounter);
//    free(x);
//    free(y);
//    free(heading);
//    free(handling);
//    free(plik);
//    free(handlingLenght);
    return EXIT_SUCCESS;
}
