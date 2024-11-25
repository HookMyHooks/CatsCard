#include "FrontEnd.h"

FrontEnd::FrontEnd(QWidget* parent)
    : QMainWindow(parent), ui(new Ui::FrontEndClass), m_game(IGame::Produce())
{
    ui->setupUi(this);
    updateUI();
}

FrontEnd::~FrontEnd()
{
    delete ui;
}

void FrontEnd::on_takeCardButton_clicked()
{
    m_game->TakeCard(); 
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

    ui->player1CardList->setVisible(currentPlayer == EPlayer(0));
    ui->player2CardList->setVisible(currentPlayer == EPlayer(1));

    displayCards(EPlayer(0));
    displayCards(EPlayer(1));

    EState currentState = m_game->GetCurrentState();
    if (currentState == EState::Player1Win)
        ui->statusLabel->setText("Player 1 Wins!");
    else if (currentState == EState::Player2Win)
        ui->statusLabel->setText("Player 2 Wins!");
    else if (currentState == EState::Draw)
        ui->statusLabel->setText("It's a Draw!");
    else
        ui->statusLabel->setText(currentPlayer == EPlayer::Player1 ? "Player 1's Turn" : "Player 2's Turn");

    bool gameInProgress = (currentState == EState::InProgress);
    ui->takeCardButton->setEnabled(gameInProgress);
    ui->holdCardButton->setEnabled(gameInProgress);
}

void FrontEnd::displayCards(EPlayer player)
{
    QListWidget* cardListWidget = (player == EPlayer::Player1) ? ui->player1CardList : ui->player2CardList;
    cardListWidget->clear();

    auto cards = m_game->GetCardsForPlayer(player);
    for (const auto& card : cards)
    {
        QString cardText = QString::fromStdString(std::to_string(static_cast<int>(card->GetNumber())));
        cardListWidget->addItem(cardText);
    }
}
