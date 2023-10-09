#include "mainwindow.h"
#include "ui_mainwindow.h"


sul::dynamic_bitset<>* create_keys(QString file_path, int len, int& array_size);
sul::dynamic_bitset<>* create_random_keys(int array_size, int len);
bool elem_is_in_array(sul::dynamic_bitset<> elem, sul::dynamic_bitset<>* array, int array_size);
char encode_byte(char old_byte, int len, sul::dynamic_bitset<>* keys, sul::dynamic_bitset<>* new_keys, int array_size);
int index_of_elem(sul::dynamic_bitset<> elem, sul::dynamic_bitset<>* array, int array_size);
void show_dict(sul::dynamic_bitset<>* array1, sul::dynamic_bitset<>* array2, int arrays_size);




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
    delete[] keys;
    delete[] new_keys;
}



void MainWindow::on_choose_clicked(){
    QString filename = QFileDialog::getOpenFileName(
          this,
          "Open file",
          QDir::homePath(),
          "All files (*.*)");
    this->path = filename;


    // считывание ключей из файла
    this->keys = create_keys(path, this->keys_len, this->array_size);

    // создание словар€ с помощью генерировани€ рандомных ключей
    this->new_keys = create_random_keys(this->array_size, this->new_keys_len);

    qDebug() << "Test\n";
    qDebug() << "Test\n";
    qDebug() << "Test\n";
    qDebug() << "Test\n";
    qDebug() << "Test\n";
};

void MainWindow::on_encode_clicked(){
    if (path == 0){
        errordialog.show();
    } else {
        // замена символов с помощью словар€

        // создание объекта входного файла
        QFile old_file(path);
        char *byte; // символ дл€ чтени€ файла

        // временный файл, куда записываю новые биты
        // такое расширение только чтобы в папке случайно не оказалс€ такой файл
        QFile new_file("temp_file.cxc");
        new_file.open(QIODevice::WriteOnly);
        if (old_file.open(QIODevice::ReadOnly)){
            while(old_file.getChar(byte)){
                new_file.putChar(encode_byte(*byte, new_keys_len, keys, new_keys, array_size));
            }
        }

        // закрываем файлики, переименовываем
        old_file.close();
        new_file.close();
        old_file.remove();
        new_file.rename(path);


        successdialog.show();
    }
}

// TODO: изменить дл€ случа€ со словарЄм в начале файла
void MainWindow::on_decode_clicked(){
    if (path == 0){
        errordialog.show();
    } else {
        // замена символов с помощью словар€

        // создание объекта входного файла
        QFile old_file(path);
        char *byte; // символ дл€ чтени€ файла

        // временный файл, куда записываю новые биты
        // такое расширение только чтобы в папке случайно не оказалс€ такой файл
        QFile new_file("temp_file.cxc");
        new_file.open(QIODevice::WriteOnly);
        if (old_file.open(QIODevice::ReadOnly)){
            while(old_file.getChar(byte)){
                new_file.putChar(encode_byte(*byte, new_keys_len, new_keys, keys, array_size));
            }
        }

        // закрываем файлики, переименовываем
        old_file.close();
        new_file.close();
        old_file.remove();
        new_file.rename(path);


        successdialog.show();
    }
}



void MainWindow::on_show_dict_clicked(){
    if (path == 0){
        errordialog.show();
    } else {

        // вывод словар€ кодировани€
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
sul::dynamic_bitset<>* create_keys(QString path, int len, int& array_size){

    // создание объекта входного файла
    QFile file(path);

    // массив битсетов
    sul::dynamic_bitset<> *keys = new sul::dynamic_bitset<>[16]; // TODO: сделать вектор с длиной pow(2, len)
    for (int i = 0; i < 16; i++){
        keys[i].resize(len);
    }

    // количество битсетов (входных слов)
    int number_of_keys = 0;

    char *byte;
    if (file.open(QIODevice::ReadOnly)){
        while(file.getChar(byte) and number_of_keys < pow(2, len)){ // TODO: изменить число 16
            // 2 битсета, в котором хран€тс€ первые 4 и последние 4 бита €чейки пам€ти
            sul::dynamic_bitset<> binary_num1(len);
            // сохранение битов в битсет
            for(int i = len-1; i >= 0; i--){
                binary_num1[len-1-i] = ( (*byte >> i) & 1);
            }

            // добавл€ю эти битсеты, если их ещЄ нет в массиве массивов
            // (размер массива = number_of_keys чтобы проверка не затрагивала элементы, которым ещЄ не было присвоено значение
            if (not(elem_is_in_array(binary_num1, keys, number_of_keys))){
                keys[number_of_keys] = binary_num1;
                number_of_keys++;
            }
        }
    }
    file.close();


    array_size = number_of_keys;

    return keys;
}


// создание рандомного массива битсетов (выходные буквы алфавита)
sul::dynamic_bitset<>* create_random_keys(int array_size, int len){
    sul::dynamic_bitset<>* keys = new sul::dynamic_bitset<>[array_size];
    for (int i = 0; i < array_size; i++){
        keys[i].resize(len);
    }

    sul::dynamic_bitset<> temp_num(len);

    for (int i = 0; i < array_size; i++){
        do {
            for (int j = 0; j < 4; j++){
                temp_num[j] = rand() % 2; // рандомный bool
            }
        } while (elem_is_in_array(temp_num, keys, i)); // тут так же размер массива = i чтобы не провер€ть лишние элементы

        keys[i] = temp_num;
    }
    return keys;
}

// проверка, есть ли битсет в массиве битсетов
bool elem_is_in_array(sul::dynamic_bitset<> elem, sul::dynamic_bitset<>* array, int array_size){
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
int index_of_elem(sul::dynamic_bitset<> elem, sul::dynamic_bitset<>* array, int array_size){
    int result = 0;
    for (int i = 0; i < array_size; i++){
        if (array[i] == elem){
            result = i;
            break;
        }
    }
    return result;
}


// ну и собственно главна€ функци€, котора€ кодирует байты в соответсвии со словарЄм
char encode_byte(char old_byte, int len,  sul::dynamic_bitset<>* keys, sul::dynamic_bitset<>* new_keys, int array_size){
    char new_byte;

    std::bitset<8> temp_num;

    sul::dynamic_bitset<> binary_num1(len);

    for(int i = 7; i >= 4; i--){
        binary_num1[7-i] = ( (old_byte >> i) & 1);
    }

    sul::dynamic_bitset<> binary_num2(len);

    for(int i = 3; i >= 0; i--){
        binary_num2[3-i] = ( (old_byte >> i) & 1);
    }


    for (int i = 0; i < 4; i++){
        temp_num[i] = new_keys[index_of_elem(binary_num1, keys, array_size)][i];
    }
    for (int i = 4; i < 8; i++){
        temp_num[i] = new_keys[index_of_elem(binary_num2, keys, array_size)][i-4];
    }

    // реверсирую битсет потому что этот класс почему-то неправильно работает с индексами, а мен€ть индексы в циклах уже лень
    for(int i = 0; i < 4; i++) {
        bool t = temp_num[i];
        temp_num[i] = temp_num[8-i-1];
        temp_num[8-i-1] = t;
    }

    new_byte = static_cast<char>(temp_num.to_ulong());
    return new_byte;
}


// это функции дл€ ползунков

//void MainWindow::on_spinBox_valueChanged(int arg1)
//{
//    this->keys_len = arg1;
//}

//void MainWindow::on_spinBox_2_valueChanged(int arg1)
//{
//    this->new_keys_len = arg1;
//}
