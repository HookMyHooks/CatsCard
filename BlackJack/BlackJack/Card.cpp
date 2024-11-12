#include "Card.h"

Card::Card()
	:m_value(EValue::one),
	 m_number(ENumber::A)
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
EValue Card::ConvertNumberToValue(ENumber number)
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

Card::~Card()
{
	//empty
}
