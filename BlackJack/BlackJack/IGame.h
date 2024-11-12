#pragma once
#include "EState.h"
#include "EPlayer.h"

class IGame {

	virtual ~IGame() = default;

	virtual EPlayer GetCurrentPlayer()const=0;
	virtual EState GetCurrentState()const=0;

	virtual void TakeCard() = 0;
	virtual void HoldCards() = 0;
};