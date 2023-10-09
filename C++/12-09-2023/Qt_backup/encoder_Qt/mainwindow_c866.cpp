#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "texts.h"
#include <QFileDialog>
//#include <fstream>
#include <bitset>
#include <QDebug>


std::bitset<4>* create_keys(std::ifstream& file, int& array_size);
std::bitset<4>* create_random_keys(int array_size);
bool elem_is_in_array(std::bitset<4> elem, std::bitset<4>* array, int array_size);
char encode_byte(char old_byte, std::bitset<4>* keys, std::bitset<4>* new_keys, int array_size);
int index_of_elem(std::bitset<4> elem, std::bitset<4>* array, int array_size);
void show_dict(std::bitset<4>* array1, std::bitset<4>* array2, int arrays_size);




MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow){
    ui->setupUi(this);
    ui->GREETINGS->setText(GREETINGS);
    errordialog.setWindowTitle("Error");
    successdialog.setWindowTitle("Yappy");

//    setWindowFlags(windowFlags() & ~Qt::Window);
}

MainWindow::~MainWindow(){
    delete ui;
}



void MainWindow::on_choose_clicked(){
    QString filename =  QFileDialog::getOpenFileName(
          this,
          "Open file",
          QDir::homePath(),
          "All files (*.*)");
    path = filename.toUtf8();
    old_file.open(path.toStdString(), std::ios::in|std::ios::binary);

    // считывание ключей из файла
    this->keys = create_keys(old_file, this->array_size);
    old_file.close();

    // создание словаря с помощью генерирования рандомных ключей
    this->new_keys = create_random_keys(array_size);
}

void MainWindow::on_encode_clicked(){
    if (path == 0){
        errordialog.show();
    } else {

        char byte; // символ для чтения файла
        const char* charpath = path.toStdString().c_str(); // путь файла в формате char* для функций remove и rename
        // замена символов с помощью словаря
        this->old_file.open(path.toStdString(), std::ios::in|std::ios::binary);
        // временный файл, куда записываю новые биты
        // такое расширение только чтобы в папке случайно не оказался такой файл
        new_file.open("temp_file.cxc", std::ios::out|std::ios::binary);
        if (old_file){
            while(old_file.get(byte)){
                new_file << encode_byte(byte, keys, new_keys, array_size);
            }
        }

        // закрываем файлики, переименовываем
        old_file.close();
        new_file.close();
        remove(charpath);
        rename("temp_file.cxc", charpath);


        successdialog.show();
    }
}

void MainWindow::on_decode_clicked(){
    if (path == 0){
        errordialog.show();
    } else {

        char byte; // символ для чтения файла
        const char* charpath = path.toStdString().c_str(); // путь файла в формате char* для функций remove и rename
        // замена символов с помощью словаря
        this->old_file.open(path.toStdString(), std::ios::in|std::ios::binary);
        // временный файл, куда записываю новые биты
        // такое расширение только чтобы в папке случайно не оказался такой файл
        new_file.open("temp_file.cxc", std::ios::out|std::ios::binary);
        if (old_file){
            while(old_file.get(byte)){
                new_file << encode_byte(byte, new_keys, keys, array_size);
            }
        }

        // закрываем файлики, переименовываем
        old_file.close();
        new_file.close();
        remove(charpath);
        rename("temp_file.cxc", charpath);


        successdialog.show();
    }

}



void MainWindow::on_show_dict_clicked(){
    if (path == 0){
        errordialog.show();
    } else {

        // вывод словаря кодирования
        QString temp = "";
        temp += LETTERS;
        for (int j = 0; j < this->array_size; j++){
            for (int i = 0; i < 4; i++){
                temp += keys[j][i] & 1 ? "1" : "0";
            }
            temp += "\t";
            for (int i = 0; i < 4; i++){
                temp += new_keys[j][i] & 1 ? "1" : "0";
            }
            temp += "\n";
        }
        temp += "\n";


        dictdialog.setDictionary(temp);

        dictdialog.show();

    }
}








// создание массива битсетов из файла
std::bitset<4>* create_keys(std::ifstream& file, int& array_size){
    std::bitset<4> *keys = new std::bitset<4>[16];
    int number_of_keys = 0;

    char byte;
    if (file){
        while(file.get(byte) and number_of_keys < 16){
            // 2 битсета, в котором хранятся первые 4 и последние 4 бита ячейки памяти
            std::bitset<4> binary_num1;
            // сохранение битов в битсет
            for(int i = 7; i >= 4; i--){
                binary_num1[7-i] = ( (byte >> i) & 1);
            }

            std::bitset<4> binary_num2;
            for(int i = 3; i >= 0; i--){
                binary_num2[3-i] = ( (byte >> i) & 1);
            }

            // добавляю эти битсеты, если их ещё нет в массиве массивов
            // (размер массива = number_of_keys чтобы проверка не затрагивала элементы, которым ещё не было присвоено значение
            if (not(elem_is_in_array(binary_num1, keys, number_of_keys))){
                keys[number_of_keys] = binary_num1;
                number_of_keys++;
            }

            if (not(elem_is_in_array(binary_num2, keys, number_of_keys))){
                keys[number_of_keys] = binary_num2;
                number_of_keys++;
            }
        }
    }


    array_size = number_of_keys;

    return keys;
}


// создание рандомного массива битсетов (выходные буквы алфавита)
std::bitset<4>* create_random_keys(int array_size){
    std::bitset<4>* keys = new std::bitset<4>[array_size];

    std::bitset<4> temp_num;

    for (int i = 0; i < array_size; i++){
        do {
            for (int j = 0; j < 4; j++){
                temp_num[j] = rand() % 2; // рандомный bool
            }
        } while (elem_is_in_array(temp_num, keys, i)); // тут так же размер массива = i чтобы не проверять лишние элементы

        for (int j = 0; j < 4; j++){
            keys[i] = temp_num;
        }
    }
    return keys;
}

// проверка, есть ли битсет в массиве битсетов
bool elem_is_in_array(std::bitset<4> elem, std::bitset<4>* array, int array_size){
    bool result = 0;
    for (int i = 0; i < array_size; i++){
         if (array[i] == elem){
            result = 1;
            break;
         }
    }
    return result;
}

// поиск индекса элемента
int index_of_elem(std::bitset<4> elem, std::bitset<4>* array, int array_size){
    int result = 0;
    for (int i = 0; i < array_size; i++){
        if (array[i] == elem){
            result = i;
            break;
        }
    }
    return result;
}


// ну и собственно главная функция, которая кодирует байты в соответсвии со словарём
char encode_byte(char old_byte,  std::bitset<4>* keys, std::bitset<4>* new_keys, int array_size){
    char new_byte;

    std::bitset<8> temp_num;

    std::bitset<4> binary_num1;

    for(int i = 7; i >= 4; i--){
        binary_num1[7-i] = ( (old_byte >> i) & 1);
    }

    std::bitset<4> binary_num2;

    for(int i = 3; i >= 0; i--){
        binary_num2[3-i] = ( (old_byte >> i) & 1);
    }


    for (int i = 0; i < 4; i++){
        temp_num[i] = new_keys[index_of_elem(binary_num1, keys, array_size)][i];
    }
    for (int i = 4; i < 8; i++){
        temp_num[i] = new_keys[index_of_elem(binary_num2, keys, array_size)][i-4];
    }

    // реверсирую битсет потому что этот класс почему-то неправильно работает с индексами, а менять индексы в циклах уже лень
    for(int i = 0; i < 4; i++) {
        bool t = temp_num[i];
        temp_num[i] = temp_num[8-i-1];
        temp_num[8-i-1] = t;
    }

    new_byte = static_cast<char>(temp_num.to_ulong());
    return new_byte;
}

