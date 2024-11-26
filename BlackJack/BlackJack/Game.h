#pragma once

#include "IGame.h"

#include "Card.h"
#include"Deck.h"
#include <vector>

class Game : public IGame 
{
public:

	Game();
	// IGame methods
	EPlayer GetCurrentPlayer() const override;
	EState GetCurrentState() const override;
	Deck GetDeck() const override;
	std::vector<CardPtr> GetCardsForPlayer(EPlayer player)const override;
	//void SetCardsForPlayer(std::vector <CardPtr>, EPlayer player ) override;
	
	 void AddListener(IGameListener* listener) override;
	 void RemoveListener(IGameListener* listener) override;

	int TakeCard() override;
	int HoldCards() override;
	void SwitchPlayers();

	//other methods



private:
	void ResetGame();

	void InitiateGame();
	void InitiateCards(const EPlayer player);

	bool CheckWin();
	int CalculatePoints(EPlayer player);

	

private:

	Deck m_deck;
	std::vector<CardPtr>m_cardsPlayer1;
	std::vector<CardPtr>m_cardsPlayer2;
	GameListenerList m_Listeners;
	EPlayer m_currentPlayer;
	EState m_currentState;
	bool m_player1Hold; 
	bool m_player2Hold;

};
