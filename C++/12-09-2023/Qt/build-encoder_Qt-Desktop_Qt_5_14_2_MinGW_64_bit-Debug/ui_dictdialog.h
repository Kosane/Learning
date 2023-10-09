/********************************************************************************
** Form generated from reading UI file 'dictdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DICTDIALOG_H
#define UI_DICTDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DictDialog
{
public:
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QPushButton *pushButton;
    QSpacerItem *horizontalSpacer;
    QTextBrowser *Dictionary;

    void setupUi(QDialog *DictDialog)
    {
        if (DictDialog->objectName().isEmpty())
            DictDialog->setObjectName(QString::fromUtf8("DictDialog"));
        DictDialog->resize(300, 360);
        DictDialog->setMinimumSize(QSize(300, 360));
        DictDialog->setMaximumSize(QSize(300, 360));
        QFont font;
        font.setPointSize(10);
        DictDialog->setFont(font);
        gridLayoutWidget = new QWidget(DictDialog);
        gridLayoutWidget->setObjectName(QString::fromUtf8("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(9, 9, 281, 341));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        pushButton = new QPushButton(gridLayoutWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        gridLayout->addWidget(pushButton, 1, 1, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 1, 0, 1, 1);

        Dictionary = new QTextBrowser(gridLayoutWidget);
        Dictionary->setObjectName(QString::fromUtf8("Dictionary"));

        gridLayout->addWidget(Dictionary, 0, 0, 1, 2);


        retranslateUi(DictDialog);

        QMetaObject::connectSlotsByName(DictDialog);
    } // setupUi

    void retranslateUi(QDialog *DictDialog)
    {
        DictDialog->setWindowTitle(QCoreApplication::translate("DictDialog", "Dialog", nullptr));
        pushButton->setText(QCoreApplication::translate("DictDialog", "\320\237\321\200\320\270\320\275\321\217\321\202\320\276", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DictDialog: public Ui_DictDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DICTDIALOG_H
