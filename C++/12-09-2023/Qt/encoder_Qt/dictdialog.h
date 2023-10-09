#ifndef DICTDIALOG_H
#define DICTDIALOG_H

#include <QDialog>

namespace Ui {
class DictDialog;
}

class DictDialog : public QDialog
{
    Q_OBJECT

public:
    explicit DictDialog(QWidget *parent = nullptr);
    ~DictDialog();
    void setDictionary(QString dictionary);

private slots:
    void on_pushButton_clicked();

private:
    Ui::DictDialog *ui;
};

#endif // DICTDIALOG_H
