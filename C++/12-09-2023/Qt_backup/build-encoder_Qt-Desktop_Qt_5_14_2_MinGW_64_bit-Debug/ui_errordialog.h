/********************************************************************************
** Form generated from reading UI file 'errordialog.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ERRORDIALOG_H
#define UI_ERRORDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ErrorDialog
{
public:
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QPushButton *pushButton;
    QSpacerItem *horizontalSpacer;
    QLabel *ERROR_FILE;

    void setupUi(QDialog *ErrorDialog)
    {
        if (ErrorDialog->objectName().isEmpty())
            ErrorDialog->setObjectName(QString::fromUtf8("ErrorDialog"));
        ErrorDialog->resize(400, 100);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(ErrorDialog->sizePolicy().hasHeightForWidth());
        ErrorDialog->setSizePolicy(sizePolicy);
        ErrorDialog->setMinimumSize(QSize(400, 100));
        ErrorDialog->setMaximumSize(QSize(400, 100));
        ErrorDialog->setSizeIncrement(QSize(400, 100));
        QFont font;
        font.setPointSize(10);
        ErrorDialog->setFont(font);
        ErrorDialog->setModal(false);
        gridLayoutWidget = new QWidget(ErrorDialog);
        gridLayoutWidget->setObjectName(QString::fromUtf8("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(10, 10, 381, 81));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        pushButton = new QPushButton(gridLayoutWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        gridLayout->addWidget(pushButton, 2, 1, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 2, 0, 1, 1);

        ERROR_FILE = new QLabel(gridLayoutWidget);
        ERROR_FILE->setObjectName(QString::fromUtf8("ERROR_FILE"));
        ERROR_FILE->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(ERROR_FILE, 1, 0, 1, 2);


        retranslateUi(ErrorDialog);

        QMetaObject::connectSlotsByName(ErrorDialog);
    } // setupUi

    void retranslateUi(QDialog *ErrorDialog)
    {
        ErrorDialog->setWindowTitle(QCoreApplication::translate("ErrorDialog", "Dialog", nullptr));
        pushButton->setText(QCoreApplication::translate("ErrorDialog", "\320\236\320\272", nullptr));
        ERROR_FILE->setText(QCoreApplication::translate("ErrorDialog", "LabelText \320\237\321\200\320\270\320\274\320\265\321\200 \321\202\320\265\320\272\321\201\321\202\320\260", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ErrorDialog: public Ui_ErrorDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ERRORDIALOG_H
