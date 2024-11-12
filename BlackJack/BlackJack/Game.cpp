#include "Game.h"

Game::Game()
	:m_currentPlayer(EPlayer::Player1),
	 m_currentState(EState::HoldCard)
{
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

void Game::TakeCard()
{
	//take card and add to vector cards
	SwitchPlayers();
}

void Game::HoldCards()
{
	SwitchPlayers();
}

void Game::InitiateGame()
{
	//shuffle Deck
	InitiateCards(EPlayer::Player1);
	InitiateCards(EPlayer::Player2);
}

void Game::ResetGame()
{
	//deck reinitializat and shuffle
	m_cardsPlayer1.clear();
	m_cardsPlayer2.clear();
}

void Game::InitiateCards(const EPlayer player)
{
}

int Game::CalculatePoints()
{
	return 0;
}

bool Game::CheckWin()
{
	if (CalculatePoints() > 21)
	{
		if (m_currentPlayer == EPlayer::Player1)
			m_currentState = EState::Player2Win;
		else
			m_currentState = EState:: Player1Win;
		return true;
	}
	return false;
}

void Game::SwitchPlayers()
{
	m_currentPlayer = EPlayer(1 - (int)m_currentPlayer);

}
