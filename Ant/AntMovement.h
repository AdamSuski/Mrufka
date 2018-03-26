//
// Created by T460s on 24.03.2018.
//

#ifndef ANT_ANTMOVEMENT_H
#define ANT_ANTMOVEMENT_H

int makeHeading(int head , char handling);

int checkActive(int* activityTab, int antCounter);

int acivityCheck(int x, int y, int boardSize);

int makeFootprint(int fieldInfo , int handlingLenght);

void moveAnt ( int* x, int* y, int* heading, int antNumber, int fieldInfo,int** board, int handlingLenght, char handling );

void antAlgorithm ( int* x, int* y, int antCounter, int* heading, int** board, int boardSize, int handlingLenght, char* handling);


#endif //ANT_ANTMOVEMENT_H
