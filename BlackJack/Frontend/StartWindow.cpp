#include "StartWindow.h"
#include <QLabel>
#include <QPixmap>
#include <QPushButton>
#include <QIcon>
#include <QScreen>
#include "../FrontEnd/CursorUtil.h"
StartWindow::StartWindow(QWidget* parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
    this->setFixedSize(1280, 720);
    QRect screenGeometry = QGuiApplication::primaryScreen()->geometry();
    int x = (screenGeometry.width() - this->width()) / 2;
    int y = (screenGeometry.height() - this->height()) / 2;
    this->move(x, y-50);
    setCustomCursor(this);
    QLabel* backgroundLabel = new QLabel(this);
    QPixmap backgroundPixmap(":/endgame/FrontEnd/background_start.png");
    backgroundLabel->setPixmap(backgroundPixmap);
    backgroundLabel->setScaledContents(true);
    backgroundLabel->setGeometry(0, 0, this->width(), this->height());
    backgroundLabel->lower();

    QLabel* titleLabel = new QLabel(this);
    QPixmap logoPixmap(":/cards/FrontEnd/logo.png");
    titleLabel->setPixmap(logoPixmap);
    titleLabel->setScaledContents(true);
    titleLabel->setGeometry(440, 150, 400, 150);

    QPushButton* playButton = createButton("button_play", 540, 400, 200, 100);
    QPushButton* exitButton = createButton("button_exit", 540, 550, 200, 100);

    connect(playButton, &QPushButton::clicked, this, &StartWindow::onStartButtonClicked);
    connect(exitButton, &QPushButton::clicked, this, &StartWindow::onExitButtonClicked);

}

StartWindow::~StartWindow()
{
}

void StartWindow::onStartButtonClicked()
{
    auto game = IGame::Produce();

    m_frontEnd = new FrontEnd();
    m_frontEnd->SetGame(game);

    game->AddListener(m_frontEnd);

    m_frontEnd->show();
    this->close(); 
}

void StartWindow::onExitButtonClicked()
{
    this->close();
}

QPushButton* StartWindow::createButton(const QString& iconName, int posX, int posY, int width, int height)
{
    QPushButton* button = new QPushButton(this);
    button->setIcon(QIcon(QString(":/cards/FrontEnd/%1.png").arg(iconName)));
    button->setIconSize(QSize(width, height));
    button->setFlat(true);
    button->setGeometry(posX, posY, width, height);
    return button;
}
