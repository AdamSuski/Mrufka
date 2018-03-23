#include "board.h"
#include <stdlib.h>
#include <stdio.h>

//x - amount of rows, y - amount of columns
int** boardGenerate(int x, int y){
    int** board;
    if (( board = malloc( x*sizeof( int* ))) == NULL ){
        return NULL;
    }
    int i;
    for ( i = 0; i < x; i++ ){
        if (( board[i] = malloc( y*sizeof (int) )) == NULL ){
                int j;
                for(j=0; j<=i; j++)
                    board[j]==NULL;
                return NULL;
        }
    }
    return board;
}

void boardDisplay(int** board, int x, int y){
    printf("\n");
    int i,j;
    for(i=0;i<x;i++){
        for(j=0;j<y;j++){
            printf("%d", board[i][j]);
        }
        printf("\n");
    }
}
