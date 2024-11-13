#pragma once
#include "EValue.h"
#include "ENumber.h"

#include <memory>

class Card 
{

public:

	Card();
	Card(EValue value, ENumber number);
	
	//ICard methods
	EValue GetValue() const ;
	ENumber GetNumber() const ;
	

	~Card();

private:
	EValue m_value;
	ENumber m_number;
};

using CardPtr = std::shared_ptr<Card>;

static EValue ConvertNumberToValue(ENumber number)
{
	switch (number) {
	case ENumber::A:
		return EValue::eleven; //or 1 depending on the player
	case ENumber::ten:
	case ENumber::J:
	case ENumber::Q:
	case ENumber::K:
		return EValue::ten;
	default:

		return static_cast<EValue>(number);
	}
}