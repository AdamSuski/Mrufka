#include "display.h"
#include <SDL2/SDL.h>

void destorySDL( SDL_Window* window, SDL_Renderer* renderer ){
    //quiting SDL and destroying all pointers
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

void createImage(int** plansz, int size, int size, int milisec){
    //init all SDL
    SDL_Init(SDL_INIT_EVERYTHING);
    //creating  window and render
    SDL_Window* mywindow;
    SDL_Renderer* render;
    SDL_Event event;
    //creating window & renderer
    SDL_CreateWindowAndRenderer(size, size, 0, &mywindow, &render);
    //setting render
    SDL_SetRenderDrawColor(render, 0, 0, 0, 0);
    SDL_RenderClear(render);
    //
    int i,j;
    for(;;){
        for(i=0; i<size; i++)
            for(j=0; j<size; j++){
                if(plansz[i][j]==0){
                    SDL_SetRenderDrawColor(render, 255, 255, 255, 255);
                    SDL_RenderDrawPoint(render, i, j);
                }
                if(plansz[i][j]==1){
                    SDL_SetRenderDrawColor(render, 255, 0, 0, 255);
                    SDL_RenderDrawPoint(render, i, j);
                }
                if(plansz[i][j]==2){
                    SDL_SetRenderDrawColor(render, 0, 255, 0, 255);
                    SDL_RenderDrawPoint(render, i, j);
                }
                if(plansz[i][j]==3){
                    SDL_SetRenderDrawColor(render, 0, 0, 255, 255);
                    SDL_RenderDrawPoint(render, i, j);
                }
                if(plansz[i][j]==4){
                    SDL_SetRenderDrawColor(render, 243, 108, 18, 255);
                    SDL_RenderDrawPoint(render, i, j);
                }
            }

        SDL_RenderPresent(render);
        SDL_Delay(milisec);
        SDL_RenderClear(render);
    }
    //waiting fior user key event
    while(1){
             if (SDL_PollEvent(&event) && event.type == SDL_QUIT)
             break;
    }
    destroySDL(mywindow, render);

}
