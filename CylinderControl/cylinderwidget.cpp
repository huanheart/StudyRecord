#include "cylinderwidget.h"
#include "ui_cylinderwidget.h"
#include<QDebug>


CylinderWidget::CylinderWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CylinderWidget)
{
    ui->setupUi(this);
    this->initValue();
}

CylinderWidget::~CylinderWidget()
{



    delete m_vboxLayout;
    delete dock; //得注意删除的顺序
    delete ui;


}

void CylinderWidget::paintEvent(QPaintEvent *event)      //加上这一个就可以样式表成功了
{
    QStylePainter painter(this);
    QStyleOption opt;
    opt.initFrom(this);
    opt.rect = rect();
    painter.drawPrimitive(QStyle::PE_Widget, opt);

    QWidget::paintEvent(event);
}

void CylinderWidget::initValue()
{
//    dockwidget显示对应的标签学习时间，

    ui->widgetFirst->setSliderValue(15);     //这个进度条得根据它目前对应的标签的总学习时长来进行一个更改
    ui->widgetFirst->setSliderText("12月27"); //这里的柱形图得刷新成当前对应的日期时间，如12月27

    ui->widgetSecond->setSliderValue(30);
    ui->widgetSecond->setSliderText("12月28");

    ui->widgetThird->setSliderValue(45);
    ui->widgetThird->setSliderText("12月29");

    ui->widgetFourth->setSliderValue(60);
    ui->widgetFourth->setSliderText("12月30");

    ui->widgetFifth->setSliderValue(80);
    ui->widgetFifth->setSliderText("12月31");

    ui->widgetSixth->setSliderValue(95); //
    ui->widgetSixth->setSliderText("12月1");

    dock=new QDockWidget("详细标签信息",this,Qt::WindowStaysOnTopHint);
    dock->setAllowedAreas(Qt::NoDockWidgetArea); //Qt::NoDockWidgetArea 表示不允许 QDockWidget 在任何区域停靠
    dock->setMinimumSize(300,300);
    dock->setFeatures(QDockWidget::DockWidgetClosable|QDockWidget::DockWidgetMovable|QDockWidget::DockWidgetFloatable);
    //可关闭，可移动，可悬浮
    dock->hide();



}






void CylinderWidget::on_pushButton_clicked() //原本下想把这个按钮改名的，结果出现qt本身的按钮bug了
{
    qDebug()<<"ahskdh1“；";":";

    if(!dock->isHidden())
    {
        dock->hide();
        return ;
    }

    dock->setGeometry(QRect(200,200,300,300));
    dock->setFloating(true);
    dock->show();

}

