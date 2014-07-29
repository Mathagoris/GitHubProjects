// ============================================================================
// File: card.cpp
// ============================================================================
// Description: This is the implementaion of the card class used in the
//				Matching Game program
// Developer:	Matt Dohlen
// Created:		07/22/2014
// Last update: 07/22/2014
// ============================================================================

#include <iostream>
#include "windows.h"
using namespace std;
#include "card.h"

void Card::DrawFaceDown(HANDLE out)
{
	COORD pos = mPosition;
	pos.X += 4;
	SetConsoleCursorPosition(out, pos);
	cout << " ------------";
	pos.X -= 4;
	++pos.Y;
	SetConsoleCursorPosition(out, pos);
	cout << "     |          |";
	++pos.Y;
	SetConsoleCursorPosition(out, pos);
	cout << "     |          |";
	++pos.Y;
	SetConsoleCursorPosition(out, pos);
	cout << "     |          |";
	++pos.Y;
	SetConsoleCursorPosition(out, pos);
	cout << "     |          |";
	++pos.Y;
	SetConsoleCursorPosition(out, pos);
	cout << "     |          |";
	++pos.Y;
	SetConsoleCursorPosition(out, pos);
	cout << "     ------------";
}

void Card::Draw(HANDLE out)
{
	COORD pos = mPosition;
	pos.X += 4;
	SetConsoleCursorPosition(out, pos);
	if(mValue == 0)
	{
			cout << " ------------";
			pos.X -= 4;
			++pos.Y;
			SetConsoleCursorPosition(out, pos);
			cout << "     |  ******  |";
			++pos.Y;
			SetConsoleCursorPosition(out, pos);
			cout << "     |  *    *  |";
			++pos.Y;
			SetConsoleCursorPosition(out, pos);
			cout << "     |  *    *  |";
			++pos.Y;
			SetConsoleCursorPosition(out, pos);
			cout << "     |  *    *  |";
			++pos.Y;
			SetConsoleCursorPosition(out, pos);
			cout << "     |  ******  |";
			++pos.Y;
			SetConsoleCursorPosition(out, pos);
			cout << "     ------------";
	}
	else if(mValue == 1)
	{
			cout << " ------------";
			pos.X -= 4;
			++pos.Y;
			SetConsoleCursorPosition(out, pos);
			cout << "     |          |";
			++pos.Y;
			SetConsoleCursorPosition(out, pos);
			cout << "     |   @  @   |";
			++pos.Y;
			SetConsoleCursorPosition(out, pos);
			cout << "     |          |";
			++pos.Y;
			SetConsoleCursorPosition(out, pos);
			cout << "     | \\______/ |";
			++pos.Y;
			SetConsoleCursorPosition(out, pos);
			cout << "     |          |";
			++pos.Y;
			SetConsoleCursorPosition(out, pos);
			cout << "     ------------";
	}
	else if(mValue == 2)
	{
			cout << " ------------";
			pos.X -= 4;
			++pos.Y;
			SetConsoleCursorPosition(out, pos);
			cout << "     |  ______  |";
			++pos.Y;
			SetConsoleCursorPosition(out, pos);
			cout << "     | /      \\ |";
			++pos.Y;
			SetConsoleCursorPosition(out, pos);
			cout << "     |          |";
			++pos.Y;
			SetConsoleCursorPosition(out, pos);
			cout << "     | \\______/ |";
			++pos.Y;
			SetConsoleCursorPosition(out, pos);
			cout << "     |          |";
			++pos.Y;
			SetConsoleCursorPosition(out, pos);
			cout << "     ------------";
	}
	else if(mValue == 3)
	{
			cout << " ------------";
			pos.X -= 4;
			++pos.Y;
			SetConsoleCursorPosition(out, pos);
			cout << "     |  ______  |";
			++pos.Y;
			SetConsoleCursorPosition(out, pos);
			cout << "     | /      \\ |";
			++pos.Y;
			SetConsoleCursorPosition(out, pos);
			cout << "     |          |";
			++pos.Y;
			SetConsoleCursorPosition(out, pos);
			cout << "     |   @  @   |";
			++pos.Y;
			SetConsoleCursorPosition(out, pos);
			cout << "     |          |";
			++pos.Y;
			SetConsoleCursorPosition(out, pos);
			cout << "     ------------";

	}
	else if(mValue == 4)
	{
			cout << " ------------";
			pos.X -= 4;
			++pos.Y;
			SetConsoleCursorPosition(out, pos);
			cout << "     |          |";
			++pos.Y;
			SetConsoleCursorPosition(out, pos);
			cout << "     |  OOOOOO  |";
			++pos.Y;
			SetConsoleCursorPosition(out, pos);
			cout << "     |  OOOOOO  |";
			++pos.Y;
			SetConsoleCursorPosition(out, pos);
			cout << "     |  OOOOOO  |";
			++pos.Y;
			SetConsoleCursorPosition(out, pos);
			cout << "     |          |";
			++pos.Y;
			SetConsoleCursorPosition(out, pos);
			cout << "     ------------";

	}
	else if(mValue == 5)
	{
			cout << " ------------";
			pos.X -= 4;
			++pos.Y;
			SetConsoleCursorPosition(out, pos);
			cout << "     | #      # |";
			++pos.Y;
			SetConsoleCursorPosition(out, pos);
			cout << "     |  #    #  |";
			++pos.Y;
			SetConsoleCursorPosition(out, pos);
			cout << "     |    ##    |";
			++pos.Y;
			SetConsoleCursorPosition(out, pos);
			cout << "     |  #    #  |";
			++pos.Y;
			SetConsoleCursorPosition(out, pos);
			cout << "     | #      # |";
			++pos.Y;
			SetConsoleCursorPosition(out, pos);
			cout << "     ------------";

	}
	else if(mValue == 6)
	{
			cout << " ------------";
			pos.X -= 4;
			++pos.Y;
			SetConsoleCursorPosition(out, pos);
			cout << "     |          |";
			++pos.Y;
			SetConsoleCursorPosition(out, pos);
			cout << "     | /\\    /\\ |";
			++pos.Y;
			SetConsoleCursorPosition(out, pos);
			cout << "     |  ______  |";
			++pos.Y;
			SetConsoleCursorPosition(out, pos);
			cout << "     |  \\____/  |";
			++pos.Y;
			SetConsoleCursorPosition(out, pos);
			cout << "     |          |";
			++pos.Y;
			SetConsoleCursorPosition(out, pos);
			cout << "     ------------";

	}
	else
	{
			cout << " ------------";
			pos.X -= 4;
			++pos.Y;
			SetConsoleCursorPosition(out, pos);
			cout << "     | ######## |";
			++pos.Y;
			SetConsoleCursorPosition(out, pos);
			cout << "     |  #    #  |";
			++pos.Y;
			SetConsoleCursorPosition(out, pos);
			cout << "     |    ##    |";
			++pos.Y;
			SetConsoleCursorPosition(out, pos);
			cout << "     |  #    #  |";
			++pos.Y;
			SetConsoleCursorPosition(out, pos);
			cout << "     | ######## |";
			++pos.Y;
			SetConsoleCursorPosition(out, pos);
			cout << "     ------------";

	}
}