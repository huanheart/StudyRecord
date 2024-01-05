/********************************************************************************
** Form generated from reading UI file 'docklabelcontrol.ui'
**
** Created by: Qt User Interface Compiler version 5.9.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DOCKLABELCONTROL_H
#define UI_DOCKLABELCONTROL_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DockLabelControl
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label_3;
    QLabel *label;
    QLabel *label_2;
    QFrame *frameLine;

    void setupUi(QWidget *DockLabelControl)
    {
        if (DockLabelControl->objectName().isEmpty())
            DockLabelControl->setObjectName(QStringLiteral("DockLabelControl"));
        DockLabelControl->resize(566, 107);
        DockLabelControl->setStyleSheet(QStringLiteral("color:rgb(0, 255, 255)"));
        verticalLayout = new QVBoxLayout(DockLabelControl);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label_3 = new QLabel(DockLabelControl);
        label_3->setObjectName(QStringLiteral("label_3"));

        horizontalLayout->addWidget(label_3);

        label = new QLabel(DockLabelControl);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        label_2 = new QLabel(DockLabelControl);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout->addWidget(label_2);


        verticalLayout->addLayout(horizontalLayout);

        frameLine = new QFrame(DockLabelControl);
        frameLine->setObjectName(QStringLiteral("frameLine"));
        frameLine->setFrameShape(QFrame::StyledPanel);
        frameLine->setFrameShadow(QFrame::Raised);

        verticalLayout->addWidget(frameLine);

        verticalLayout->setStretch(0, 7);
        verticalLayout->setStretch(1, 1);

        retranslateUi(DockLabelControl);

        QMetaObject::connectSlotsByName(DockLabelControl);
    } // setupUi

    void retranslateUi(QWidget *DockLabelControl)
    {
        DockLabelControl->setWindowTitle(QApplication::translate("DockLabelControl", "Form", Q_NULLPTR));
        label_3->setText(QApplication::translate("DockLabelControl", "\346\230\276\347\244\272\351\242\234\350\211\262", Q_NULLPTR));
        label->setText(QApplication::translate("DockLabelControl", "\346\240\207\347\255\276\345\220\215:", Q_NULLPTR));
        label_2->setText(QApplication::translate("DockLabelControl", "\345\257\271\345\272\224\346\227\266\351\227\264", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class DockLabelControl: public Ui_DockLabelControl {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DOCKLABELCONTROL_H
