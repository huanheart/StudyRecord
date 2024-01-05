#ifndef CYLINDERWIDGET_H
#define CYLINDERWIDGET_H

#include <QWidget>
#include<QDockWidget>
#include<QRect>
#include<QVBoxLayout>
#include<QList>
#include"CylinderControl/docklabelcontrol.h"



namespace Ui {
class CylinderWidget;
}

class CylinderWidget : public QWidget
{
    Q_OBJECT

public:
    explicit CylinderWidget(QWidget *parent = nullptr);
    ~CylinderWidget();

protected:
    void paintEvent(QPaintEvent *event) override;


private slots:

    void on_pushButton_clicked();

private:
    void initValue();
    Ui::CylinderWidget *ui;
    QDockWidget *dock=nullptr;
    QVBoxLayout * m_vboxLayout=nullptr;
    DockLabelControl * dockLabel=nullptr;
    QList<DockLabelControl*> DockList;

};

#endif // CYLINDERWIDGET_H
