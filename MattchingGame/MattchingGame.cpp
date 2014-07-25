// ============================================================================
// File: MattchingGame.cpp
// ============================================================================
// Program:		Matching Game program
// Description:	This is a matching game where the user attempts to match the 
//				various different cards in the user interface.
// Developer:	Matt Dohlen
// Created:		07/22/2014
// Last update: 07/22/2014
// ============================================================================

#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "windows.h"
using namespace std;
#include "card.h"

// ============================================================================
// Prototypes and Constanst
// ============================================================================

//void InitialDraw();
const int NUM_CARDS = 16;

// ==== main ==================================================================
//
// ============================================================================

int	main(void)
{
	Card cardArray[NUM_CARDS];
	int i;
	int random;
	HANDLE output = GetStdHandle(STD_OUTPUT_HANDLE);

	srand(time(NULL));

	//for(i = 0; i < NUM_CARDS / 2; ++i)
	//{
	//	//Lots of collisions
	//	do {
	//		random = rand() % NUM_CARDS;
	//	} while(cardArray[random].GetRand());
	//	cardArray[random].SetVal(i);
	//	cardArray[random].SetRand();
	//	do {
	//		random = rand() % NUM_CARDS;
	//	} while(cardArray[random].GetRand());
	//	cardArray[random].SetVal(i);
	//	cardArray[random].SetRand();
	//}
	cout << 1;
	cardArray[0].SetCoord(0,0);
	cardArray[0].DrawFaceDown(output);
	//InitialDraw();
	cout << 1;


}