#pragma once

#include <QtWidgets/QMainWindow>
#include <QPainter>
#include "ui_MainScene.h"
#include "Bird.h"

class MainScene : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainScene(QWidget *parent = Q_NULLPTR);

	void setWindowTransparent();//设置窗口透明

	void paintEvent(QPaintEvent* event) override;

private:
    Ui::MainSceneClass ui;

	Bird *m_bird = nullptr;

	//自动移动位置
	QPoint m_auto_pos;
	//自动移动定时器
	QTimer *timer = nullptr;
	//屏幕对象
	QDesktopWidget *desk = nullptr;
};
