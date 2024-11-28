#pragma once

#include "ui_StartWindow.h"
#include "FrontEnd.h"

#include <QMainWindow>

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
