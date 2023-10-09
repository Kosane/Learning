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

    // ниже должны быть объ€влены нулЄм и потом через ползунки задавать, но € их пока убрал
    int keys_len = 4;
    int new_keys_len = 4;

    sul::dynamic_bitset<>* keys;
    sul::dynamic_bitset<>* new_keys;



    int array_size;

//    void setGreetings();

private slots:
    void on_choose_clicked();

    void on_encode_clicked();

    void on_decode_clicked();

    void on_show_dict_clicked();

    // это функции дл€ ползунков
//    void on_spinBox_valueChanged(int arg1);

//    void on_spinBox_2_valueChanged(int arg1);


private:
    Ui::MainWindow *ui;
    ErrorDialog errordialog;
    SuccessDialog successdialog;
    DictDialog dictdialog;
};
#endif // MAINWINDOW_H
