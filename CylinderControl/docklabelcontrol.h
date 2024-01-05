#ifndef DOCKLABELCONTROL_H
#define DOCKLABELCONTROL_H

#include <QWidget>



namespace Ui {
class DockLabelControl;
}

class DockLabelControl : public QWidget
{
    Q_OBJECT

public:
    explicit DockLabelControl(QWidget *parent = nullptr);
    ~DockLabelControl();

private:



    Ui::DockLabelControl *ui;
};

#endif // DOCKLABELCONTROL_H
