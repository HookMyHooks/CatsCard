#pragma once
#pragma once

#include <vector>

class IGameListener
{
public:
	
	
	virtual void OnWin() = 0;
	virtual void OnReset() = 0;

	virtual ~IGameListener() = default;

};

using GameListenerList = std::vector<IGameListener*>;