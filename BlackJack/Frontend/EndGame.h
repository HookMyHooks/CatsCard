#pragma once

#include <QMainWindow>
#include "ui_EndGame.h"

class EndGame : public QMainWindow
{
	Q_OBJECT

public:
	EndGame(int typeEndGame,int finalPointsPlayer1,int finalPointsPlayer2,QWidget *parent = nullptr);
	~EndGame();

private:
	void closeEvent(QCloseEvent* event) override;
private:
	Ui::EndGameClass ui;
};
