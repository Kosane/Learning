#include <iostream>
#include <string>
#include <fstream>
#include <math.h>
#include <ctime>

// ���� ⥪�� �뭥� � �⤥��� ����⠭�� ��⮬� �� ���⥫
const std::string GREETINGS = "�ਢ������ ���, � ������� ���짮��⥫�!!!!!!!!!!!!!\n"
                              "� - �ணࠬ��, ����� ������� 䠩�� ���襡�� ��ࠧ��!\n"
                              "�᫨ � ���, � �������, �������� ������᭨��� ��襭�� ������� "
                              "������஢��� 䠩�, �, ���� ⠪ ����, ������ ��� ����� ����! "
                              "� � �ॢ������ 㤮�����⢨�� ᤥ��� ��� ��吝�� ࠡ���!\n"
                              "����� ���� 䠩��: ";

const std::string COMMANDS =  "���᮪ ������.\n"
                              "1. ������஢��� 䠩�.\n"
                              "2. ������஢��� 䠩�.\n"
                              "3. �뢥�� ᫮���� ����஢����.\n"
                              "0. �������� ࠡ��� �ணࠬ��.\n"
                              "������ ����� �������:";

const std::string CASE_ERROR = "�訡�窠: �������, �� ����� ������ ����� �������.\n";

const std::string FAREWELL = "�ᥣ�! ���! ����!";

// ���⨯� �㭪権
int decimal_from_bin(bool* array, int size);
bool elem_is_in_array(bool* elem, bool** array, int array_size);
int index_of_elem(bool* elem, bool** array, int array_size);
bool** create_keys(std::ifstream& file, int& array_size);
bool** create_random_keys(int array_size);
void show_array(bool** array, int array_size);
void show_dict(bool** array1, bool** array2, int arrays_size);
std::string encode_string(std::string old_string, bool** keys, bool** new_keys, int array_size);

int main(){
    // ᨤ ��� ࠭����
    srand(time(0));

    // ����⨥ 䠩��
    std::string path; // ���� � 䠩��
    std::cout << GREETINGS; getline(std::cin, path);
    std::ifstream old_file(path);
    std::cout << std::endl << "����讥 ᯠᨡ� �� ����!" << std::endl;

    // ���뢠��� ���祩 �� 䠩��
    int array_size;
    bool** keys = create_keys(old_file, array_size);
    old_file.close();

    // ᮧ����� ᫮���� � ������� �����஢���� ࠭������ ���祩
    bool** new_keys = create_random_keys(array_size);

    std::string line; // ��ப� ��� �⥭�� 䠩��
    const char* charpath = path.c_str(); // ���� 䠩�� � �ଠ� char* ��� �㭪権 remove � rename

    bool cycle = 1;
    int choose;
    while (cycle){
        std::cout << COMMANDS << std::endl; std::cin >> choose;

        switch (choose){
        case 1:{
            // ������ ᨬ����� � ������� ᫮����
            old_file.open(path);
            std::ofstream new_file("temp_file.txt"); // �६���� 䠩�, �㤠 �����뢠� ���� ����
            if (old_file){
                while(getline(old_file, line)){
                    new_file << encode_string(line, keys, new_keys, array_size) << std::endl;
                }
            }

            // ����뢠�� 䠩����, ��२�����뢠��
            old_file.close();
            new_file.close();
            remove(charpath);
            rename("temp_file.txt", charpath);

            std::cout << "�ᯥ譮 ����஢���!" << std::endl << std::endl;
        }
            break;
        case 2:{
            // ������ ᨬ����� � ������� ᫮����
            old_file.open(path);
            std::ofstream new_file("temp_file.txt"); // �६���� 䠩�, �㤠 �����뢠� ���� ����
            if (old_file){
                while(getline(old_file, line)){
                    new_file << encode_string(line, new_keys, keys, array_size) << std::endl; // ��� ���� �������� ���⠬� keys � new_keys
                }
            }

            // ����뢠�� 䠩����, ��२�����뢠��
            old_file.close();
            new_file.close();
            remove(charpath);
            rename("temp_file.txt", charpath);

            std::cout << "�ᯥ譮 ������஢���!" << std::endl << std::endl;
        }
            break;
        case 3:
                // �뢮� ᫮����
                std::cout << "�������:" << std::endl;
                show_dict(keys, new_keys, array_size);
            break;
        case 0: cycle = 0; break;
        default: std::cout << CASE_ERROR << std::endl; break;
        }
    }

    std::cout << FAREWELL << std::endl;
    return 0;
}









// �㭪樨


// ��ॢ�� �� ���ᨢ� bool � ����筮� �᫮ int
int decimal_from_bin(bool* number, int size){
    int result = 0;
    for (int i = 0; i < size; i++){
        result += number[i]*pow(2, size-1-i);
    }
    return result;
}


// �஢�ઠ, ���� �� ���ᨢ bool � ���ᨢ� ���ᨢ��
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

// ���� ������ �����
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


// ᮧ����� ���ᨢ� ���ᨢ�� bool �� 䠩��
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



                // 2 ���ᨢ� bool, � ���஬ �࠭���� ���� 4 � ��᫥���� 4 ��� �祩�� �����
                bool *binary_num1 = new bool[4];
                // ��ॢ�� �� ᨬ���� � bool
                for(int i = 7; i >= 4; i--){
                    binary_num1[7-i] = ( ( line[j] >> i ) & 1 ? 1 : 0 );
                }

                bool *binary_num2 = new bool[4];
                for(int i = 3; i >= 0; i--){
                    binary_num2[3-i] = ( ( line[j] >> i ) & 1 ? 1 : 0 );
                }

                // �������� �� ���ᨢ�, �᫨ �� ��� ��� � ���ᨢ� ���ᨢ��
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


// ᮧ����� ࠭������� ���ᨢ� ���ᨢ�� bool (��室�� �㪢� ��䠢��)
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

// �뢮� ���ᨢ�, ���᫥��⢨� �� �ᯮ�짮���, ����� ���� �� ࠡ�⠥�
void show_array(bool** array, int array_size){
    for (int j = 0; j < array_size; j++){
        for (int i = 0; i < 4; i++){
            std::cout << array[j][i];
        }
        std::cout << std::endl;
    }
}



// �뢮� ᫮���� ����஢����
void show_dict(bool** array1, bool** array2, int arrays_size){
    std::cout << "�㪢� ��.\t�㪢� ���." << std::endl;
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





// �� � ᮡ�⢥��� ������� �㭪��, ����� ������� ����� � ᮮ⢥�ᢨ� � ᫮����
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
