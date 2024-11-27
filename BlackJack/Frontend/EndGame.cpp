#include "EndGame.h"

EndGame::EndGame(int typeEndGame, int finalPointsPlayer1, int finalPointsPlayer2, QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

	switch (typeEndGame)
	{
	case 0:
		//player1Win
		break;
	case 1: 
		//player2Win
		break;
	case 2:
		//Draw
		break;
	default:
		break;
	}
}

EndGame::~EndGame()
{}
