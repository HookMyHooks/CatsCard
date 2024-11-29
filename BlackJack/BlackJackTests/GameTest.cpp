#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "Game.h"

//start game

class MockListenerGame :public IGameListener
{
public:

	MOCK_METHOD(void, OnWin, (int finalPointsPlayer1, int finalPointsPlayer2), (override));
	MOCK_METHOD(void, OnTakeCard, (const EPlayer& player), (override));
};

TEST(GameTest, Player1TakeCardsListenerNotifies) {
	Game game;
	MockListenerGame listener;
	game.AddListener(&listener);
	EXPECT_CALL(listener, OnTakeCard(EPlayer::Player1)).Times(1);
	game.TakeCard();

}
TEST(GameTest, Player2TakeCardsListenerNotifies) {
	Game game;
	MockListenerGame listener;
	game.AddListener(&listener);
	game.TakeCard();
	EXPECT_CALL(listener, OnTakeCard(EPlayer::Player2)).Times(1);
	game.TakeCard();
}

TEST(GameTest, PlayersTakeCardsListenerNotifies) {
	Game game;
	MockListenerGame listener;
	game.AddListener(&listener);
	EXPECT_CALL(listener, OnTakeCard(EPlayer::Player1)).Times(1);
	game.TakeCard();
	EXPECT_CALL(listener, OnTakeCard(EPlayer::Player2)).Times(1);
	game.TakeCard();
}

TEST(GameTest, NotifyOnWin) {
	Game game;
	MockListenerGame listener;

	game.AddListener(&listener);

	EXPECT_CALL(listener, OnWin(testing::_, testing::_)).Times(1);

	game.HoldCards();
	game.HoldCards();

	ASSERT_TRUE(game.GetCurrentState() == EState::Player1Win ||
		game.GetCurrentState() == EState::Player2Win ||
		game.GetCurrentState() == EState::Draw);
}

TEST(StartGame, FirstPlayer) {
	Game game;
	EPlayer player = game.GetCurrentPlayer();
	ASSERT_EQ(player, EPlayer::Player1);
}

TEST(StartGame, SecondPlayer) {
	Game game;
	game.HoldCards();
	EPlayer player = game.GetCurrentPlayer();
	ASSERT_EQ(player, EPlayer::Player2);
}

//player switch done correctly
TEST(PlayerSwitch, isTrue) {
	Game game;
	game.TakeCard();
	EPlayer player = game.GetCurrentPlayer();
	ASSERT_EQ(player, EPlayer::Player2);
}

//game ends on blackjack (exactly 21 points)

//game ends if player has more than 21 points (idk how to test random picks from a deck)
//TEST(GameEnd, Player1WinsOnBlackjack) {
//	Game game;
//
//	ASSERT_EQ(game.GetCurrentState(), EState::HoldCard);
//
//	while (true) {
//		int points = game.TakeCard();
//		if (points == 21) {
//			break;
//		}
//		else if (points > 21) {
//			FAIL() << "Player 1 exceeded 21 points while testing. Points obtained: "<< points;
//		}
//	}
//	ASSERT_EQ(game.GetCurrentState(), EState::Player1Win);
//}

//if player 1 takes cards, that card is put in his deck not the other player's
TEST(PlayerTake, isTrue) {
	Game game;
	game.TakeCard();
	int deckSizePlayer1 = game.GetCardsForPlayer(EPlayer::Player1).size();
	int deckSizePlayer2 = game.GetCardsForPlayer(EPlayer::Player2).size();
	ASSERT_EQ(deckSizePlayer1, 3);
	ASSERT_EQ(deckSizePlayer2, 2);
}

TEST(PlayerHold, Player1Holds) {
	Game game;
	game.HoldCards();
	ASSERT_TRUE(game.GetCurrentState() == EState::InProgress);

	game.HoldCards();
	ASSERT_TRUE(game.GetCurrentState() == EState::Player1Win || game.GetCurrentState() == EState::Player2Win || game.GetCurrentState() == EState::Draw);
}

TEST(GameTest, GameStatus) {
	Game game;

	game.HoldCards();
	ASSERT_EQ(game.GetCurrentState(), EState::InProgress);

	game.HoldCards();
	ASSERT_TRUE(game.GetCurrentState() == EState::Player1Win ||
		game.GetCurrentState() == EState::Player2Win ||
		game.GetCurrentState() == EState::Draw);
}