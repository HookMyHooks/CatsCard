#pragma once
#include "qmessagebox.h"
#include "ui_FrontEnd.h"
#include <QWidget>
#include <QPixmap>
#include <QLabel>
#include <QHBoxLayout>  
#include <QVBoxLayout>  
#include <QDebug>
#include "CursorUtil.h"
#include "../Frontend/EndGame.h"
#include "../BlackJack/IGame.h"


class FrontEnd : public QMainWindow,public IGameListener
{
    Q_OBJECT

public:
    explicit FrontEnd(QWidget* parent = nullptr);
    ~FrontEnd();

    //IGameListener
    void OnWin(int pointsPlayer1, int pointsPlayer2) override;
    void OnTakeCard(const EPlayer& player) override;

    // other methods
    void SetGame(IGamePtr game);
   
private slots:
    void onDeckButtonClicked();
    void onHoldCardButtonClicked();
    void updateUI();

private:
    void displayCards(EPlayer player);
    void displayCardImage(ENumber card, QLabel* label);
    void displayCardBack(QLabel* label);

private:
    Ui::FrontEndClass* ui;

    QWidget* player1CardContainer;
    QWidget* player2CardContainer;
    QHBoxLayout* player1CardLayout;
    QHBoxLayout* player2CardLayout;

    IGamePtr m_game;
};
