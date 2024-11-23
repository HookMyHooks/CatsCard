#include <gtest/gtest.h>

#include "Card.h"

TEST(CardValueGetter, isTrue) {
	Card card(EValue::eight, ENumber::eight);
	EValue value = card.GetValue();
	ASSERT_EQ(value, EValue::eight);
}

TEST(CardNumberGetter, isTrue) {
	Card card(EValue::four, ENumber::four);
	ENumber number = card.GetNumber();
	ASSERT_EQ(number, ENumber::four);
}