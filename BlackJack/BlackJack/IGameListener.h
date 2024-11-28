#pragma once

#include <vector>

class IGameListener
{
public:
	
	virtual void OnWin(int finalPointsPlayer1, int finalPointsPlayer2) = 0;
	virtual void OnTakeCard(const EPlayer& player) = 0;

	virtual ~IGameListener() = default;

};

using GameListenerList = std::vector<IGameListener*>;