#include <iostream>
#include "Card.h"

int main()
{
	Card card (EValue::eight, ENumber::seven);
	ENumber value = card.GetNumber();
	std::cout << (int)value;
	return 0;
}