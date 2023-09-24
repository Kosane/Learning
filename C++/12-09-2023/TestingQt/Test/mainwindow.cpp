#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked(){
    QString filename =  QFileDialog::getOpenFileName(
          this,
          "Открыть",
          QDir::currentPath(),
          "All files (*.*)");

    ui->label->setText(filename.toUtf8());
}
