#include <iostream>
#include "Deck.h"
#include "IGame.h"

int main()
{/*
	Card card (EValue::eight, ENumber::seven);
	ENumber value = card.GetNumber();
	std::cout << (int)value;*/

	Deck* deck=new Deck();
	int count = 1;

	for (auto& el : deck->GetCards())
	{
		ENumber number = el->GetNumber();
		EValue value = el->GetValue();

		std::cout << "Count: " << count << " with value: " << (int)value << " and Number: " << (int)number << std::endl;
		count++;
	}

	/*auto game = IGame::Produce();
	int count = 1;

	for (auto& el : game->GetDeck())
	{
		ENumber number = el->GetNumber();
		EValue value = el->GetValue();

		std::cout << "Count: " << count << " with value: " << (int)value << " and Number: " << (int)number << std::endl;
		count++;
	}*/

	return 0;
}