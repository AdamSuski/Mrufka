#include "display.h"
#include <SDL2/SDL.h>

void destorySDL( SDL_Window* window, SDL_Renderer* renderer ){
    //quiting SDL and destroying all pointers
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

void createImage(int** plansz, int size, SDL_Renderer* rndr){
    //creating window & renderer
    SDL_RenderClear(rndr);
    //setting render
    int i,j;
    for(i=0; i<size; i++){
           for(j=0; j<size; j++){
                if(plansz[i][j]==1){
                    SDL_SetRenderDrawColor(rndr, 0, 0, 255, 255);
                    SDL_RenderDrawPoint(rndr, i, j);
                }else if(plansz[i][j]==2){
                    SDL_SetRenderDrawColor(rndr, 0, 255, 0, 255);
                    SDL_RenderDrawPoint(rndr, i, j);
                }else if(plansz[i][j]==3){
                    SDL_SetRenderDrawColor(rndr, 255, 0, 0, 255);
                    SDL_RenderDrawPoint(rndr, i, j);
                }
                else if(plansz[i][j]==4){
                    SDL_SetRenderDrawColor(rndr, 255, 0, 255, 255);
                    SDL_RenderDrawPoint(rndr, i, j);
                }
                else if(plansz[i][j]==5){
                    SDL_SetRenderDrawColor(rndr, 255, 255, 0, 255);
                    SDL_RenderDrawPoint(rndr, i, j);
                }
            }
    }
    SDL_RenderPresent(rndr);
    //waiting for user key event
    SDL_Event event;
    while(1){
        if (SDL_PollEvent(&event) && event.type == SDL_QUIT)
            break;
    }
}

SDL_Window* createWindow( int boardSize ){
    SDL_Init(SDL_INIT_EVERYTHING);
    SDL_Window* window= SDL_CreateWindow("Program Mrowka",
                                         SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, boardSize, boardSize, SDL_WINDOW_SHOWN);
    return window;
}

SDL_Renderer* createRender( SDL_Window* okienko ){
    SDL_Renderer* render= SDL_CreateRenderer(okienko, -1, SDL_RENDERER_ACCELERATED);
    return render;
}
