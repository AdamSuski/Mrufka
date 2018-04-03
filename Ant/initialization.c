//
// Created by T460s on 19.03.2018.
//
#include <stdlib.h>
#include <stdio.h>
#include "initialization.h"


int readFromFile(int* x, int* y, int* antCounter, int* heading, int boardSize, int* handlingLenght, char* handling)
{
	int buf = 0;
	FILE * file;
	file = fopen( "initialization.txt" , "r");
	fscanf(file, %d, &boardSize);
	fscanf(file, %d, antCounter);
	x = malloc(sizeof(int) * (*antCounter));
	y = malloc(sizeof(int) * (*antCounter));
	heading = malloc(sizeof(int) * (*antCounter));
	for(int i = 0;i < (*antCounter); i++){
	fscanf(file, %d, &x[i]);
	fscanf(file, %d, &y[i]);
	fscanf(file, %d, &heading[i]);
	}
	fscanf(file, %d, handlingLenght);
	handling = malloc(sizeof(char) * (*handlingLenght));
	for(int i=0; i < (*handlingLenght); i++){
	fscanf(file, %c, &handling[i]);
	}
	
	fclose(file);
	return boardSize;
}