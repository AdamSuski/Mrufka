#include "display.h"
#include <SDL2/SDL.h>

void createImage(int** plansz, int wwidth, int wheigh, int milisec){
    //init all SDL
    SDL_Init(SDL_INIT_EVERYTHING);
    //creating  window and render
    SDL_Window* mywindow;
    SDL_Renderer* render;
    SDL_Event event;
    //creating window & renderer
    SDL_CreateWindowAndRenderer(wwidth , wheigh, 0, &mywindow, &render);
    //setting render
    SDL_SetRenderDrawColor(render, 0, 0, 0, 0);
    SDL_RenderClear(render);
    //
    int i,j;
    for(;;){
        for(i=0; i<wwidth; i++)
            for(j=0; j<wheigh; j++){
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

    //setting red pixel
//    SDL_SetRenderDrawColor(render, 255, 0, 0, 255);
//    int i,j;
//    for(i=0; i<wwidth; i++)
//        for(j=0; j<wheigh; j++){
//            if(plansz[i][j]==1)SDL_RenderDrawPoint(render, i, j);
//        }
//
//    SDL_RenderPresent(render);
    while(1){
             if (SDL_PollEvent(&event) && event.type == SDL_QUIT)
             break;
    }
    //quiting SDL and destroying all pointers
    SDL_DestroyRenderer(render);
    SDL_DestroyWindow(mywindow);
    SDL_Quit();
}
