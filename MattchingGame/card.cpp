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
using namespace std;
#include "card.h"

void Card::DrawFaceDown()
{
	cout << "------------" << endl
		 << "|          |" << endl
		 << "|          |" << endl
		 << "|          |" << endl
		 << "|          |" << endl
		 << "|          |" << endl
		 << "------------";
}

void Card::Draw()
{
	if(mValue == 0)
	{
			cout << "------------" << endl
				 << "|  ******  |" << endl
				 << "|  *    *  |" << endl
				 << "|  *    *  |" << endl
				 << "|  *    *  |" << endl
				 << "|  ******  |" << endl
				 << "------------";
	}
	else if(mValue == 1)
	{
			cout << "------------" << endl
				 << "|          |" << endl
				 << "|   @  @   |" << endl
				 << "|          |" << endl
				 << "| \______/ |" << endl
				 << "|          |" << endl
				 << "------------";
	}
	else if(mValue == 2)
	{
			cout << "------------" << endl
				 << "|  ______  |" << endl
				 << "| /      \ |" << endl
				 << "|          |" << endl
				 << "| \______/ |" << endl
				 << "|          |" << endl
				 << "------------";
	}
	else if(mValue == 3)
	{
			cout << "------------" << endl
				 << "|  ______  |" << endl
				 << "| /      \ |" << endl
				 << "|          |" << endl
				 << "|   @  @   |" << endl
				 << "|          |" << endl
				 << "------------";
	}
	else if(mValue == 4)
	{
			cout << "------------" << endl
				 << "|          |" << endl
				 << "|  OOOOOO  |" << endl
				 << "|  OOOOOO  |" << endl
				 << "|  OOOOOO  |" << endl
				 << "|          |" << endl
				 << "------------";
	}
	else if(mValue == 5)
	{
			cout << "------------" << endl
			   	 << "| #      # |" << endl
				 << "|  #    #  |" << endl
				 << "|    ##    |" << endl
				 << "|  #    #  |" << endl
				 << "| #      # |" << endl
				 << "------------";
	}
	else if(mValue == 6)
	{
			cout << "------------" << endl
				 << "|          |" << endl
				 << "| /\    /\ |" << endl
				 << "|  ______  |" << endl
				 << "|  \____/  |" << endl
				 << "|          |" << endl
				 << "------------";
	}
	else
	{
			cout << "------------" << endl
				 << "| ######## |" << endl
				 << "|  #    #  |" << endl
				 << "|    ##    |" << endl
				 << "|  #    #  |" << endl
				 << "| ######## |" << endl
				 << "------------";
	}
}