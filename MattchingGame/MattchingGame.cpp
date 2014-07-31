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

void InitialDraw(HANDLE out, Card* cards);
void RandomizeDeck(Card* cards);
void GameEngine(HANDLE out, Card* cards);
void FlushInstream(istream  &inStream = cin);
const int NUM_CARDS = 16;

// ==== main ==================================================================
//
// ============================================================================

int	main(void)
{
	Card cardDeck[NUM_CARDS];
	HANDLE output = GetStdHandle(STD_OUTPUT_HANDLE);

	RandomizeDeck(cardDeck);
	InitialDraw(output, cardDeck);
	GameEngine(output, cardDeck);

}

// ==== RandomizeDeck =========================================================
//
// This function randomly sets the value of each card in the deck
//
// Input:
//		cards	-- an array of cards
//
// Output:
//      Nothing.
//
// ============================================================================

void RandomizeDeck(Card* cards)
{
	int i;
	int random;

	srand(time(NULL));

	for(i = 0; i < NUM_CARDS / 2; ++i)
	{
		//Lots of collisions
		do {
			random = rand() % NUM_CARDS;
		} while(cards[random].GetRand());
		cards[random].SetVal(i);
		cards[random].SetRand();
		do {
			random = rand() % NUM_CARDS;
		} while(cards[random].GetRand());
		cards[random].SetVal(i);
		cards[random].SetRand();
	}

}  // end of "RandomizeDeck"

// ==== InitialDraw ===========================================================
//
// This function draws the initial game board and also sets the coordinates
// of each card
//
// Input:
//      out		-- handle to the current output console
//		cards	-- an array of cards
//
// Output:
//      Nothing.
//
// ============================================================================

void InitialDraw(HANDLE out, Card* cards)
{
	int i, j, count = 0;
	COORD pos;
	SMALL_RECT windowSize;
	
	windowSize.Top = 0;
	windowSize.Left = 0;
	windowSize.Right = 79;
	windowSize.Bottom = 36;
	SetConsoleWindowInfo(out, true, &windowSize);
	pos.X = 0;
	pos.Y = 3;

	cout << "Welcome to Matt's World Famous Mattching Game!" << endl
		 << "Match the cards to win the game...";
	for(i = 0; i < NUM_CARDS / 4; ++i)
	{
		for(j = 0; j < NUM_CARDS / 4; ++j)
		{
			SetConsoleCursorPosition(out, pos);
			cout << count + 1 << "->";
			cards[count].SetCoord(pos);
			cards[count].DrawFaceDown(out);
			pos.X += 19;
			++count;
		}
		pos.X = 0;
		pos.Y += 8;
		cout << endl;
	}
	cout << endl << "Enter your first card choice followed by your second "
		 << "card choice: ";

}  // end of "Initial Draw"


// ==== GameEngine ============================================================
//
// This function is the heart of the game. Most of the logic is found in this
// section of the code. The user is asked for two guesses to match a pattern
// on two cards. If they match the cards are left face up. Once all matches are
// found the program lets the user know how many valid guesses it took to
// complete the game.
//
// Input:
//      out		-- handle to the current output console
//		cards	-- an array of cards
//
// Output:
//      Nothing.
//
// ============================================================================

void GameEngine(HANDLE out, Card* cards)
{
	CONSOLE_SCREEN_BUFFER_INFO		bufferInfo;
	COORD	startLine;
	COORD	cursorPos;
	CONSOLE_CURSOR_INFO		visible, invisible;
	int		numMatches = 0, numGuesses = 0, guessOne, guessTwo;

	GetConsoleScreenBufferInfo(out, &bufferInfo);
	cursorPos = bufferInfo.dwCursorPosition;
	startLine.X = 0;
	startLine.Y = cursorPos.Y;
	GetConsoleCursorInfo(out, &visible);
	invisible = visible;
	invisible.bVisible = false;

	while(numMatches != NUM_CARDS / 2)
	{
		SetConsoleCursorPosition(out, startLine);
		cout << "Enter your first card choice followed by your second "
			 << "card choice: ";
		// Take in number of first guess and validate
		if(cin >> guessOne && guessOne <= 16 && guessOne >= 1 &&
		   !cards[guessOne - 1].GetMatch())
		{
			cards[guessOne - 1].Draw(out);
			SetConsoleCursorPosition(out, cursorPos);
			cout << "     ";
			SetConsoleCursorPosition(out, cursorPos);
			Sleep(1000);
			// Take in number of first guess and validate
			if(cin >> guessTwo && guessTwo <= 16 && guessTwo >= 1 &&
			   guessOne != guessTwo && !cards[guessTwo - 1].GetMatch())
			{
				cards[guessTwo - 1].Draw(out);
				SetConsoleCursorPosition(out, cursorPos);
				cout << "     ";
				SetConsoleCursorPosition(out, startLine);
				Sleep(1000);
				// Check if values are equal, if so leave cards visible and 
				// mark them as a match
				if(cards[guessOne - 1].GetVal() == cards[guessTwo - 1].GetVal())
				{
					cout << "You got a match!                              "
						 << "                           ";
					SetConsoleCursorInfo(out, &invisible);
					Sleep(2000);
					SetConsoleCursorInfo(out, &visible);
					cards[guessOne - 1].SetMatch();
					cards[guessTwo - 1].SetMatch();
					++numMatches;
					++numGuesses;
				}
				// If not, flip cards back over and restart process
				else
				{
					SetConsoleCursorPosition(out, startLine);
					cout << "Sorry, no match :(                             "
						 << "                             ";
					SetConsoleCursorInfo(out, &invisible);
					Sleep(2000);
					SetConsoleCursorInfo(out, &visible);
					++numGuesses;
					cards[guessOne - 1].DrawFaceDown(out);
					cards[guessTwo - 1].DrawFaceDown(out);
				}
			}
			// Invalid second choice
			else
			{
				SetConsoleCursorPosition(out, startLine);
				cout << "Invalid selection for card two, try again          "
					 << "                           ";
				cards[guessOne - 1].DrawFaceDown(out);
				SetConsoleCursorInfo(out, &invisible);
				Sleep(2000);
				SetConsoleCursorInfo(out, &visible);
			}
		}
		// Invalid first choice
		else
		{
			SetConsoleCursorPosition(out, startLine);
			cout << "Invalid selection for card one, try again          "
				 << "                           ";
			SetConsoleCursorInfo(out, &invisible);
			Sleep(2000);
			SetConsoleCursorInfo(out, &visible);
		}
		FlushInstream();
	}
	SetConsoleCursorPosition(out, startLine);
	cout << "Congratulations, you beat Matt's World Famous Mattching game in "
		 << numGuesses << " guesses!" << endl;
	system("pause");

}  // end of "GameEngine"

// ==== FlushInstream =========================================================
//
// This function clears the input buffer until a new line or eof is encountered
//
// Input:
//      inStream    -- a reference to the input stream to flush
//
// Output:
//      Nothing.
//
// ============================================================================

void    FlushInstream(istream  &inStream)
{
    char        inChar;

    inStream.clear();
    while (false == inStream.eof())
    {
        inStream.get(inChar);
        if ('\n' == inChar)
            {
            break;
            }
    }

}  // end of "FlushInstream"