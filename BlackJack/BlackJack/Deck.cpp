#include "Deck.h"
#include <algorithm>
#include <random>

Deck::Deck() 
{
	InitiateDeck();
	ShuffleDeck();
}

void Deck::InitiateDeck() {
	m_cards.clear();

	for (int suit = 0; suit < 4; ++suit) {
		for (int number = static_cast<int>(ENumber::A); number <= static_cast<int>(ENumber::K); ++number) {
			ENumber rank = static_cast<ENumber>(number);
			EValue value = ConvertNumberToValue(rank);
			m_cards.push_back(std::make_shared<ICard>(value, rank));
		}
	}
}

void Deck::ShuffleDeck() {
	std::random_device rd;
	std::mt19937 g(rd());
	std::shuffle(m_cards.begin(), m_cards.end(), g);
}

std::shared_ptr<ICard> Deck::GiveCard() {
	if (m_cards.empty()) {
		return nullptr;
	}
	std::shared_ptr<ICard> card = m_cards.back();
	m_cards.pop_back();
	return card;
}

