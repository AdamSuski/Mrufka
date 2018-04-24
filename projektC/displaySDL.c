#include <stdio.h>
#include "displaySDL.h"

void destroymySDL(){
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

void drawBlack( int xm, int ym ){
    ant.x=xm*ANTSIZE;
    ant.y=ym*ANTSIZE;
    SDL_SetRenderDrawColor( renderer, 0, 0, 0, 0 );
    SDL_RenderFillRect( renderer, &ant );
    SDL_RenderPresent( renderer );
}

void drawColor( int xm, int ym, int i ){
    ant.x=xm*ANTSIZE;
    ant.y=ym*ANTSIZE;
    if(i==1){
        SDL_SetRenderDrawColor( renderer, 0, 0, 255, 255 );
        SDL_RenderFillRect( renderer, &ant );
    }
    if(i==2){
        SDL_SetRenderDrawColor( renderer, 255, 1, 255, 255 );
        SDL_RenderFillRect( renderer, &ant );
    }
    if(i==3){
        SDL_SetRenderDrawColor( renderer, 0, 255, 0, 255 );
        SDL_RenderFillRect( renderer, &ant );
    }
    if(i==4){
        SDL_SetRenderDrawColor( renderer, 255, 0, 0, 255 );
        SDL_RenderFillRect( renderer, &ant );
    }
    if(i==5){
        SDL_SetRenderDrawColor( renderer, 255, 255, 0, 255 );
        SDL_RenderFillRect( renderer, &ant );
    }
}

int initEverything(int sizeBoard){
	if ( SDL_Init( SDL_INIT_EVERYTHING ) == -1 ){
		printf( "Failed to initialize SDL!\n" );
		return 0;
	}
	window = SDL_CreateWindow( "Mrowka Grupa1",
                           SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                           sizeBoard*ANTSIZE, sizeBoard*ANTSIZE, 0 );
	if ( window == NULL ){
		printf( "Failed to initialize window!\n" );
		return 0;
	}
	renderer = SDL_CreateRenderer( window, -1, 0 );
	if ( renderer == NULL ){
		printf( "Failed to initialize renderer!\n" );
		return 0;
	}
	SDL_SetRenderDrawColor( renderer, 0, 0, 0, 0 );
    ant.w=ANTSIZE;
    ant.h=ANTSIZE;
    SDL_RenderClear( renderer );
	return 1;
}

void antShow( int milisec ){
    SDL_RenderPresent( renderer );
    SDL_Delay( milisec );
}

