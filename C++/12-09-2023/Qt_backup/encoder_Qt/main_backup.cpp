#include "mainwindow.h"

#include <QApplication>

#include <ctime>




// ���⨯� �㭪権
//int decimal_from_bin(bool* array, int size);
void print_bitset(std::bitset<4> binary_num1);
void show_bitset(std::bitset<4> array, int array_size);


int main(int argc, char *argv[]){
    // ᨤ ��� ࠭����
    srand(time(0));

    QApplication a(argc, argv);
    MainWindow window;
    window.setWindowTitle("Encoder");
    window.setWindowIcon(QIcon(":icon.png"));
    window.show();
//    window.setWindowIcon();
    return a.exec();
}
















