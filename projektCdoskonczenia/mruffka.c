#include "mruffka.h"
#include "displaySDL.h"
#include <stdlib.h>
#include <stdio.h>
#include "board.h"

mrufka_t zrobMrufki( int iloscMrowek ){
    mrufka_t mrufki = malloc( iloscMrowek * sizeof(*mrufki) );
    if( mrufki!=NULL )
        return mrufki;
    return NULL;
}

int sprawdzAktywnosc( mrufka_t owady, int i, int rozmiar ){
    if( owady[i].x<0 || owady[i].x>rozmiar-1 || owady[i].y<0 || owady[i].y>rozmiar-1 )
        return NIEAKTYWNA;
    else
        return AKTYWNA;
}

void zmienPozycje(int** plansza, int rozmiar, mrufka_t owad, int i ){
    switch( owad[i].kierunek){
        case N:
                if( owad[i].sterowanie==prawo ){
                    owad[i].x++;
                    owad[i].kierunek=E;
                }
                else {
                    owad[i].x--;
                    owad[i].kierunek=W;
                }
            break;
        case E:
                if(owad[i].sterowanie==prawo){
                    owad[i].y++;
                    owad[i].kierunek=S;
                }
                else{
                    owad[i].y--;
                    owad[i].kierunek=N;
                }
            break;
        case S:
                if(owad[i].sterowanie==prawo){
                    owad[i].x--;
                    owad[i].kierunek=W;
                }
                else{
                    owad[i].x++;
                    owad[i].kierunek=E;
                }
            break;
        case W:
                if(owad[i].sterowanie==prawo){
                    owad[i].kierunek=N;
                    owad[i].y--;
                }
                else{
                    owad[i].y++;
                    owad[i].kierunek=S;
                }
            break;
    }
}

void algorytmMrowki(int** plansza, int rozmiarPlanszy, mrufka_t owady, int iloscMrowek){
//    initEverything(rozmiarPlanszy);
    int aktywnosc = iloscMrowek;
    int iloscAktywnychMrowek = 0;
    int i=0;
//    int loop=1;
//    while(loop){
//        SDL_Event event;
//		while ( SDL_PollEvent( &event ) ){
//			if ( event.type == SDL_QUIT )
//				loop = 0;
//            else{
//
//            }
//		}
//    }
    while( aktywnosc ){
        if(plansza[owady[i].x][owady[i].y]==0){
            plansza[owady[i].x][owady[i].y]=i;
            owady[i].sterowanie=prawo;
            rysujKolor(owady[i].x, owady[i].y, i);
        }
        else{
            plansza[owady[i].x][owady[i].y]=0;
            owady[i].sterowanie=lewo;
            rysujCzarny(owady[i].x, owady[i].y);
        }

        zmienPozycje(plansza, rozmiarPlanszy, owady, i);
        iloscAktywnychMrowek += sprawdzAktywnosc(owady, i, rozmiarPlanszy);
        if(i == iloscMrowek-1){
            //boardDisplay(plansza, rozmiarPlanszy);
            if(iloscAktywnychMrowek!=aktywnosc)
                aktywnosc=0;
            else{
                i=0;
                iloscAktywnychMrowek=0;
            }
        }
        else
            i++;
    }
}
