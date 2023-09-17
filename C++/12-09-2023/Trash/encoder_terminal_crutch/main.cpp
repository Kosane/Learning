#include <iostream>
#include <string>
#include <fstream>
#include <math.h>
#include <ctime>

// весь текст вынес в отдельные константы потому что захотел
const std::string GREETINGS = "Приветствую Вас, о Великий Пользователь!!!!!!!!!!!!!\n"
                              "Я - программа, которая кодирует файлы волшебным образом!\n"
                              "Если у Вас, о Великий, возникло необъяснимое бешеное желание "
                              "закодировать файл, то, будьте так любезны, введите его полный путь! "
                              "Я с превеликим удовольствием сделаю всю грязную работу!\n"
                              "Полный путь файла: ";

const std::string COMMANDS =  "Список команд.\n"
                              "1. Закодировать файл.\n"
                              "2. Декодировать файл.\n"
                              "3. Вывести словарь кодирования.\n"
                              "0. Завершить работу программы.\n"
                              "Введите номер команды:";

const std::string CASE_ERROR = "Ошибочка: кажется, вы ввели неверный номер команды.\n";

const std::string FAREWELL = "Всего! Хоро! Шего!";

// прототипы функций
int decimal_from_bin(bool* array, int size);
bool elem_is_in_array(bool* elem, bool** array, int array_size);
int index_of_elem(bool* elem, bool** array, int array_size);
bool** create_keys(std::ifstream& file, int& array_size);
bool** create_random_keys(int array_size);
void show_array(bool** array, int array_size);
void show_dict(bool** array1, bool** array2, int arrays_size);
std::string encode_string(std::string old_string, bool** keys, bool** new_keys, int array_size);

int main(){
    // сид для рандома
    srand(time(0));

    // открытие файла
    std::string path; // путь к файлу
    std::cout << GREETINGS; getline(std::cin, path);
    std::ifstream old_file(path);
    std::cout << std::endl << "Большое спасибо за путь!" << std::endl;

    // считывание ключей из файла
    int array_size;
    bool** keys = create_keys(old_file, array_size);
    old_file.close();

    // создание словаря с помощью генерирования рандомных ключей
    bool** new_keys = create_random_keys(array_size);

    std::string line; // строка для чтения файла
    const char* charpath = path.c_str(); // путь файла в формате char* для функций remove и rename

    bool cycle = 1;
    int choose;
    while (cycle){
        std::cout << COMMANDS << std::endl; std::cin >> choose;

        switch (choose){
        case 1:{
            // замена символов с помощью словаря
            old_file.open(path);
            std::ofstream new_file("temp_file.txt"); // временный файл, куда записываю новые биты
            if (old_file){
                while(getline(old_file, line)){
                    new_file << encode_string(line, keys, new_keys, array_size) << std::endl;
                }
            }

            // закрываем файлики, переименовываем
            old_file.close();
            new_file.close();
            remove(charpath);
            rename("temp_file.txt", charpath);

            std::cout << "Успешно кодировано!" << std::endl << std::endl;
        }
            break;
        case 2:{
            // замена символов с помощью словаря
            old_file.open(path);
            std::ofstream new_file("temp_file.txt"); // временный файл, куда записываю новые биты
            if (old_file){
                while(getline(old_file, line)){
                    new_file << encode_string(line, new_keys, keys, array_size) << std::endl; // тут просто поменены местами keys и new_keys
                }
            }

            // закрываем файлики, переименовываем
            old_file.close();
            new_file.close();
            remove(charpath);
            rename("temp_file.txt", charpath);

            std::cout << "Успешно декодировано!" << std::endl << std::endl;
        }
            break;
        case 3:
                // Вывод словаря
                std::cout << "Словарь:" << std::endl;
                show_dict(keys, new_keys, array_size);
            break;
        case 0: cycle = 0; break;
        default: std::cout << CASE_ERROR << std::endl; break;
        }
    }

    std::cout << FAREWELL << std::endl;
    return 0;
}









// функции


// перевод из массива bool в двоичное число int
int decimal_from_bin(bool* number, int size){
    int result = 0;
    for (int i = 0; i < size; i++){
        result += number[i]*pow(2, size-1-i);
    }
    return result;
}


// проверка, есть ли массив bool в массиве массивов
bool elem_is_in_array(bool* elem, bool** array, int array_size){
    bool result;
    for (int i = 0; i < array_size; i++){
        result = 1;
        for (int j = 0; j < 4; j++){
            if (array[i][j] != elem[j]){
                result = 0;
                break;
            }
        }
        if (result) {break;}
    }
    return result;
}

// поиск индекса элемента
int index_of_elem(bool* elem, bool** array, int array_size){
    int result = 0;
    bool is_exist;
    for (int i = 0; i < array_size; i++){
        is_exist = 1;
        for (int j = 0; j < 4; j++){
            if (array[i][j] != elem[j]){
                is_exist = 0;
                break;
            }
        }
        if (is_exist) {result = i; break;}
    }
    return result;
}


// создание массива массивов bool из файла
bool** create_keys(std::ifstream& file, int& array_size){
    bool **keys = new bool*[16];
    for (int i = 0; i < 16; i++){
        keys[i] = new bool[4]{};
    }

    int number_of_keys = 0;

    std::string line;
    if (file){
        while(getline(file, line)){
            int len = line.length();
            for (int j = 0; j < len; j++) {



                // 2 массива bool, в котором хранятся первые 4 и последние 4 бита ячейки памяти
                bool *binary_num1 = new bool[4];
                // перевод из символа в bool
                for(int i = 7; i >= 4; i--){
                    binary_num1[7-i] = ( ( line[j] >> i ) & 1 ? 1 : 0 );
                }

                bool *binary_num2 = new bool[4];
                for(int i = 3; i >= 0; i--){
                    binary_num2[3-i] = ( ( line[j] >> i ) & 1 ? 1 : 0 );
                }

                // добавляю эти массивы, если их ещё нет в массиве массивов
                if (not(elem_is_in_array(binary_num1, keys, 16))){
                    keys[number_of_keys] = binary_num1;
                    number_of_keys++;
                }
                if (not(elem_is_in_array(binary_num2, keys, 16))){
                    keys[number_of_keys] = binary_num2;
                    number_of_keys++;
                }
            }
        }
    }
    array_size = number_of_keys;

    return keys;
}


// создание рандомного массива массивов bool (выходные буквы алфавита)
bool** create_random_keys(int array_size){
    bool** keys = new bool*[array_size];

    for (int i = 0; i < array_size; i++){
        keys[i] = new bool[4];
    }

    bool* temp_num = new bool[4];

    for (int i = 0; i < array_size; i++){
        while (elem_is_in_array(temp_num, keys, array_size)){
            for (int j = 0; j < 4; j++){
                temp_num[j] = rand() % 2;
            }
        }

        for (int j = 0; j < 4; j++){
            keys[i][j] = temp_num[j];
        }
    }
    return keys;
}

// вывод массива, впоследствии не использовал, может даже не работает
void show_array(bool** array, int array_size){
    for (int j = 0; j < array_size; j++){
        for (int i = 0; i < 4; i++){
            std::cout << array[j][i];
        }
        std::cout << std::endl;
    }
}



// вывод словаря кодирования
void show_dict(bool** array1, bool** array2, int arrays_size){
    std::cout << "Буквы вх.\tБуквы вых." << std::endl;
    for (int j = 0; j < arrays_size; j++){
        for (int i = 0; i < 4; i++){
            std::cout << array1[j][i];
        }
        std::cout << "\t\t";
        for (int i = 0; i < 4; i++){
            std::cout << array2[j][i];
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}





// ну и собственно главная функция, которая кодирует байты в соответсвии со словарём
std::string encode_string(std::string old_string,  bool** keys, bool** new_keys, int array_size){
    std::string new_string = "";

    int len = old_string.length();
    bool temp_num[8];
    for (int j = 0; j < len; j++) {

        bool *binary_num1 = new bool[4];

        for(int i = 7; i >= 4; i--){
            binary_num1[7-i] = ( ( old_string[j] >> i ) & 1 ? 1 : 0 );
        }

        bool *binary_num2 = new bool[4];

        for(int i = 3; i >= 0; i--){
            binary_num2[3-i] = ( ( old_string[j] >> i ) & 1 ? 1 : 0 );
        }


        for (int i = 0; i < 4; i++){
            temp_num[i] = new_keys[index_of_elem(binary_num1, keys, array_size)][i];
        }
        for (int i = 4; i < 8; i++){
            temp_num[i] = new_keys[index_of_elem(binary_num2, keys, array_size)][i-4];
        }

        new_string += char(decimal_from_bin(temp_num, 8));
    }

    return new_string;
}
