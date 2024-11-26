#pragma once

#include "FrontEnd.h"

#include <QMainWindow>
#include "ui_StartWindow.h"

class StartWindow : public QMainWindow
{

public:
	StartWindow(QWidget *parent = nullptr);
	~StartWindow();

private slots:
	void onStartButtonClicked();

private:
	Ui::StartWindowClass ui;
	FrontEnd* m_frontEnd;
};
