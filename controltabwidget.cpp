#include "controltabwidget.h"
#include "ui_controltabwidget.h"

controltabwidget::controltabwidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::controltabwidget)
{
    ui->setupUi(this);
    this->initValue();

}

controltabwidget::~controltabwidget()
{
    delete labelWidget; //防止
    delete ui;
}

void controltabwidget::initValue()
{
    ui->tabWidget->tabBar()->setHidden(true);
    //    这意味着用户将无法通过点击选项卡标签来切换页面，但你仍然可以通过编程方式在不同的页面之间进行切换。
    //这个就是隐藏了它的标签栏
    QPalette palette;
    palette.setColor(QPalette::Background,QColor(30,30,30));
    ui->tabWidget->setAutoFillBackground(true);
    ui->tabWidget->setPalette(palette);
    ui->tabWidget->tabBar()->setPalette(palette);

    {
        TabWidgetData tabWidgetData;
        tabWidgetData.currentWidget=ui->tabBanna;
        tabWidgetData.currentTabText=ui->tabWidget->tabText(static_cast<int>(WidgetTabType::Tab_first));
        mapTabWidget[WidgetTabType::Tab_first]=tabWidgetData;
    } //1


    {
        TabWidgetData tabWidgetData;
        tabWidgetData.currentWidget=ui->tab_2;
        tabWidgetData.currentTabText=ui->tabWidget->tabText(static_cast<int>(WidgetTabType::Tab_Second));
        mapTabWidget[WidgetTabType::Tab_Second]=tabWidgetData;
    } //2


    {
        TabWidgetData tabWidgetData;
        tabWidgetData.currentWidget=ui->tab_3;
        tabWidgetData.currentTabText=ui->tabWidget->tabText(static_cast<int>(WidgetTabType::Tab_thrid));
        mapTabWidget[WidgetTabType::Tab_thrid]=tabWidgetData;
    } //3


    {
        TabWidgetData tabWidgetData;
        tabWidgetData.currentWidget=ui->tab_4;
        tabWidgetData.currentTabText=ui->tabWidget->tabText(static_cast<int>(WidgetTabType::Tab_fourth));
        mapTabWidget[WidgetTabType::Tab_fourth]=tabWidgetData;
    }
    labelWidget=new LabelWidget(this);
    labelWidget->hide();
    CurrentWidget=new CurrentListControlWidget(this);
    CurrentWidget->hide(); //一开始隐藏


    connect(this,&controltabwidget::RecoverFinsh,ui->AddLabel,&MyMaterialFlatButton::ClickedFinsh);
    //信号连接信号,将按钮给进行初始了，然后完成的时候再发送个信号给最终的一行文本
    connect(ui->AddLabel,&MyMaterialFlatButton::ClickedFinsh,ui->widget_2,&ListWidget::write_label);

    connect(labelWidget,&LabelWidget::SaveInformation,this,RecoverWidget);
    connect(labelWidget,&LabelWidget::SaveInformation,CurrentWidget,&CurrentListControlWidget::SaveMyInformation);
    connect(ui->widget_2,&ListWidget::SaveValue,ui->searchBox,&MyMaterialAutoComplete::MyMateriaAppend);
    connect(this,&controltabwidget::ChangeUi_Information,CurrentWidget,&CurrentListControlWidget::ChangeInformation);
    connect(ui->widget_2,&ListWidget::ShowCurrentListWidget_two,this,&controltabwidget::ShowListControlWidget);
    connect(CurrentWidget,&CurrentListControlWidget::SaveInformation,this,RecoverWidget);
    connect(CurrentWidget,&CurrentListControlWidget::SaveInformation,ui->widget_2,&ListWidget::SaveLabel); //这里的要和listwidget联系起来了
    connect(CurrentWidget,&CurrentListControlWidget::Update_MyMaterialAutoComplete,ui->searchBox,&MyMaterialAutoComplete::Update_MyMaterialAutoComplete);
    connect(ui->widget_2,&ListWidget::DeleteCurrentLineEdit,ui->searchBox,&MyMaterialAutoComplete::DeleteCurrentLineEdit);
    connect(CurrentWidget,&CurrentListControlWidget::DeleteListControl,ui->widget_2,&ListWidget::DeleteListControl);
    connect(ui->widget_2,&ListWidget::ShowListWidget,this,&controltabwidget::To_hideLabelWidget_2);
    connect(this,&controltabwidget::UpdateListWidget,ui->widget_2,&ListWidget::UpdateListWidget);
    //现在是已经可以添加了，但是并没有覆盖

}

void controltabwidget::keyPressEvent(QKeyEvent *event)
{
    if(event->key()==Qt::Key_Enter||event->key()==Qt::Key_Return)
    {
        ui->look->click();   //增加搜索的快捷键
    }
    else
    {
        QWidget::keyPressEvent(event);
    }
}

void controltabwidget::resizeEvent(QEvent event)
{
    qDebug()<<"子内容改变";
}

void controltabwidget::paintEvent(QPaintEvent *event)
{

    QStylePainter painter(this);
    QStyleOption opt;
    opt.initFrom(this);
    opt.rect = rect();
    painter.drawPrimitive(QStyle::PE_Widget, opt);

    QWidget::paintEvent(event);
}

void controltabwidget::change(int width,int height)
{
    this->resize(width*13/14+100,height-20);
    ui->tabWidget->resize(width*13/14+100,height-20);
    ui->widget_2->setGeometry(0,this->height()/4,this->width(),this->height()*3/4);
    ui->searchWidget->setGeometry(0,0,this->width(),this->height()/4);
    labelWidget->resize(width*13/14+100,height-20);
    CurrentWidget->resize(width*13/14+100,height-20);
}

void controltabwidget::receiveShowCurrentTab(WidgetTabType widgetTabType)
{
    if(widgetTabType>=WidgetTabType::Tab_max) return ;
//    qDebug()<<"进入";
    TabWidgetData tabWidgetData=mapTabWidget.value(widgetTabType);

    if(ui->tabWidget->indexOf(tabWidgetData.currentWidget)<0){ //判断这个widget是否存在,以防万一
        ui->tabWidget->addTab(tabWidgetData.currentWidget,tabWidgetData.currentTabText);
        //如果不存在就手动添加
    }
    if(widgetTabType==WidgetTabType::Tab_thrid) //则让对应的show出来
    {
        ui->searchWidget->show();
        ui->widget_2->show();
    }
    ui->tabWidget->setCurrentWidget(tabWidgetData.currentWidget); //直接显示
}

void controltabwidget::RecoverWidget(LabelInformation Information,enum Whether_to_send decide) //这里还要赋值给本地json的
{
    labelWidget->hide();
    CurrentWidget->hide();
    //然后发送一个信号,将保存的内容给创建起来,这里并将内容恢复
    if(decide==Whether_to_send::YES)
    {
        emit RecoverFinsh(Information);
    }
    qDebug()<<"回到这里了;";
    ui->searchWidget->show();
    ui->widget_2->show();


}

void controltabwidget::ShowListControlWidget(long long CurrentNum,LabelInformation Information)
{
    ui->searchWidget->hide();
    ui->widget_2->hide();
        //这里要传递一个信号，给到它，才能知道要改啥
    emit ChangeUi_Information(CurrentNum,Information);
    CurrentWidget->show();     //然后要将展示的页面的内容更新成当前下标的内容

}

void controltabwidget::To_hideLabelWidget()  //这里是切换页面用到的
{
    CurrentWidget->hide();
    labelWidget->hide();  //否则就是labelWidget
}

void controltabwidget::To_hideLabelWidget_2() //这里是删除完页面恢复到原本的地方用的
{
    CurrentWidget->hide();
//    (*CurrentWidget).hide();
    ui->searchWidget->show();
    ui->widget_2->show();
}


//这里可以创一个枚举值，在这里来进行一个判断即可，不用多建立函数了，由于刚刚那个是系统自己创立的槽函数，固然，还是得多创建一个


void controltabwidget::on_AddLabel_clicked() //增加一个内容,先做一个不能自定义添加的东西
{ //这里传一个结构体,在这里可以多建立一个窗口，然后隐藏主窗口
    ui->searchWidget->hide();
    ui->widget_2->hide();             //先进行把当前页面隐藏，然后显示标签页，当点击保存，删除，各有不同的属性，但是都会使得这几个恢复
                                        //得拿一个数组存储对应标签的内容，因为当我重新点击编辑的时候，我得恢复出场设置
    labelWidget->show(); //当我点击其他页面的时候，这个页面必须得hide

}




void controltabwidget::on_look_clicked()
{
    qDebug()<<"出成果";
    qDebug()<<ui->searchBox->text();
    if(ui->searchBox->text()=="")
    {
        emit UpdateListWidget(ui->searchBox->text(),Update_ListWidget::ShowAll);
    }
    else
    {
        qDebug()<<"进入了?";
        emit UpdateListWidget(ui->searchBox->text(),Update_ListWidget::ShowPart);
    }

}

