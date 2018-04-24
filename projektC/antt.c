#include <stdlib.h>
#include <stdio.h>
#include "antt.h"
#include "displaySDL.h"
#include "board.h"

ants_t makeAnts( int antsAmount ){
    ants_t anties = malloc( antsAmount * sizeof(*anties) );
    if( anties!=NULL )
        return anties;
    return NULL;
}

int checkActivity( ants_t insectsi, int i, int boardSize ){
    if( insectsi[i].x < 0 || insectsi[i].x > boardSize-1 || insectsi[i].y < 0 || insectsi[i].y > boardSize-1 )
        return NONACTIVEA;
    else
        return ACTIVEA;
}

void changePosition( ants_t insect, int i ){
    switch( insect[i].direction ){
        case N:
                if( insect[i].handling == righth ){
                    insect[i].x++;
                    insect[i].direction=E;
                }
                else {
                    insect[i].x--;
                    insect[i].direction=W;
                }
            break;
        case E:
                if( insect[i].handling == righth ){
                    insect[i].y++;
                    insect[i].direction=S;
                }
                else{
                    insect[i].y--;
                    insect[i].direction=N;
                }
            break;
        case S:
                if( insect[i].handling == righth ){
                    insect[i].x--;
                    insect[i].direction=W;
                }
                else{
                    insect[i].x++;
                    insect[i].direction=E;
                }
            break;
        case W:
                if( insect[i].handling == righth ){
                    insect[i].direction=N;
                    insect[i].y--;
                }
                else{
                    insect[i].y++;
                    insect[i].direction=S;
                }
            break;
    }
}

void antsAlgorithm(int** board, int boardSize, ants_t insects, int antAmount, int milisec){
    initEverything( boardSize );
    int activity = antAmount;
    int activeAntCounter = 0;
    int i = 0;
    int loop = 1;
    SDL_Event event;
    while( loop && activity ){
        if( board[insects[i].x][insects[i].y] == 0 ){
            board[insects[i].x][insects[i].y] = i+1;
            insects[i].handling = insects[i].handlingOriginal;
            drawColor( insects[i].x, insects[i].y, i+1 );
        }
        else{
            board[insects[i].x][insects[i].y] = 0;
            insects[i].handling = insects[i].handlingDerivate;
            drawBlack( insects[i].x, insects[i].y );
        }
        changePosition( insects, i );
        activeAntCounter += checkActivity( insects, i, boardSize );
        if( i == antAmount-1 ){
            antShow( milisec );
            if( activeAntCounter != activity )
                activity = 0;
            else{
                i = 0;
                activeAntCounter = 0;
            }
        }
        else
            i++;
        while ( SDL_PollEvent( &event ) )
            if ( event.type == SDL_QUIT )
                loop = 0;
        }
    destroymySDL();
}
