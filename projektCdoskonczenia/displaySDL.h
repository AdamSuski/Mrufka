#ifndef _DISPLAYSDL_H
#define _DISPLAYSDL_H

#include "SDL2/SDL.h"
#define ANTSIZE 4

SDL_Window* window;
SDL_Renderer* renderer;
SDL_Rect ant;

void drawBlack( int, int );

void drawColor( int, int, int );

int initEverything( int );

void destroymySDL();

void antShow( int );


#endif // _DISPLAYSDL_H
