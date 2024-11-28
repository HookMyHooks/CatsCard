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
	Cards GetCardsForPlayer(EPlayer player)const override;
	int GetPointsForPlayer(EPlayer player)const override;
	void AddListener(IGameListener* listener) override;
	void RemoveListener(IGameListener* listener) override;

	void TakeCard() override;
	void HoldCards() override;
	void SwitchPlayers();


private:
	void ResetGame();

	void InitiateGame();
	void InitiateCards(const EPlayer player);

	bool CheckWin();
	int CalculatePoints(EPlayer player) const;

	//Notify Listeners
	void NotifyListenersOnWin(int pointsPlayer1,int pointsPlayer2) const;
	void NotifyListenersOnTakeCard() const;
	
private:

	Deck m_deck;
	Cards m_cardsPlayer1;
	Cards m_cardsPlayer2;
	GameListenerList m_Listeners;
	EPlayer m_currentPlayer;
	EState m_currentState;
	bool m_player1Hold; 
	bool m_player2Hold;
};
