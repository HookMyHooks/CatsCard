#include <iostream>
#include "Deck.h"
#include "IGame.h"
#include <typeinfo>
int main()
{/*
	Card card (EValue::eight, ENumber::seven);
	ENumber value = card.GetNumber();
	std::cout << (int)value;*/

	/*Deck* deck=new Deck();
	int count = 1;

	for (auto& el : deck->GetCards())
	{
		ENumber number = el->GetNumber();
		EValue value = el->GetValue();

		std::cout << "Count: " << count << " with value: " << (int)value << " and Number: " << (int)number << std::endl;
		count++;
	}*/

	auto game = IGame::Produce();
	std::cout << typeid(game).name() << std::endl;
	int points=0; //added initialization here -> else if first player holds, error 
	std::cout << "Round starts: \n";
	std::cout << "Player" << game->GetCurrentPlayer() + 1 <<" your cards are: \n";
	std::vector<CardPtr>cards = game->GetCardsForPlayer(game->GetCurrentPlayer());
	for (auto el : cards)
	{
		//removed the Value print because it's unecesarry in console (we only need number, untill player takes an Ace, then promt the value pick)
		//also bug with cards generating with different number and value
		//std::cout << (int)el->GetNumber() << " " << (int)el->GetValue() << std::endl;
		std::cout << (int)el->GetNumber() << std::endl;
	}
	std::cout << "Choose on option: Take Card (1) or HoldCards(2)\n";
	int option;
	std::cin >> option;
	if (option == 1)
	{
		 points=game->TakeCard();
		std::cout << "Player"<< game->GetCurrentPlayer() +1 << " your cards are: \n";
		//why are we printing the other player's cards here?
		std::vector<CardPtr>cards = game->GetCardsForPlayer((EPlayer)(1-(int)game->GetCurrentPlayer()));
		for (auto el : cards)
		{
			//std::cout << (int)el->GetNumber() << " " << (int)el->GetValue() << std::endl;
			std::cout << (int)el->GetNumber() << std::endl;
		}
		std::cout << "Your current points are: " << points << "\n" << std::endl;
	}
	else if (option==0)
	{
		std::cout << "You choose to hold cards\n";
		points = game->HoldCards();
		std::cout << "Your current points are: " << points << "\n" << std::endl;

	}
	if (points > 21)
	{
		std::cout << "You lost!\n";
	}
	else
	{
		std::cout << game->GetCurrentPlayer() << " your cards are: \n";
		cards = game->GetCardsForPlayer(game->GetCurrentPlayer());
		for (auto el : cards)
		{
			std::cout << (int)el->GetNumber() << " " << (int)el->GetValue() << std::endl;
		}
		std::cout << "Choose on option: Take Card (1) or HoldCards(2)\n";

		std::cin >> option;
		if (option == 1)
		{
			points = game->TakeCard();
			std::cout << "Player" << game->GetCurrentPlayer() + 1 << " your cards are: \n";
			std::vector<CardPtr>cards = game->GetCardsForPlayer((EPlayer)(1 - (int)game->GetCurrentPlayer()));
			for (auto el : cards)
			{
				std::cout << (int)el->GetNumber() << " " << (int)el->GetValue() << std::endl;
			}
			std::cout << "Your current points are: " << points << std::endl;
			if (points > 21)
			{
				std::cout << "You lost!\n";
			}
		}
		else if (option == 0)
		{
			std::cout << "You choose to hold cards\n";
			points = game->TakeCard();
			std::cout << "Your current points are: " << points << std::endl;

		}
	}
	return 0;
}