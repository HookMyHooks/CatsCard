#pragma once
#include "EValue.h"
#include "ENumber.h"
#include "ICard.h"
class Card : public ICard
{

public:
	Card();
	Card(EValue value, ENumber number);
	
	//ICard methods
	EValue GetValue() const override;
	ENumber GetNumber() const override;

	~Card();

private:
	EValue m_value;
	ENumber m_number;
};

