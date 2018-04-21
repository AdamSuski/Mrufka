#include "displaySDL.h"
#include <stdio.h>

//void destroymySDL(){
//    SDL_DestroyRenderer(renderer);
//    SDL_DestroyWindow(window);
//    SDL_Quit();
//}

void rysujCzarny( int xm, int ym ){
    SDL_RenderClear( renderer );
    ant.x=xm*ROZMIARMROWKI;
    ant.y=ym*ROZMIARMROWKI;
    SDL_SetRenderDrawColor( renderer, 0, 0, 0, 0 );
    SDL_RenderFillRect( renderer, &ant );
    SDL_RenderPresent( renderer );
}

void rysujKolor( int xm, int ym, int i ){
    SDL_RenderClear( renderer );
   if(i==1){
                ant.x=xm*ROZMIARMROWKI;
                ant.y=ym*ROZMIARMROWKI;
                SDL_SetRenderDrawColor( renderer, 0, 0, 255, 255 );
                SDL_RenderFillRect( renderer, &ant );
                SDL_RenderPresent( renderer );
            }
            if(i==2){
                ant.x=xm*ROZMIARMROWKI;
                ant.y=ym*ROZMIARMROWKI;
                SDL_SetRenderDrawColor( renderer, 255, 0, 255, 255 );
                SDL_RenderFillRect( renderer, &ant );
                SDL_RenderPresent( renderer );
            }
            if(i==3){
                ant.x=xm*ROZMIARMROWKI;
                ant.y=ym*ROZMIARMROWKI;
                SDL_SetRenderDrawColor( renderer, 0, 255, 0, 255 );
                SDL_RenderFillRect( renderer, &ant );
                SDL_RenderPresent( renderer );
            }
            if(i==4){
                ant.x=xm*ROZMIARMROWKI;
                ant.y=ym*ROZMIARMROWKI;
                SDL_SetRenderDrawColor( renderer, 255, 0, 0, 255 );
                SDL_RenderFillRect( renderer, &ant );
                SDL_RenderPresent( renderer );
            }
            if(i==5){
                ant.x=xm*ROZMIARMROWKI;
                ant.y=ym*ROZMIARMROWKI;
                SDL_SetRenderDrawColor( renderer, 255, 255, 0, 255 );
                SDL_RenderFillRect( renderer, &ant );
                SDL_RenderPresent( renderer );
            }
}

void render(int** board, int size){
	SDL_RenderClear( renderer );
	int i,j;
    for(i=0;i<size;i++){
        for(j=0; j<size; j++){
            if(board[i][j]==0){
                ant.x=i*ROZMIARMROWKI;
                ant.y=j*ROZMIARMROWKI;
                SDL_SetRenderDrawColor( renderer, 0, 0, 0, 0 );
                SDL_RenderFillRect( renderer, &ant );
                SDL_RenderPresent( renderer );
            }
            if(board[i][j]==1){
                ant.x=i*ROZMIARMROWKI;
                ant.y=j*ROZMIARMROWKI;
                SDL_SetRenderDrawColor( renderer, 0, 0, 255, 255 );
                SDL_RenderFillRect( renderer, &ant );
                SDL_RenderPresent( renderer );
            }
            if(board[i][j]==2){
                ant.x=i*ROZMIARMROWKI;
                ant.y=j*ROZMIARMROWKI;
                SDL_SetRenderDrawColor( renderer, 255, 0, 255, 255 );
                SDL_RenderFillRect( renderer, &ant );
                SDL_RenderPresent( renderer );
            }
            if(board[i][j]==3){
                ant.x=i*ROZMIARMROWKI;
                ant.y=j*ROZMIARMROWKI;
                SDL_SetRenderDrawColor( renderer, 0, 255, 0, 255 );
                SDL_RenderFillRect( renderer, &ant );
                SDL_RenderPresent( renderer );
            }
            if(board[i][j]==4){
                ant.x=i*ROZMIARMROWKI;
                ant.y=j*ROZMIARMROWKI;
                SDL_SetRenderDrawColor( renderer, 255, 0, 0, 255 );
                SDL_RenderFillRect( renderer, &ant );
                SDL_RenderPresent( renderer );
            }
            if(board[i][j]==5){
                ant.x=i*ROZMIARMROWKI;
                ant.y=j*ROZMIARMROWKI;
                SDL_SetRenderDrawColor( renderer, 255, 255, 0, 255 );
                SDL_RenderFillRect( renderer, &ant );
                SDL_RenderPresent( renderer );
            }
        }
    }
}

int initEverything(int sizeBoard){
	if ( !initSDL() )
		return 0;
	if ( !createWindow(sizeBoard) )
		return 0;
	if ( !createRenderer() )
		return 0;
    ant.w=ROZMIARMROWKI;
    ant.h=ROZMIARMROWKI;
	return 1;
}

int initSDL(){
	if ( SDL_Init( SDL_INIT_EVERYTHING ) == -1 ){
		printf( "Failed to initialize SDL!\n" );
		return 0;
	}
	return 1;
}

int createWindow(int sizeBoard){
	window = SDL_CreateWindow( "Mrowka Grupa1",
                           SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                           sizeBoard*ROZMIARMROWKI, sizeBoard*ROZMIARMROWKI, 0 );

	if ( window == NULL )
	{
		printf( "Failed to initialize window!\n" );
		return 0;
	}

	return 1;
}
int createRenderer(){
	renderer = SDL_CreateRenderer( window, -1, 0 );

	if ( renderer == NULL )
	{
		printf( "Failed to initialize renderer!\n" );
		return 0;
	}
	SDL_SetRenderDrawColor( renderer, 0, 0, 0, 0 );
	return 1;
}

void antShow( int** board, int size ){
    render( board,  size );
    SDL_Delay(1);
}

