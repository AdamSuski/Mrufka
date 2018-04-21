#include "board.h"
#include <stdlib.h>
#include <stdio.h>

//x - liczba wierszy i kolumn
int** boardGenerate(int x){
    int** board;
    if (( board = malloc( x*sizeof( *board ))) == NULL ){
        return NULL;
    }
    int i;
    for(i =0; i<x; i++)
        board[i]=malloc((x*sizeof(board)));
    int j;
    for(i=0; i<x; i++)
        for(j=0; j<x; j++)
            board[i][j]=0;
    return board;
}

//board - tablica dop wyswietlenia; x - liczba kolumn i wierszy
void boardDisplay(int** board, int x){
    printf("\n");
    int i,j;
    for(i=0;i<x;i++){
        for(j=0;j<x;j++){
            printf("%d\t", board[i][j]);
        }
        printf("\n");
    }
}
