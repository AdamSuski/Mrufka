//
// Created by T460s on 19.03.2018.
//
#include <stdlib.h>
#include <stdio.h>
#include "AntMovement.h"
#include "display.h"

int makeHeading(int head , char handling)
{
    switch(handling)
    {
        case 'L': head = (head + 1);
            break;
        case 'R': head = (head - 1);
            break;
    }

    if (head == -1) { head = 3; }
    else if(head == 4) { head % 4; }

    return head;
}

int checkActive(int* activityTab, int antCounter)
{
    int counter = 0;
    for(int i=0; i<antCounter; i++)
    {
        if(activityTab[i] == 1 ){ counter++; }
    }

    if(counter>0){return 1;}

    return 0;
}

int acivityCheck(int x, int y, int boardSize)
{
    if(x < 0 || x >boardSize){return 0;}
    if(y < 0 || y >boardSize){return 0;}

    return 1;
}

int makeFootprint(int fieldInfo , int handlingLenght)
{
    fieldInfo++;
    if( fieldInfo == handlingLenght ){ fieldInfo == 0; }
    return fieldInfo;
}

void moveAnt ( int* x, int* y, int* heading, int antNumber, int fieldInfo,int** board, int handlingLenght, char handling )
{

    board[ x[antNumber] ][ y[antNumber] ] = makeFootprint( fieldInfo, handlingLenght);

    switch (*heading)
    {
        case 0:
            if(handling == 'L'){x[antNumber] -= 1;}
            else if(handling =='R'){x[antNumber] += 1;}
            break;
        case 1:
            if(handling == 'L'){y[antNumber] -= 1;}
            else if(handling =='R'){y[antNumber] += 1;}
            break;
        case 2:
            if(handling == 'L'){x[antNumber] += 1;}
            else if(handling =='R'){x[antNumber] -= 1;}
            break;
        case 3:
            if(handling == 'L'){y[antNumber] += 1;}
            else if(handling =='R'){y[antNumber] -= 1;}
            break;
    }

    heading[antNumber] = makeHeading( *heading, handling);
}
void antAlgorithm ( int* x, int* y, int antCounter, int* heading, int** board, int boardSize, int handlingLenght, char* handling)
{
    int* activityTab = (int *)malloc(antCounter* sizeof(int));
    for(int j=0;j<antCounter;j++)
    {
        activityTab[j] = 1;
    }
    int active = 1;
    int temporaryFieldInfo;
    while(active) {
        {
        for (int i = 0; i < antCounter; i++) {
            if (activityTab[i] == 1) {
                temporaryFieldInfo =board[x[i]][y[i]];
                moveAnt(x, y, heading, i, board[x[i]][y[i]], board, handlingLenght, handling[temporaryFieldInfo]);
                activityTab[i] = acivityCheck( x[i], y[i], boardSize);
                }
            }
        }
        active = checkActive( activityTab, antCounter);
        createImage(board,boardSize,boardSize, 2000);
    }
}
