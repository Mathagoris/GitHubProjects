// ============================================================================
// File: card.h
// ============================================================================
// Description: This is the header file for the card class used in the
//				Matching Game program
// Developer:	Matt Dohlen
// Created:		07/22/2014
// Last update: 07/22/2014
// ============================================================================

#ifndef CARD_H
#define CARD_H

class Card
{
public:
	//Constructors and destructors
	Card() : mMatch(false) {}
	~Card() {}

	//Member functions
	void	DrawFaceDown();
	void	Draw();
	int		GetVal() const {return mValue;}
	void	SetMatch() {mMatch = true;}
	void	SetCoord(int x, int y) { mPosition.x = x; mPosition.y = y;}
private:
	int		mValue;
	bool	mMatch;
	COORD	mPosition;
};
#endif //CARD_H

