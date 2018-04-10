#ifndef _DISPLAY_H
#define _DISPLAY_H
#include <SDL2/SDL.h>

//creating single image in SDL2
void createImage( int**, int, SDL_Renderer* );
//destroying SDL window and renderer
void destorySDL( SDL_Window*, SDL_Renderer* );
//
SDL_Renderer* createRender( SDL_Window* );
//
SDL_Window* createWindow( int );

#endif // _DISPLAY_H_
