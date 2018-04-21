#include <stdio.h>
#include <stdlib.h>
#include "board.h"
#include "mruffka.h"
#include "displaySDL.h"

int main( int argc, char** argv ){
    if( argc != 2 ){
        printf( "Niepoprawne uruchomienie programu! Nieodpowiednia ilosc argumentow programu!\n" );
        return EXIT_FAILURE;
    }
    FILE* fileInit = fopen( argv[1], "r" );
    if( fileInit == NULL ){
        printf( "Blad odczytu pliku \"%s\"\n", argv[1] );
        return EXIT_FAILURE;
    }
    int antAmount, boardSize;
    int** board;
    fscanf( fileInit, "%d %d", &antAmount, &boardSize );
    board = boardGenerate( boardSize);
    if(board == NULL){
        printf( "Blad alokacji planszy!\n" );
        return EXIT_FAILURE;
    }
    mrufka_t owady = zrobMrufki( antAmount );
    int i;
    for( i = 0; i < antAmount; i++ ){
        fscanf( fileInit, "%d %d %d %d", &owady[i].x, &owady[i].y, &owady[i].sterowanie, &owady[i].kierunek );
        owady[i].aktywnosc=AKTYWNA;
    }
    fclose(fileInit);
    initEverything(boardSize);
    algorytmMrowki(board, boardSize, owady, antAmount);

    return EXIT_SUCCESS;
}
