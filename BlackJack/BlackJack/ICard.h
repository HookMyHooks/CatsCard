#pragma once
#include "EValue.h"
#include "ENumber.h"

#include <memory>

class ICard
{
public:

	virtual EValue GetValue() const = 0;
	virtual ENumber GetNumber() const = 0;

	virtual ~ICard() = default;
};

using ICardPtr = std::shared_ptr<ICard>;

