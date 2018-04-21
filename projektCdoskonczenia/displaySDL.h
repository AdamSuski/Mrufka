#ifndef _DISPLAYSDL_H
#define _DISPLAYSDL_H

#include "SDL2/SDL.h"
#define ROZMIARMROWKI 4

SDL_Window* window;
SDL_Renderer* renderer;
SDL_Rect ant;

//void destroymySDL();
void rysujCzarny( int, int );
void rysujKolor( int, int, int );
void render( int**, int );
int initEverything( int );
int initSDL();
int createWindow( int );
int createRenderer();
void antShow( int**, int );


#endif // _DISPLAYSDL_H
