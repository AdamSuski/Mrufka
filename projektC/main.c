#include <stdio.h>
#include <stdlib.h>
#include "board.h"
#include "antt.h"

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
    int antAmount, boardSize, milisecs;
    int** board;
    fscanf( fileInit, "%d %d %d\n", &antAmount, &boardSize, &milisecs );
    if( antAmount < 1 || antAmount > 5 ){
        printf( "Blad odczytu liczby mrowek(zakres od 1 do 5 mrowek)!\n" );
        return EXIT_FAILURE;
    }
    if( boardSize < 0 || boardSize > 180){
        printf( "Blad odczytu rozmiaru planszy!\n" );
        return EXIT_FAILURE;
    }
    if( milisecs < 1 || milisecs > 4000){
        printf( "Blad odczytu przerywnika(zakres od 1 do 4000 milisekund)!\n" );
        return EXIT_FAILURE;
    }
    board = boardGenerate( boardSize );
    if(board == NULL){
        printf( "Blad alokacji planszy!\n" );
        return EXIT_FAILURE;
    }
    ants_t insects = makeAnts( antAmount );
    int i;
    for( i = 0; i < antAmount; i++ ){
        if( fscanf( fileInit, "%d %d %d %d\n", &insects[i].x, &insects[i].y, &insects[i].handlingOriginal, &insects[i].direction ) != 4 ){
            printf( "Niepoprawna ilosc wprowadzonych danych!\n" );
            return EXIT_FAILURE;
        }
        insects[i].handling=insects[i].handlingOriginal;
        if( insects[i].handlingOriginal == righth ){
            insects[i].handlingDerivate = lefth;
        }
        else{
            insects[i].handlingDerivate = righth;
        }
    }
    if( fgetc( fileInit ) != EOF ){
        printf( "Niepoprawna ilosc wprowadzonych danych!\n" );
        return EXIT_FAILURE;
    }
    fclose( fileInit );
    antsAlgorithm( board, boardSize, insects, antAmount, milisecs );
    return EXIT_SUCCESS;
}
