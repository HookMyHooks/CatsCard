#include "EndGame.h"
#include <QPixmap>
#include <QLabel>
#include <qboxlayout.h>
#include"CursorUtil.h"
#include "StartWindow.h"
EndGame::EndGame(int typeEndGame, int finalPointsPlayer1, int finalPointsPlayer2, QWidget* parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
    
    QString imagePath;
    QString message;
    setCustomCursor(this);
    switch (typeEndGame)
    {
    case 0: // Player 1 Win
        imagePath = ":/endgame/winCard_player1.png";
        message = "Player 1 Wins!";
        break;
    case 1: // Player 2 Win
        imagePath = ":/endgame/winCard_player2.png";
        message = "Player 2 Wins!";
        break;
    case 2: // Draw
        imagePath = ":/endgame/draw.png";
        message = "It's a Draw!";
        break;
    }

    QPixmap pixmap(imagePath);
    if (pixmap.isNull())
    {
        qDebug() << "Failed to load image for endgame:" << imagePath;
    }
    else
    {
        ui.imageLabel->setPixmap(pixmap);
        ui.imageLabel->setScaledContents(true);
        ui.imageLabel->setFixedSize(415, 159);
    }

    ui.pointsLabel->setText(
        QString("Final Points:\nPlayer 1: %1\nPlayer 2: %2").arg(finalPointsPlayer1).arg(finalPointsPlayer2));
    ui.pointsLabel->setAlignment(Qt::AlignCenter);

}

EndGame::~EndGame()
{
}

void EndGame::closeEvent(QCloseEvent* event)
{
    QMainWindow::closeEvent(event); 
    StartWindow* startWindow = new StartWindow();
    startWindow->show();
}
