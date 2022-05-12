#include "Bird.h"
#include <QDebug>

Bird::Bird(QWidget * parent)
	:QWidget(parent),
	 bird_fly_speed(30),
	 bird_weed_speed(50)
{
	for (size_t i = 0; i < this->max; i++)
	{
		QString str = QString(":/resource/bird%1.png").arg(i+1);
		this->m_bird_pix.load(str);
	}

	//设置bird大小
	this->setFixedSize(this->m_bird_pix.width(), this->m_bird_pix.height());

	//创建timer对象
	this->timer = new QTimer(this);
	//监听timer
	connect(timer, &QTimer::timeout, [=]() {
		QString str = QString(":/resource/bird%1.png").arg(this->min++);
		this->m_bird_pix.load(str);
		if (this->min > this->max)
		{
			this->min = 1;
		}

		emit changePix();
	});

	//创建菜单
	this->m_menu = new QMenu(this);
	QMenu *WeedSpeedMenu = new QMenu(QStringLiteral("翅膀速度"),this);
	QMenu *FlySpeedMenu = new QMenu(QStringLiteral("飞行速度"), this);
	this->m_menu->addMenu(WeedSpeedMenu);
	this->m_menu->addMenu(FlySpeedMenu);

	connect(this->m_menu->addAction(QStringLiteral("退出")), &QAction::triggered, [=]() {
		exit(0);
	});
	/*connect(this->m_menu->addAction(QStringLiteral("速度1档")), &QAction::triggered, [=]() {
		bird_weed_speed = 20;
	});*/
	connect(WeedSpeedMenu->addAction(QStringLiteral("一档")), &QAction::triggered, [=]() {
		this->timer->setInterval(50);
	}); 
	connect(WeedSpeedMenu->addAction(QStringLiteral("二档")), &QAction::triggered, [=]() {
		this->timer->setInterval(40);
	});
	connect(WeedSpeedMenu->addAction(QStringLiteral("三档")), &QAction::triggered, [=]() {
		this->timer->setInterval(30);
	});

	connect(FlySpeedMenu->addAction(QStringLiteral("一档")), &QAction::triggered, [=]() {
		emit changeSpeed(30);
	});
	connect(FlySpeedMenu->addAction(QStringLiteral("二档")), &QAction::triggered, [=]() {
		emit changeSpeed(20);
	});
	connect(FlySpeedMenu->addAction(QStringLiteral("三档")), &QAction::triggered, [=]() {
		emit changeSpeed(10);
	});
}

void Bird::running()
{
	this->timer->start(50);
}

void Bird::mousePressEvent(QMouseEvent *e)
{
	qDebug() << "top left pos ::" << ((QWidget *)this->parent())->frameGeometry().topLeft();
	qDebug() << "cur pos :: " << e->globalPos();
	//获取当前窗口的左上角坐标与屏幕全局坐标的差值,定位当前
	this->m_pox = e->globalPos() - ((QWidget *)this->parent())->frameGeometry().topLeft();

	this->mouseDown = true;

	if (e->button() == Qt::RightButton)
	{
		this->m_menu->popup(QCursor::pos());
	}

	//窗口消失后的信号监听
	connect(this->m_menu, &QMenu::aboutToHide, [=]() {
		this->mouseDown = false;
	});
}

void Bird::mouseMoveEvent(QMouseEvent *e)
{
	qDebug() << "move cur pos :: " << e->globalPos();
	qDebug() << "m_pox pos :: " << this->m_pox;

	emit this->moving(e->globalPos() - this->m_pox);
}

void Bird::mouseReleaseEvent(QMouseEvent * e)
{
	this->mouseDown = false;
}
