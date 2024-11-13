#pragma once

#include "IGame.h"
#include "Deck.h"

#include <vector>

class Game : public IGame 
{
public:

	Game();
	// IGame methods
	EPlayer GetCurrentPlayer() const override;
	EState GetCurrentState() const override;

	void TakeCard() override;
	void HoldCards() override;

	//other methods



private:
	void ResetGame();

	void InitiateGame();
	void InitiateCards(const EPlayer player);

	bool CheckWin();
	int CalculatePoints();

	void SwitchPlayers();

private:

	Deck m_deck;
	std::vector<ICardPtr>m_cardsPlayer1;
	std::vector<ICardPtr>m_cardsPlayer2;
	EPlayer m_currentPlayer;
	EState m_currentState;

};
