#include "FrontEnd.h"
#include <QPixmap>
#include <QLabel>

FrontEnd::FrontEnd(QWidget* parent)
    : QMainWindow(parent), ui(new Ui::FrontEndClass)
{
    ui->setupUi(this);

    // Initialize player card containers and layouts
    player1CardContainer = ui->Player1CardContainer;
    player2CardContainer = ui->Player2CardContainer;

    player1CardLayout = new QHBoxLayout(player1CardContainer);
    player2CardLayout = new QHBoxLayout(player2CardContainer);

    player1CardContainer->setLayout(player1CardLayout);
    player2CardContainer->setLayout(player2CardLayout);

    QObject::connect(&m_msgBoxEndGame, &QMessageBox::buttonClicked, [&](QAbstractButton* button) {
        if (m_msgBoxEndGame.buttonRole(button) == QMessageBox::AcceptRole) {
            onOkButtonClicked();
        }
        });
}

FrontEnd::~FrontEnd()
{
    delete ui;
}

void FrontEnd::on_deckButton_clicked()
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

void FrontEnd::OnReset()
{
   
}

void FrontEnd::OnTakeCard(const EPlayer& player)
{
    // Update UI to reflect the card taken
    displayCards(EPlayer::Player1);
    displayCards(EPlayer::Player2);
}

void FrontEnd::SetGame(IGamePtr game)
{
    this->m_game = game;
    updateUI();
}

void FrontEnd::on_holdCardButton_clicked()
{
    m_game->HoldCards();
    updateUI();
}

void FrontEnd::updateUI()
{
    EPlayer currentPlayer = m_game->GetCurrentPlayer();

    displayCards(EPlayer::Player1);
    displayCards(EPlayer::Player2);

    ui->statusLabel->setText(currentPlayer == EPlayer::Player1 ? "Player 1's Turn" : "Player 2's Turn");

    EState currentState = m_game->GetCurrentState();
    bool gameInProgress = (currentState == EState::InProgress);
    ui->deckButton->setEnabled(gameInProgress);
    ui->holdCardButton->setEnabled(gameInProgress);

    if (!gameInProgress)
    {
        ui->Player1CardContainer->setVisible(true);
        ui->Player2CardContainer->setVisible(true);
    }
}

void FrontEnd::onOkButtonClicked()
{
    close();
}

void FrontEnd::displayCards(EPlayer player)
{
    QHBoxLayout* layout = (player == EPlayer::Player1) ? player1CardLayout : player2CardLayout;

    // Clear the layout
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
            // Display card-back for the first card of the opponent
            displayCardBack(label);
        }
        else
        {
            // Display actual card
            displayCardImage(cards[i]->GetNumber(), label);
        }

        label->setFixedSize(100, 150);
        layout->addWidget(label);
    }

    layout->addStretch();
}

void FrontEnd::displayCardBack(QLabel* label)
{
    QString cardBackFile = ":/cards/card_back.png"; // Path to the card-back image
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
