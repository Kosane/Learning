/********************************************************************************
** Form generated from reading UI file 'successdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SUCCESSDIALOG_H
#define UI_SUCCESSDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SuccessDialog
{
public:
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton;
    QLabel *SUCCESSED;

    void setupUi(QDialog *SuccessDialog)
    {
        if (SuccessDialog->objectName().isEmpty())
            SuccessDialog->setObjectName(QString::fromUtf8("SuccessDialog"));
        SuccessDialog->resize(400, 100);
        SuccessDialog->setMinimumSize(QSize(400, 100));
        SuccessDialog->setMaximumSize(QSize(400, 100));
        QFont font;
        font.setPointSize(10);
        SuccessDialog->setFont(font);
        gridLayoutWidget = new QWidget(SuccessDialog);
        gridLayoutWidget->setObjectName(QString::fromUtf8("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(10, 10, 381, 81));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 1, 0, 1, 1);

        pushButton = new QPushButton(gridLayoutWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        gridLayout->addWidget(pushButton, 1, 1, 1, 1);

        SUCCESSED = new QLabel(gridLayoutWidget);
        SUCCESSED->setObjectName(QString::fromUtf8("SUCCESSED"));
        SUCCESSED->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(SUCCESSED, 0, 0, 1, 2);


        retranslateUi(SuccessDialog);

        QMetaObject::connectSlotsByName(SuccessDialog);
    } // setupUi

    void retranslateUi(QDialog *SuccessDialog)
    {
        SuccessDialog->setWindowTitle(QCoreApplication::translate("SuccessDialog", "Dialog", nullptr));
        pushButton->setText(QCoreApplication::translate("SuccessDialog", "\320\236\320\272\320\270", nullptr));
        SUCCESSED->setText(QCoreApplication::translate("SuccessDialog", "TextLabel \320\237\321\200\320\270\320\274\320\265\321\200 \321\202\320\265\320\272\321\201\321\202\320\260", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SuccessDialog: public Ui_SuccessDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SUCCESSDIALOG_H
