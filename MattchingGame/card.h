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
	Card() : mMatch(false), mRandomized(true) {}
	~Card() {}

	//Member functions
	void	DrawFaceDown(HANDLE out);
	void	Draw(HANDLE out);
	int		GetVal() const {return mValue;}
	bool	GetMatch() const {return mMatch;}
	bool	GetRand() const {return mRandomized;}
	void	SetVal(int val) {mValue = val;}
	void	SetMatch() {mMatch = true;}
	void	SetRand() {mRandomized = true;}
	void	SetCoord(int x, int y) { mPosition.X = x; mPosition.Y = y;}
private:
	int		mValue;
	bool	mMatch;
	bool	mRandomized;
	COORD	mPosition;
};
#endif //CARD_H

