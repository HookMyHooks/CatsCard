#include "FrontEnd.h"
#include <QPixmap>
#include <QLabel>
#include <QCursor>

FrontEnd::FrontEnd(QWidget* parent)
    : QMainWindow(parent), ui(new Ui::FrontEndClass)
{
    ui->setupUi(this);
    setCustomCursor();
  
    player1CardContainer = ui->Player1CardContainer;
    player2CardContainer = ui->Player2CardContainer;

    player1CardLayout = new QHBoxLayout(player1CardContainer);
    player2CardLayout = new QHBoxLayout(player2CardContainer);

    player1CardContainer->setLayout(player1CardLayout);
    player2CardContainer->setLayout(player2CardLayout);

    connect(ui->deckButton, &QPushButton::clicked, this, &FrontEnd::onDeckButtonClicked);
    connect(ui->holdCardButton, &QPushButton::clicked, this, &FrontEnd::onHoldCardButtonClicked);
}

FrontEnd::~FrontEnd()
{
    delete ui;
}

void FrontEnd::onDeckButtonClicked()
{
    m_game->TakeCard();
    updateUI();
}

void FrontEnd::OnWin(int pointsPlayer1,int pointsPlayer2)
{
    int currentState = (int)m_game->GetCurrentState();

    EndGame* endgame = new EndGame(currentState,pointsPlayer1,pointsPlayer2);
    endgame->show();

    this->close();
}

void FrontEnd::OnTakeCard(const EPlayer& player)
{
    displayCards(player);
}

void FrontEnd::SetGame(IGamePtr game)
{
    this->m_game = game;
    updateUI();
}

void FrontEnd::onHoldCardButtonClicked()
{
    m_game->HoldCards();
    updateUI();
}

void FrontEnd::updateUI()
{
    EPlayer currentPlayer = m_game->GetCurrentPlayer();
    EState currentState = m_game->GetCurrentState();

    displayCards(EPlayer::Player1);
    displayCards(EPlayer::Player2);

    ui->statusLabel->setText(currentPlayer == EPlayer::Player1 ? "Player 1's Turn" : "Player 2's Turn");

    bool gameInProgress = (currentState == EState::InProgress);
    bool currentPlayerHasHeld =  m_game->GetPlayerHold(currentPlayer);
    int currentPlayerPoints = m_game->GetPointsForPlayer(currentPlayer);

    ui->HoldOnlyLabel->setVisible(currentPlayerHasHeld);
    ui->deckButton->setEnabled(gameInProgress && !currentPlayerHasHeld);
    ui->holdCardButton->setEnabled(gameInProgress);
    ui->currentPlayerPointsLabel->setText(QString("Points: %1").arg(currentPlayerPoints));
}

void FrontEnd::displayCards(EPlayer player)
{
    QHBoxLayout* layout = (player == EPlayer::Player1) ? player1CardLayout : player2CardLayout;

    QLayoutItem* item;

    while ((item = layout->takeAt(0)) != nullptr)
    {
        delete item->widget();
        delete item;
    }

    auto cards = m_game->GetCardsForPlayer(player);
    bool isOpponent = (player != m_game->GetCurrentPlayer());

    for (size_t i = 0; i < cards.size(); ++i)
    {
        QLabel* label = new QLabel(player == EPlayer::Player1 ? player1CardContainer : player2CardContainer);

        if (isOpponent && i == 0)
        {
            displayCardBack(label);
        }
        else
        {
            displayCardImage(cards[i]->GetNumber(), label);
        }

        label->setFixedSize(114, 200);
        layout->addWidget(label);
    }

    layout->addStretch();
}

void FrontEnd::displayCardBack(QLabel* label)
{
    QString cardBackFile = ":/cards/card_back.png";
    QPixmap pixmap(cardBackFile);

    if (pixmap.isNull())
    {
        qDebug() << "Failed to load card-back image:" << cardBackFile;
        return;
    }

    label->setPixmap(pixmap);
    label->setScaledContents(true);
}

void FrontEnd::displayCardImage(ENumber card, QLabel* label)
{
    QString cardFile;
    switch (card)
    {
    case ENumber::A:
        cardFile = ":/cards/card_a.png";
        break;
    case ENumber::J:
        cardFile = ":/cards/card_j.png";
        break;
    case ENumber::Q:
        cardFile = ":/cards/card_q.png";
        break;
    case ENumber::K:
        cardFile = ":/cards/card_k.png";
        break;
    default:
        cardFile = QString(":/cards/card_%1.png").arg(static_cast<int>(card));
        break;
    }

    QPixmap pixmap(cardFile);
    if (pixmap.isNull())
    {
        qDebug() << "Failed to load card image:" << cardFile;
        return;
    }

    label->setPixmap(pixmap);
    label->setScaledContents(true);
}

void FrontEnd::setCustomCursor()
{
    QString cursorFile = ":/cards/cursor.png";

    QPixmap cursorPixmap(cursorFile);

    if (cursorPixmap.isNull()) {
        qDebug() << "Failed to load custom cursor image:" << cursorFile;
        return;
    }

    QCursor customCursor(cursorPixmap);

    this->setCursor(customCursor);
}
