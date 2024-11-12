#pragma once
#include "EValue.h"
#include "ENumber.h"

class ICard
{
public:
	virtual EValue GetValue() const = 0;
	virtual ENumber GetNumber() const = 0;
	virtual ~ICard() = default;
};

