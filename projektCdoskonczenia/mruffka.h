#ifndef _MRUFFKA_H
#define _MRUFFKA_H

#define AKTYWNA 1
#define NIEAKTYWNA 0
#define prawo 2
#define lewo 3
#define N 4
#define E 5
#define S 6
#define W 7

typedef struct mrufka{
    int x,y,aktywnosc, sterowanie, kierunek;
}*mrufka_t;

mrufka_t zrobMrufki( int );

int sprawdzAktywnosc( mrufka_t, int, int );

void zmienPozycje(int**, int, mrufka_t, int );

void algorytmMrowki( int**, int, mrufka_t, int );

#endif // MRUFFKA_H_
