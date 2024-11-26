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

TEST(ConvertNumberToValue, CorrectValues) {
	EXPECT_EQ(ConvertNumberToValue(ENumber::ten), EValue::ten);
	EXPECT_EQ(ConvertNumberToValue(ENumber::Q), EValue::ten);
	EXPECT_EQ(ConvertNumberToValue(ENumber::three), EValue::three);
	EXPECT_EQ(ConvertNumberToValue(ENumber::eight), EValue::eight);
}
TEST(ConvertNumberToString, CorrectStrings) {
	EXPECT_EQ(ConvertNumberToString(ENumber::A), "A");
	EXPECT_EQ(ConvertNumberToString(ENumber::J), "J");;
	EXPECT_EQ(ConvertNumberToString(ENumber::two), "2");
	EXPECT_EQ(ConvertNumberToString(ENumber::ten), "10");
}