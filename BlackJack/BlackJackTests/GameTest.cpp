#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "Game.h"

//start game

TEST(StartGame, FirstPlayer) {
	Game game;
	EPlayer player = game.GetCurrentPlayer();
	ASSERT_EQ(player, EPlayer::Player1);
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

