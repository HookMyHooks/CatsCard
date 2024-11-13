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

static EValue ConvertNumberToValue(ENumber number)
{
    switch (number) {
    case ENumber::A:
        return EValue::eleven;
    case ENumber::ten:
    case ENumber::J:
    case ENumber::Q:
    case ENumber::K:
        return EValue::ten;
    default:

        return static_cast<EValue>(number);
    }
}

