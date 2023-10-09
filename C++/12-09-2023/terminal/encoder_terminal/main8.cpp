#include <iostream>
#include <fstream>
#include <ctime>
#include <bitset>

// весь текст вынес в отдельные константы потому что захотел
const std::string GREETINGS = "Приветствую Вас, о Великий Пользователь!!!!!!!!!!!!!\n"
                              "Я - программа, которая кодирует файлы волшебным образом!\n"
                              "Если у Вас, о Великий, возникло необъяснимое бешеное желание "
                              "закодировать файл, то, будьте так любезны, введите его полный путь!\n"
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
//int decimal_from_bin(bool* array, int size);
void print_bitset(std::bitset<4> binary_num1);
bool elem_is_in_array(std::bitset<4> elem, std::bitset<4>* array, int array_size);
int index_of_elem(std::bitset<4> elem, std::bitset<4>* array, int array_size);
std::bitset<4>* create_keys(std::ifstream& file, int& array_size);
std::bitset<4>* create_random_keys(int array_size);
void show_bitset(std::bitset<4> array, int array_size);
void show_dict(std::bitset<4>* array1, std::bitset<4>* array2, int arrays_size);
char encode_byte(char old_byte, std::bitset<4>* keys, std::bitset<4>* new_keys, int array_size);


int main(){
    // сид для рандома
    srand(time(0));

    // открытие файла
    std::string path; // путь к файлу
    std::cout << GREETINGS; getline(std::cin, path);
    std::ifstream old_file(path, std::ios::in|std::ios::binary);
    std::cout << std::endl << "Большое спасибо за путь!" << std::endl;

    // считывание ключей из файла
    int array_size;
    std::bitset<4>* keys = create_keys(old_file, array_size);
    old_file.close();

    // создание словаря с помощью генерирования рандомных ключей
    std::bitset<4>* new_keys = create_random_keys(array_size);


    char byte; // символ для чтения файла
    const char* charpath = path.c_str(); // путь файла в формате char* для функций remove и rename

    bool cycle = 1;
    int choose;
    while (cycle){
        std::cout << COMMANDS << std::endl; std::cin >> choose;

        switch (choose){
        case 1:{
            // замена символов с помощью словаря
            old_file.open(path, std::ios::in|std::ios::binary);
            // временный файл, куда записываю новые биты
            // такое расширение только чтобы в папке случайно не оказался такой файл
            std::ofstream new_file("temp_file.cxc", std::ios::out|std::ios::binary);
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

            std::cout << "Успешно кодировано!" << std::endl << std::endl;
        }
            break;
        case 2:{
            // замена символов с помощью словаря
            old_file.open(path, std::ios::in|std::ios::binary);
            std::ofstream new_file("temp_file.cxc", std::ios::out|std::ios::binary); // временный файл, куда записываю новые биты
            if (old_file){
                while(old_file.get(byte)){
                    new_file << encode_byte(byte, new_keys, keys, array_size); // тут просто поменены местами keys и new_keys
                }
            }

            // закрываем файлики, переименовываем
            old_file.close();
            new_file.close();
            remove(charpath);
            rename("temp_file.cxc", charpath);

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

// вывод битсета
void print_bitset(std::bitset<4> binary_num1){
    for(int i = 0; i < 4; i++){
        std::cout << (binary_num1[i]);
    }
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

// вывод битсетов, впоследствии не использовал, может даже не работает
void show_bitsets(std::bitset<4>* array, int array_size){
    for (int j = 0; j < array_size; j++){
        for (int i = 0; i < 4; i++){
            std::cout << array[j][i];
        }
        std::cout << std::endl;
    }
}

// вывод словаря кодирования
void show_dict(std::bitset<4>* array1, std::bitset<4>* array2, int arrays_size){
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
