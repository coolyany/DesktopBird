#pragma once
#include <QWidget>
#include <QPixmap>
#include <QTimer>
#include <QMouseEvent>
#include <QMenu>
#include <QCursor>

class Bird : public QWidget
{
	Q_OBJECT
public:
	explicit Bird(QWidget *parent = Q_NULLPTR);

	void running();//指定bird fly 动画

	//鼠标按下事件
	void mousePressEvent(QMouseEvent *e);
	//鼠标移动事件
	void mouseMoveEvent(QMouseEvent *e);
	//鼠标释放事件
	void mouseReleaseEvent(QMouseEvent *e);

	QPixmap m_bird_pix;//鸟贴的图片

	int min = 1;//min index of picture
	int max = 8;

	QTimer *timer = nullptr;
	QPoint m_pox;//记录坐标差值

	bool mouseDown = false;

	QMenu *m_menu;

	int bird_weed_speed;
	int bird_fly_speed;

signals:
	void changePix();//动画图片切换
	void moving(QPoint point);//移动位置信号
	void changeSpeed(int speed);//改变飞行速度信号
public slots:
private:
};