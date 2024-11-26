#include "StartWindow.h"

StartWindow::StartWindow(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	QPushButton* startButton = new QPushButton("Start", this);
	connect(startButton, &QPushButton::clicked, this, &StartWindow::onStartButtonClicked);

}

StartWindow::~StartWindow()
{}

void StartWindow::onStartButtonClicked()
{
	auto game = IGame::Produce();

	m_frontEnd = new FrontEnd();
	m_frontEnd->SetGame(game);

	game->AddListener(m_frontEnd);

	m_frontEnd->show();
}