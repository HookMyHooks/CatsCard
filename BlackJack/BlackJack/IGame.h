#pragma once
#include "EState.h"
#include "EPlayer.h"
#include "Deck.h"
#include "memory"

using IGamePtr = std::shared_ptr<class IGame>;

class IGame 
{
public:
	virtual EPlayer GetCurrentPlayer()const=0;
	virtual EState GetCurrentState()const=0;
	virtual Deck GetDeck()const=0;

	virtual void TakeCard() = 0;
	virtual void HoldCards() = 0;

	static IGamePtr Produce();
	virtual ~IGame() = default;
};