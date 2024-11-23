#include <gtest/gtest.h>

#include "Deck.h"

TEST(DeckSize, isTrue) {
	Deck* deck = new Deck();
	int size = deck->GetCards().size();
	ASSERT_EQ(size, 52);
}

TEST(DeckStructure, isTrue) {
	Deck* deck = new Deck();
	std::vector<std::shared_ptr<Card>> cards = deck->GetCards();
    std::map<std::pair<ENumber, EValue>, int> cardCount;

    for (auto& card : cards) {
        std::pair<ENumber, EValue> cardKey = { card->GetNumber(), card->GetValue() };
        cardCount[cardKey]++;
    }

    for (int rank = static_cast<int>(ENumber::A);
        rank <= static_cast<int>(ENumber::K);
        ++rank) {
        ENumber rankEnum = static_cast<ENumber>(rank);
        EValue value = ConvertNumberToValue(rankEnum);

        std::pair<ENumber, EValue> expectedCard = { rankEnum, value };
        ASSERT_EQ(cardCount[expectedCard], 4);
    }
}

TEST(GiveCard, isTrue) {
	Deck* deck = new Deck();
	std::shared_ptr<Card> card = deck->GiveCard();
	int size = deck->GetCards().size();
	ASSERT_EQ(size, 51);
}