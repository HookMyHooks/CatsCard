#include "FrontEnd.h"
#include <QPixmap>
#include <QLabel>

FrontEnd::FrontEnd(QWidget* parent)
    : QMainWindow(parent), ui(new Ui::FrontEndClass)
{
    ui->setupUi(this);
    player1CardLabels = { ui->player1CardLabel1, ui->player1CardLabel2, ui->player1CardLabel3 };
    player2CardLabels = { ui->player2CardLabel1, ui->player2CardLabel2, ui->player2CardLabel3 };
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

void FrontEnd::OnWin()
{
    ui->Player1CardContainer->setVisible(1);
    ui->Player2CardContainer->setVisible(1);

    displayCards(EPlayer(0));
    displayCards(EPlayer(1));

    QString msg;
    EState currentState = m_game->GetCurrentState();
    if (currentState == EState::Player1Win)
        msg="Player 1 Wins!";
    else if (currentState == EState::Player2Win)
       msg="Player 2 Wins!";
    else if (currentState == EState::Draw)
        msg="It's a Draw!";

    m_msgBoxEndGame.setText(msg);

    m_msgBoxEndGame.exec();
}

void FrontEnd::OnReset()
{
}

void FrontEnd::OnTakeCard(const EPlayer& player)
{
    ui->Player1CardContainer->setVisible(player == EPlayer(0));
    ui->Player2CardContainer->setVisible(player == EPlayer(1));

    displayCards(EPlayer(0));
    displayCards(EPlayer(1));
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

    ui->Player1CardContainer->setVisible(currentPlayer == EPlayer(0));
    ui->Player2CardContainer->setVisible(currentPlayer == EPlayer(1));

    displayCards(EPlayer(0));
    displayCards(EPlayer(1));

    ui->statusLabel->setText(currentPlayer == EPlayer::Player1 ? "Player 1's Turn" : "Player 2's Turn");

    //check to elimini
    EState currentState = m_game->GetCurrentState();
    bool gameInProgress = (currentState == EState::InProgress);
    ui->deckButton->setEnabled(gameInProgress);
    ui->holdCardButton->setEnabled(gameInProgress);
    if (!gameInProgress)
    {
        ui->Player1CardContainer->setVisible(1);
        ui->Player2CardContainer->setVisible(1);
    }
}

void FrontEnd::onOkButtonClicked()
{
    close();
}

void FrontEnd::displayCards(EPlayer player)
{
    QList<QLabel*> labels = (player == EPlayer::Player1) ? player1CardLabels : player2CardLabels;

    auto cards = m_game->GetCardsForPlayer(player);
    for (int i = 0; i < labels.size(); i++)
    {
        if (i < cards.size())
        {
            displayCardImage(cards[i]->GetNumber(), labels[i]); 
            labels[i]->show();
        }
        else
        {
            labels[i]->hide(); 
        }
    }
}



void FrontEnd::displayCardImage(ENumber card, QLabel* label)
{
    QString cardFile;
    switch (card)
    {
    case ENumber::A:
        cardFile = ":/cards/card_A.png";
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


