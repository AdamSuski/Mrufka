#include "board.h"
#include <stdlib.h>
#include <stdio.h>

//x - amount of rows, y - amount of columns
int** boardGenerate(int x){
    int** board;
    if (( board = malloc( x*sizeof( int* ))) == NULL ){
        return NULL;
    }
    int i;
    for ( i = 0; i < x; i++ ){
        if (( board[i] = malloc( x*sizeof (int) )) == NULL ){
                int j;
                for(j=0; j<=i; j++)
                    board[j]==NULL;
                return NULL;
        }
    }
    return board;
}

//board - 2dim array to display; x - amount of rows, y - amount of columns
void boardDisplay(int** board, int x){
    printf("\n");
    int i,j;
    for(i=0;i<x;i++){
        for(j=0;j<x;j++){
            printf("%d", board[i][j]);
        }
        printf("\n");
    }
}
