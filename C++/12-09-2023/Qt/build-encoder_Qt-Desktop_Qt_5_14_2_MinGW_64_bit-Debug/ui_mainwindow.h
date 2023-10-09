/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QLabel *GREETINGS;
    QVBoxLayout *verticalLayout_2;
    QGridLayout *gridLayout_2;
    QLabel *label;
    QLabel *label_2;
    QPushButton *choose;
    QPushButton *encode;
    QPushButton *decode;
    QPushButton *show_dict;
    QSpacerItem *horizontalSpacer;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->setEnabled(true);
        MainWindow->resize(600, 225);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setMinimumSize(QSize(600, 225));
        MainWindow->setMaximumSize(QSize(600, 225));
        QFont font;
        font.setPointSize(10);
        MainWindow->setFont(font);
        MainWindow->setContextMenuPolicy(Qt::NoContextMenu);
#if QT_CONFIG(statustip)
        MainWindow->setStatusTip(QString::fromUtf8(""));
#endif // QT_CONFIG(statustip)
        MainWindow->setDockOptions(QMainWindow::AllowTabbedDocks|QMainWindow::AnimatedDocks);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayoutWidget = new QWidget(centralwidget);
        gridLayoutWidget->setObjectName(QString::fromUtf8("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(19, 9, 561, 201));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        GREETINGS = new QLabel(gridLayoutWidget);
        GREETINGS->setObjectName(QString::fromUtf8("GREETINGS"));
        GREETINGS->setFont(font);
        GREETINGS->setLayoutDirection(Qt::RightToLeft);
        GREETINGS->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        GREETINGS->setMargin(0);

        gridLayout->addWidget(GREETINGS, 0, 0, 1, 1);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        label = new QLabel(gridLayoutWidget);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout_2->addWidget(label, 1, 0, 1, 1);

        label_2 = new QLabel(gridLayoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout_2->addWidget(label_2, 1, 1, 1, 1);


        verticalLayout_2->addLayout(gridLayout_2);

        choose = new QPushButton(gridLayoutWidget);
        choose->setObjectName(QString::fromUtf8("choose"));

        verticalLayout_2->addWidget(choose);

        encode = new QPushButton(gridLayoutWidget);
        encode->setObjectName(QString::fromUtf8("encode"));

        verticalLayout_2->addWidget(encode);

        decode = new QPushButton(gridLayoutWidget);
        decode->setObjectName(QString::fromUtf8("decode"));

        verticalLayout_2->addWidget(decode);

        show_dict = new QPushButton(gridLayoutWidget);
        show_dict->setObjectName(QString::fromUtf8("show_dict"));

        verticalLayout_2->addWidget(show_dict);


        gridLayout->addLayout(verticalLayout_2, 0, 1, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 1, 0, 1, 1);

        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
#if QT_CONFIG(whatsthis)
        MainWindow->setWhatsThis(QString());
#endif // QT_CONFIG(whatsthis)
        GREETINGS->setText(QCoreApplication::translate("MainWindow", "TextLabel \320\237\321\200\320\270\320\274\320\265\321\200 \321\202\320\265\320\272\321\201\321\202\320\260", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "\320\224\320\273\320\270\320\275\320\260 \320\262\321\205. \321\201\320\273\320\276\320\262\320\260", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "\320\224\320\273\320\270\320\275\320\260 \320\262\321\213\321\205. \321\201\320\273\320\276\320\262\320\260", nullptr));
        choose->setText(QCoreApplication::translate("MainWindow", "\320\222\321\213\320\261\321\200\320\260\321\202\321\214 \321\204\320\260\320\271\320\273", nullptr));
        encode->setText(QCoreApplication::translate("MainWindow", "\320\232\320\276\320\264\320\270\321\200\320\276\320\262\320\260\321\202\321\214", nullptr));
        decode->setText(QCoreApplication::translate("MainWindow", "\320\224\320\265\320\272\320\276\320\264\320\270\321\200\320\276\320\262\320\260\321\202\321\214", nullptr));
        show_dict->setText(QCoreApplication::translate("MainWindow", "\320\237\320\276\320\272\320\260\320\267\320\260\321\202\321\214 \321\201\320\273\320\276\320\262\320\260\321\200\321\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
