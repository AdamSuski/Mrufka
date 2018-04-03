//
// Created by T460s on 19.03.2018.
//
#include <stdlib.h>
#include <stdio.h>
#include "initialization.h"

int checkInit(int* x, int* y, int* antCounter, int* heading, int boardSize, int* handlingLenght, char* handling)
{
	if(boardSize < 9 || boardSize > 641) { return 0; printf("zly rozmiar planszy");}
	if(antCounter < 1 || antCounter > 5) { return 0; printf("zly rozmiar planszy");}
	for(int i = 0; i < antCounter; i++){
		if( x[i] < 0 || x[i] > boardSize) { return 0; printf("zly parametr początkowy x mrowki %d",i);}
		if( y[i] < 0 || y[i] > boardSize) { return 0; printf("zly parametr początkowy y mrowki %d",i);}
		if( heading[i] < 0 || heading[i] > 3) { return 0; printf("zly parametr początkowy kierunku mrowki %d",i);}
	}
	for(int i = 0; i < handlingLenght; i++){
		if(handling[i] != L && handling != R){return 0; printf("błąd %d elementu sterowania", i);
	}
	return boardSize;
}

int readFromFile(int* x, int* y, int* antCounter, int* heading, int boardSize, int* handlingLenght, char* handling) // funkcja czytająca z pliku 
{
	int buf = 0;
	FILE * file;
	file = fopen( "initialization.txt" , "r");
	fscanf(file, %d, &boardSize); // wczytaj rozmiar planszy 
	fscanf(file, %d, antCounter); // wczytaj ilość mrówek
	x = malloc(sizeof(int) * (*antCounter)); // allokacja poszczególnych tablic x y i kierunek
	y = malloc(sizeof(int) * (*antCounter));
	heading = malloc(sizeof(int) * (*antCounter));
	
	for(int i = 0;i < (*antCounter); i++){   // iterujemy się po wszytskich mrówkach i pokolei wczytujemy parametry startowe
	fscanf(file, %d, &x[i]);
	fscanf(file, %d, &y[i]);
	fscanf(file, %d, &heading[i]);
	}
	
	fscanf(file, %d, handlingLenght);  // wczytujemy długość instrukcji sterującej
	handling = malloc(sizeof(char) * (*handlingLenght));
	
	for(int i=0; i < (*handlingLenght); i++){   // wczytujemy pokolei sterowanie
		*handling++ = (char)fgetc(file);
	}
	
	boardSize = checkInit;
	fclose(file);
	
	return boardSize;
}