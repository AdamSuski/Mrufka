//
// Created by T460s on 19.03.2018.
//
#include <stdlib.h>
#include <stdio.h>
#include "AntMovement.h"
int makeHeading(int head , char handling) // funkcja zmieniająca kierunek poruszania się mrówek
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

int checkActive(int* activityTab, int antCounter) // funkcja sprawdzająca czy zosatała przynajmniej jedna aktywna mrówka
{
    int counter = 0;
    for(int i=0; i<antCounter; i++)
    {
        if(activityTab[i] == 1 ){ counter++; } // jeżeli mrówka jest aktywna to zwiększ o jeden 
    }

    if(counter>0){return 1;} //jeżeli przynajmniej jeden to zwracamy aktywność

    return 0;
}

int acivityCheck(int x, int y, int boardSize) // funkcja sprawdza czy mrówka nie wyszła poza planszę 
{
    if(x < 0 || x >boardSize){return 0;}
    if(y < 0 || y >boardSize){return 0;}

    return 1;
}

int makeFootprint(int fieldInfo , int handlingLenght) //funkcja dodająca ślad na polu
{
    fieldInfo++;
    if( fieldInfo == handlingLenght ){ fieldInfo == 0; } // jeżeli osiągnięto długość instrukcji sterowania to zerujemy
    return fieldInfo;
}

void moveAnt ( int* x, int* y, int* heading, int antNumber, int fieldInfo,int** board, int handlingLenght, char handling )  // funkcja poruszająca mrówką
{

    board[ x[antNumber] ][ y[antNumber] ] = makeFootprint( fieldInfo, handlingLenght);  // dodajemy ślad

    switch (*heading)									// kierunek:
    {
        case 0:                                       	//Północ
            if(handling == 'L'){x[antNumber] -= 1;}
            else if(handling =='R'){x[antNumber] += 1;}
            break;
        case 1:											//Zachód 
            if(handling == 'L'){y[antNumber] -= 1;}
            else if(handling =='R'){y[antNumber] += 1;}
            break;
        case 2:											//Południe
            if(handling == 'L'){x[antNumber] += 1;}
            else if(handling =='R'){x[antNumber] -= 1;}
            break;
        case 3:											//Wschód
            if(handling == 'L'){y[antNumber] += 1;}
            else if(handling =='R'){y[antNumber] -= 1;}
            break;
    }

    heading[antNumber] = makeHeading( *heading, handling); // zmieniamy kierunek poruszania
}
void antAlgorithm ( int* x, int* y, int antCounter, int* heading, int** board, int boardSize, int handlingLenght, char* handling) // funkcja odpowiadająca za cały algorytm mrówki
{
    int* activityTab = (int *)malloc(antCounter* sizeof(int)); // tablica odpowiadająca za aktywność mrówek (jeżeli mrówka wyjdzie za granicę planszy to ją wyłącza)
    for(int j=0;j<antCounter;j++)
    {
        activityTab[j] = 1;        // wszystkie mrówki aktywne na starcie
    }
    int active = 1; 			// zmienna odpowiadająca za wyłączania pętli przechodzenia gdy wszystkie mrówki będą miały status: nieaktywna(0) to wyłącza ją 
    int temporaryFieldInfo;    
    while(active) {
        for (int i = 0; i < antCounter; i++) { // iteracja po każdej z mrówek
            if (activityTab[i] == 1) {  // sprawdzamy czy mrówka jest aktywna
                temporaryFieldInfo =board[x[i]][y[i]];  // wczytujemy informację z pola
                moveAnt(x, y, heading, i, board[x[i]][y[i]], board, handlingLenght, handling[temporaryFieldInfo]); //przekazujemy do funkcji poruszającej
                activityTab[i] = acivityCheck( x[i], y[i], boardSize); //sprawdzamy czy mrówka nie wyszła poza planszę
                }
            }
        }
        active = checkActive( activityTab, antCounter); // sprawdzamy czy zostały jakieś aktywne mrówki 
    }
}
