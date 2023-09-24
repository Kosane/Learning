#ifndef FILEDIALOG_H
#define FILEDIALOG_H

#include <QWidget>
#include <QFileDialog>
#include <QDebug>

namespace Ui {
class FileDialog;
}

class FileDialog : public QWidget
{
    Q_OBJECT

public:
    explicit FileDialog(QWidget *parent = nullptr);
    ~FileDialog();

    QString path;

    void openFile();

private:
    Ui::FileDialog *ui;
};

#endif // FILEDIALOG_H
