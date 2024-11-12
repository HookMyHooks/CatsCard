#include "Card.h"

Card::Card()
	:m_value(EValue::one),
	 m_number(ENumber::one)
{
	//empty
}

Card::Card(EValue value, ENumber number)
	:m_value(value),
	 m_number(number)
{
	//empty
}

EValue Card::GetValue() const
{
	return m_value;
}

ENumber Card::GetNumber() const
{
	return m_number;
}

Card::~Card()
{
	//empty
}
