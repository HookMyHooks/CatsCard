#pragma once
#include "EValue.h"
#include "ENumber.h"
#include <iostream>
#include <memory>
#include<sstream>
#include <vector>

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
using Cards = std::vector<CardPtr>;

static EValue ConvertNumberToValue(ENumber number)
{
	switch (number) {
	case ENumber::A:
		return EValue::one; 
	case ENumber::ten:
	case ENumber::J:
	case ENumber::Q:
	case ENumber::K:
		return EValue::ten;
	default:

		return static_cast<EValue>(number);
	}
}

static std::string ConvertNumberToString(ENumber number)
{
	switch (number)
	{
	case ENumber::A:
		return "A";
	case ENumber::J:
		return "J";
	case ENumber::Q:
		return "Q";
	case ENumber::K:
		return "K";
	default:
		std::ostringstream oss;
		oss << static_cast<int>(number);
		return oss.str();

	}
}