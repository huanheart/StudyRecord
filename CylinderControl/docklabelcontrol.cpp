#include "docklabelcontrol.h"
#include "ui_docklabelcontrol.h"

DockLabelControl::DockLabelControl(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DockLabelControl)
{
    ui->setupUi(this);
}

DockLabelControl::~DockLabelControl()
{
    delete ui;
}
