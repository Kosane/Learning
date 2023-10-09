#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "errordialog.h"
#include "successdialog.h"
#include "dictdialog.h"
#include "fstream"
#include <bitset>

#include <QDebug>
#include "texts.h"
#include <QFileDialog>


#include "dynamic_bitset-master/include/sul/dynamic_bitset.hpp"


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    QString path = 0;
    std::ifstream old_file;
    std::ofstream new_file;
    std::bitset<4>* keys;
    std::bitset<4>* new_keys;
    int array_size;

//    void setGreetings();

private slots:
    void on_choose_clicked();

    void on_encode_clicked();

    void on_decode_clicked();

    void on_show_dict_clicked();

private:
    Ui::MainWindow *ui;
    ErrorDialog errordialog;
    SuccessDialog successdialog;
    DictDialog dictdialog;
};
#endif // MAINWINDOW_H
