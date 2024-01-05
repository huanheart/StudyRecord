#ifndef CURRENTLISTCONTROLWIDGET_H
#define CURRENTLISTCONTROLWIDGET_H

#include <QWidget>
#include"components/qtmaterialflatbutton.h"
#include"components/qtmaterialraisedbutton.h"
#include"Global.hpp"

namespace Ui {
class CurrentListControlWidget;
}

class CurrentListControlWidget : public QWidget
{
    Q_OBJECT

public:
    explicit CurrentListControlWidget(QWidget *parent = nullptr);
    ~CurrentListControlWidget();


signals:
    void SaveInformation(LabelInformation Information,enum Whether_to_send decide);
    void Update_MyMaterialAutoComplete(QString NewLineEdit,QString OldLineEdit);
    void DeleteListControl(long long CurrentNum);

public slots:
    void ChangeInformation(long long CurrentNum,LabelInformation Information);
    void SaveMyInformation(LabelInformation Information,enum Whether_to_send decide);


private slots:
    void on_pushButton_clicked();

    void on_Query_clicked();

    void on_Save_clicked();

    void on_AddTask_clicked();

private:
    Ui::CurrentListControlWidget *ui;
    LabelInformation Information;
    long long CurrentNum=-1;
    QMessageBox *msgBox=nullptr;
    QtMaterialFlatButton *Yes=nullptr;
    QtMaterialFlatButton *No=nullptr;
private:
    void init();

};

#endif // CURRENTLISTCONTROLWIDGET_H
