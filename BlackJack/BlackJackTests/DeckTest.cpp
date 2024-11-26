#include <gtest/gtest.h>

#include "Deck.h"

TEST(DeckSize, isTrue) {
    Deck deck;
	int size = deck.GetCards().size();
	ASSERT_EQ(size, 52);
}

TEST(DeckStructure, isTrue) {
    Deck deck;
	std::vector<std::shared_ptr<Card>> cards = deck.GetCards();
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
	Deck deck;
	std::shared_ptr<Card> card = deck.GiveCard();
	int size = deck.GetCards().size();
	ASSERT_EQ(size, 51);
}


TEST(ShuffleDeckCheck, isTrue) {
    Deck deck;
    std::vector<std::shared_ptr<Card>> originalOrder = deck.GetCards();

    deck.ShuffleDeck();
    std::vector<std::shared_ptr<Card>> shuffledOrder = deck.GetCards();

    bool isDifferent = false;
    for (int i = 0; i < originalOrder.size(); ++i) {
        if (originalOrder[i] != shuffledOrder[i]) {
            isDifferent = true;
            break;
        }
    }
    ASSERT_TRUE(isDifferent);
}

TEST(GiveCardCheck, EmptyDeck) {
    Deck deck;
    for (int i = 0; i < 52; ++i) {
        std::shared_ptr<Card> card = deck.GiveCard();
        ASSERT_NE(card, nullptr); 
    }

    std::shared_ptr<Card> emptyCard = deck.GiveCard();
    ASSERT_EQ(emptyCard, nullptr);
}

