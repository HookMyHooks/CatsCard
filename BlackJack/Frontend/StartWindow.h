#pragma once

#include "ui_StartWindow.h"
#include "../FrontEnd/FrontEnd.h"


#include <QMainWindow>

class StartWindow : public QMainWindow
{

public:
	StartWindow(QWidget *parent = nullptr);
	~StartWindow();

	

private slots:
	void onStartButtonClicked();
	void onExitButtonClicked();


private:
	Ui::StartWindowClass ui;
	FrontEnd* m_frontEnd;
	QPushButton* createButton(const QString& iconName, int posX, int posY, int width, int height);
};
