#pragma once

#include "IGame.h"

#include <vector>

class Game : public IGame 
{
public:

	Game();
	// Inherited via IGame
	EPlayer GetCurrentPlayer() const override;
	EState GetCurrentState() const override;

	void TakeCard() override;
	void HoldCards() override;
private:
	void InitiateGame();
	void Reset();
	void InitiateCards(const EPlayer player);
	int CalculatePoints();
	bool CheckWin();
	void SwitchPlayers();

private:

	int m_deck;
	std::vector<int>m_cardsPlayer1;
	std::vector<int>m_cardsPlayer2;
	EPlayer m_currentPlayer;
	EState m_currentState;

};
