#include "MainScene.h"
#include <QDesktopWidget>
#include <QDebug>

MainScene::MainScene(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);

	this->m_bird = new Bird(this);
	//设置窗口大小
	this->setFixedSize(this->m_bird->width(), this->m_bird->height());
	//获取屏幕
	desk = QApplication::desktop();
	//创建定时器
	this->timer = new QTimer(this);
	
	//启动定时器
	this->m_bird->running();

	//开启定时器
	timer->start(30);
	//设置窗口透明
	setWindowTransparent();


	//监听bird切换图片信号
	connect(this->m_bird, &Bird::changePix, this, [=]() {
		update();//调用paintEvent
	});

	//监听bird移动信号
	connect(this->m_bird, &Bird::moving, this, [=](QPoint pos) {
		this->move(pos);

		m_auto_pos = pos;
	});

	//监听定时器
	connect(timer, &QTimer::timeout, [=]() {
		if (this->m_bird->mouseDown != true)
		{
			this->m_auto_pos.setX(this->m_auto_pos.x() + 5);
		}
		if (this->m_auto_pos.x() > desk->width())
		{
			qDebug() << "this width :: " << this->width();
			this->m_auto_pos.setX(-this->width());
		}
		this->move(this->m_auto_pos);
	});
	connect(this->m_bird, &Bird::changeSpeed, [=](int speed) {
		this->timer->setInterval(speed);
	});
}

void MainScene::setWindowTransparent()
{
	//隐藏右下角拖动控件
	this->statusBar()->setSizeGripEnabled(false);
	//去掉标题栏
	this->setWindowFlags(Qt::FramelessWindowHint);
	//设置透明窗体 120号属性
	this->setAttribute(Qt::WA_TranslucentBackground);
	//设置窗口顶层
	this->setWindowFlags(this->windowFlags() | Qt::WindowStaysOnTopHint);
	//设置起始Y位置
	this->m_auto_pos.setY(desk->height()*0.5 - this->m_bird->height());
}

void MainScene::paintEvent(QPaintEvent * event)
{
	QPainter painter(this);

	painter.drawPixmap(0, 0, this->m_bird->m_bird_pix);
}
