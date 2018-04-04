//
// Created by T460s on 19.03.2018.
//
#include <stdlib.h>
#include <stdio.h>
#include "initialization.h"

int checkInit(int* x, int* y, int* antCounter, int* heading, int boardSize, int* handlingLenght, char* handling)
{
	if(boardSize < 9 || boardSize > 641) { printf("zly rozmiar planszy"); return 0;}
	if((*antCounter) < 1 || (*antCounter) > 5) { printf("zly rozmiar planszy"); return 0; }
	for(int i = 0; i < (*antCounter); i++){
		if( x[i] < 0 || x[i] > boardSize) { printf("zly parametr początkowy x mrowki %d",i); return 0; }
		if( y[i] < 0 || y[i] > boardSize) { printf("zly parametr początkowy y mrowki %d",i); return 0; }
		if( heading[i] < 0 || heading[i] > 3) { printf("zly parametr początkowy kierunku mrowki %d",i); return 0; }
	}
	for(int i = 0; i < (*handlingLenght); i++){
		if(handling[i] != 'L' && handling[i] != 'R'){
            printf("błąd %d elementu sterowania", i); return 0;
	}
	return boardSize;
}}

int readFromFile(int* x, int* y, int* antCounter, int* heading, int boardSize, int* handlingLenght, char* handling, char* fileARG) // funkcja czytająca z pliku
{
	FILE * file;
	file = fopen( fileARG , "r");
	fscanf(file, "%d", &boardSize); // wczytaj rozmiar planszy
	fscanf(file, "%d", antCounter); // wczytaj ilość mrówek
	x = malloc(sizeof(int) * (*antCounter)); // allokacja poszczególnych tablic x y i kierunek
	y = malloc(sizeof(int) * (*antCounter));
	heading = malloc(sizeof(int) * (*antCounter));

	for(int i = 0;i < (*antCounter); i++){   // iterujemy się po wszytskich mrówkach i pokolei wczytujemy parametry startowe
	fscanf(file, "%d", &x[i]);
	fscanf(file, "%d", &y[i]);
	fscanf(file, "%d", &heading[i]);
	}

	fscanf(file, "%d", handlingLenght);  // wczytujemy długość instrukcji sterującej
	handling = malloc(sizeof(char) * (*handlingLenght));

//	for(int i=0; i < (*handlingLenght); i++){   // wczytujemy pokolei sterowanie
//		*handling++ = (char)fgetc(file);
//	}
    int Z;
    Z=fgetc(file);
	for( int i=0; i < (*handlingLenght); i++){
        Z=fgetc(file);

        handling[i]=((char)Z);
	}
	fclose(file);
	boardSize = checkInit(x, y, antCounter, heading, boardSize, handlingLenght, handling);

	return boardSize;
}
