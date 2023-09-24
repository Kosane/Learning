/********************************************************************************
** Form generated from reading UI file 'filedialog.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FILEDIALOG_H
#define UI_FILEDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FileDialog
{
public:

    void setupUi(QWidget *FileDialog)
    {
        if (FileDialog->objectName().isEmpty())
            FileDialog->setObjectName(QString::fromUtf8("FileDialog"));
        FileDialog->resize(400, 300);

        retranslateUi(FileDialog);

        QMetaObject::connectSlotsByName(FileDialog);
    } // setupUi

    void retranslateUi(QWidget *FileDialog)
    {
        FileDialog->setWindowTitle(QCoreApplication::translate("FileDialog", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FileDialog: public Ui_FileDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FILEDIALOG_H
