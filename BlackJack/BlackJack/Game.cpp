#include "Game.h"

Game::Game()
	:m_currentPlayer(EPlayer::Player1),
	 m_currentState(EState::HoldCard)
{
	m_deck.InitiateDeck();
	m_deck.ShuffleDeck();
	InitiateGame();
}

IGamePtr IGame::Produce()
{
	return std::make_shared<Game>();
}

EPlayer Game::GetCurrentPlayer() const
{
	return m_currentPlayer;
}

EState Game::GetCurrentState() const
{
	return m_currentState;
}

Deck Game::GetDeck() const
{
	return m_deck;
}

std::vector<CardPtr> Game::GetCardsForPlayer(EPlayer player) const
{
	if (player == EPlayer::Player1)
	{
		return m_cardsPlayer1;
	}
	return m_cardsPlayer2;
}

int Game::TakeCard()
{
	//take card and add to vector cards
	if (m_currentPlayer == EPlayer::Player1)
	{
		m_cardsPlayer1.push_back(m_deck.GiveCard());
	}
	else
	{
		m_cardsPlayer2.push_back(m_deck.GiveCard());

	}
	SwitchPlayers();
	return CalculatePoints();
}

int Game::HoldCards()
{
	SwitchPlayers();
	return CalculatePoints();
}

void Game::InitiateGame()
{
	m_deck.ShuffleDeck();
	InitiateCards(EPlayer::Player1);
	InitiateCards(EPlayer::Player2);
}

void Game::ResetGame()
{
	m_deck.InitiateDeck();
	m_cardsPlayer1.clear();
	m_cardsPlayer2.clear();
}

void Game::InitiateCards(const EPlayer player)
{
	if (player == EPlayer::Player1)
	{
		m_cardsPlayer1.push_back(m_deck.GiveCard());
		m_cardsPlayer1.push_back(m_deck.GiveCard());
	}
	else
	{
		m_cardsPlayer2.push_back(m_deck.GiveCard());
		m_cardsPlayer2.push_back(m_deck.GiveCard());
	}
}

int Game::CalculatePoints()
{
	int points = 0;
	if (m_currentPlayer == EPlayer::Player1)
	{
		for (const auto& el : m_cardsPlayer2)
		{
			points += (int)el->GetValue();
		}
	}
	else
	{
		for (const auto& el : m_cardsPlayer1)
		{
			points += (int)el->GetValue();
		}
	}
	return points;
}

bool Game::CheckWin()
{
	if (CalculatePoints() > 21) //if player has more than 21 points
	{
		if (m_currentPlayer == EPlayer::Player1)
			m_currentState = EState::Player2Win;
		else
			m_currentState = EState:: Player1Win;
		return true;
	}
	else if (CalculatePoints() == 21) //if player reaches blackjack
	{
		if (m_currentPlayer == EPlayer::Player1)
			m_currentState = EState::Player1Win;
		else
			m_currentState = EState::Player2Win;
		return true;
	}
	return false;
}

void Game::SwitchPlayers()
{
	m_currentPlayer = EPlayer(1 - (int)m_currentPlayer);

}
