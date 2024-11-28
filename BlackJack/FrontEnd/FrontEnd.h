#pragma once

#include <QWidget>
#include "qmessagebox.h"
#include "ui_FrontEnd.h"
#include "IGame.h" 
#include <QPixmap>
#include <QLabel>
#include <QHBoxLayout>  // Include for QHBoxLayout
#include <QVBoxLayout>  // (Optional) if you need vertical layouts elsewhere
#include <QDebug>   
#include "EndGame.h"


class FrontEnd : public QMainWindow,public IGameListener
{
    Q_OBJECT

public:
    explicit FrontEnd(QWidget* parent = nullptr);
    ~FrontEnd();

    //IGameListener
    void OnWin(int pointsPlayer1, int pointsPlayer2) override;
    void OnReset() override;
    void OnTakeCard(const EPlayer& player) override;

    // other methods
    void SetGame(IGamePtr game);
    void displayCardBack(QLabel* label);


private slots:
    void on_deckButton_clicked();
    void on_holdCardButton_clicked();
    void updateUI();
    void onOkButtonClicked();

private:
    Ui::FrontEndClass* ui;
    IGamePtr m_game; 
    void displayCards(EPlayer player);
    void displayCardImage(ENumber card, QLabel* label);

    QWidget* player1CardContainer;
    QWidget* player2CardContainer;
    QHBoxLayout* player1CardLayout;
    QHBoxLayout* player2CardLayout;

    QMessageBox m_msgBoxEndGame;
    void setCustomCursor();
};
