#include "mainwindow.h"
#include <QApplication>
#include <QtDebug>



int main(int argc, char *argv[]){
    QApplication a(argc, argv);
    MainWindow window;
    window.setWindowIcon(QIcon(":icon.png"));
    window.show();


    return a.exec();
}
