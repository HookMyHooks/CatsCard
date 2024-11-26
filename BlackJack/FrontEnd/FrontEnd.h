#pragma once

#include <QWidget>
#include "ui_FrontEnd.h"
#include "IGame.h" 


class FrontEnd : public QMainWindow,public IGameListener
{
    Q_OBJECT

public:
    explicit FrontEnd(QWidget* parent = nullptr);
    ~FrontEnd();

    //IGameListener
    void OnWin() override;
    void OnReset() override;

    // other methods
    void SetGame(IGamePtr game);


private slots:
    void on_deckButton_clicked();
    void on_holdCardButton_clicked();
    void updateUI();

private:
    Ui::FrontEndClass* ui;
    IGamePtr m_game; 
    void displayCards(EPlayer player);
    void displayCardImage(ENumber card, QLabel* label);

    QList<QLabel*> player1CardLabels;
    QList<QLabel*> player2CardLabels;
};
