#include "mainwindow.h"

#include <QApplication>

#include <ctime>




// прототипы функций
void print_bitset(std::bitset<4> binary_num1);
void show_bitset(std::bitset<4> array, int array_size);


int main(int argc, char *argv[]){
    // сид для рандома
    srand(time(0));

    QApplication a(argc, argv);
    MainWindow window;
    window.setWindowTitle("Encoder");
    window.setWindowIcon(QIcon(":icon.png"));
    window.show();
    return a.exec();
}
















