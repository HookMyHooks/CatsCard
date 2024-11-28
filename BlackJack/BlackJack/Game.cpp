#include "Game.h"

Game::Game()
	:m_currentPlayer(EPlayer::Player1),
	 m_currentState(EState::InProgress),
	 m_player1Hold(false),
	 m_player2Hold(false)
{
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

Cards Game::GetCardsForPlayer(EPlayer player) const
{
	return player == EPlayer::Player1 ? m_cardsPlayer1 : m_cardsPlayer2;
}

int Game::GetPointsForPlayer(EPlayer player) const
{
	return CalculatePoints(m_currentPlayer);
}

void Game::AddListener(IGameListener* listener)
{
	m_Listeners.emplace_back(listener);
}

void Game::RemoveListener(IGameListener* listener)
{
	auto func = [listener](IGameListener* el)
		{
			return el == listener;
		};

	m_Listeners.erase(std::remove_if(m_Listeners.begin(), m_Listeners.end(), func));
}

void Game::TakeCard()
{
	if (m_currentPlayer == EPlayer::Player1)
	{
		m_cardsPlayer1.push_back(m_deck.GiveCard());
	}
	else
	{
		m_cardsPlayer2.push_back(m_deck.GiveCard());
	}

	NotifyListenersOnTakeCard();

	CheckWin();
	SwitchPlayers();
}

void Game::HoldCards()
{
	if (m_currentPlayer == EPlayer::Player1)
	{
		m_player1Hold = true;
	}
	else
	{
		m_player2Hold = true;
	}

	if (m_player1Hold && m_player2Hold)
	{
		CheckWin();
	}

	SwitchPlayers();
}

void Game::InitiateGame()
{
	m_deck.ShuffleDeck();
	InitiateCards(EPlayer::Player1);
	InitiateCards(EPlayer::Player2);
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

int Game::CalculatePoints(EPlayer player) const
{
	int points = 0;
	bool hasAce = false;

	const auto& playerCards = (player == EPlayer::Player1) ? m_cardsPlayer1 : m_cardsPlayer2;

	for (const auto& card : playerCards)
	{
		points += static_cast<int>(card->GetValue());
		if (card->GetNumber() == ENumber::A)
		{
			hasAce = true;
		}
	}
	if (hasAce && points + 10 <= 21)
	{
		points += 10;
	}

	return points;
}

void Game::NotifyListenersOnWin(int pointsPlayer1,int pointsPlayer2) const
{
	for (auto it : m_Listeners)
	{
		it->OnWin(pointsPlayer1,pointsPlayer2);
	}
}

void Game::NotifyListenersOnTakeCard() const
{
	for (auto it : m_Listeners)
	{
		it->OnTakeCard(m_currentPlayer);
	}
}

bool Game::CheckWin()
{
	int player1Points = CalculatePoints(EPlayer::Player1);
	int player2Points = CalculatePoints(EPlayer::Player2);

	if (m_player1Hold && m_player2Hold)
	{
		if (player1Points == player2Points)
		{
			m_currentState = EState::Draw;
		}
		else if (player1Points > player2Points)
		{
			m_currentState = EState::Player1Win;
		}
		else
		{
			m_currentState = EState::Player2Win;
		}
		NotifyListenersOnWin(player1Points, player2Points);
		return true;
	}

	int currentPlayerPoints = m_currentPlayer==EPlayer::Player1? player1Points:player2Points;

	if (currentPlayerPoints < 21)
	{
		return false;
	}
	else if (currentPlayerPoints > 21)
	{
		m_currentState = (m_currentPlayer == EPlayer::Player1) ? EState::Player2Win : EState::Player1Win;
	}
	else if (currentPlayerPoints == 21)
	{
		m_currentState = (m_currentPlayer == EPlayer::Player1) ? EState::Player1Win : EState::Player2Win;
		
	}
	NotifyListenersOnWin(player1Points, player2Points);
	return true;
}

void Game::SwitchPlayers()
{
	m_currentPlayer = EPlayer(1 - (int)m_currentPlayer);
}

bool Game::GetPlayerHold(EPlayer& player) const
{
	return player == EPlayer::Player1 ? m_player1Hold: m_player2Hold;
}
