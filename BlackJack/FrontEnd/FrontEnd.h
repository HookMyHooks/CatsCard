#pragma once

#include <QWidget>
#include "ui_FrontEnd.h"
#include "IGame.h" // Include the interface instead of the concrete class


class FrontEnd : public QMainWindow
{
    Q_OBJECT

public:
    explicit FrontEnd(QWidget* parent = nullptr);
    ~FrontEnd();

private slots:
    void on_deckButton_clicked();
    void on_holdCardButton_clicked();
    void updateUI();

private:
    Ui::FrontEndClass* ui;
    IGamePtr m_game; // Use the interface pointer
    void displayCards(EPlayer player);
    void displayCardImage(ENumber card, QLabel* label);

    QList<QLabel*> player1CardLabels;
    QList<QLabel*> player2CardLabels;
};
