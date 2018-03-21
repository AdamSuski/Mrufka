#include "plansza.h"
#include <stdlib.h>
#include <stdio.h>

//x - ilosc wierszy, y - ilosc kolumn
int** generowaniePlanszy(int x, int y){
    int** plansza;
    if (( plansza = malloc( x*sizeof( int* ))) == NULL ){
        return NULL;
    }
    int i;
    for ( i = 0; i < x; i++ ){
        if (( plansza[i] = malloc( y*sizeof (int) )) == NULL ){
                int j;
                for(j=0; j<=i; j++)
                    plansza[j]==NULL;
                return NULL;
        }
    }
    return plansza;
}

void wyswietlaniePlanszy(int** tablica, int x, int y){
    printf("\n");
    int i,j;
    for(i=0;i<x;i++){
        for(j=0;j<y;j++){
            printf("%d", tablica[i][j]);
        }
        printf("\n");
    }
}
