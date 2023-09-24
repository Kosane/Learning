#include <iostream>
#include <fstream>
#include <ctime>
#include <bitset>

// ���� ⥪�� �뭥� � �⤥��� ����⠭�� ��⮬� �� ���⥫
const std::string GREETINGS = "�ਢ������ ���, � ������� ���짮��⥫�!!!!!!!!!!!!!\n"
                              "� - �ணࠬ��, ����� ������� 䠩�� ���襡�� ��ࠧ��!\n"
                              "�᫨ � ���, � �������, �������� ������᭨��� ��襭�� ������� "
                              "������஢��� 䠩�, �, ���� ⠪ ����, ������ ��� ����� ����!\n"
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
    // ᨤ ��� ࠭����
    srand(time(0));

    // ����⨥ 䠩��
    std::string path; // ���� � 䠩��
    std::cout << GREETINGS; getline(std::cin, path);
    std::ifstream old_file(path, std::ios::in|std::ios::binary);
    std::cout << std::endl << "����讥 ᯠᨡ� �� ����!" << std::endl;

    // ���뢠��� ���祩 �� 䠩��
    int array_size;
    std::bitset<4>* keys = create_keys(old_file, array_size);
    old_file.close();

    // ᮧ����� ᫮���� � ������� �����஢���� ࠭������ ���祩
    std::bitset<4>* new_keys = create_random_keys(array_size);


    char byte; // ᨬ��� ��� �⥭�� 䠩��
    const char* charpath = path.c_str(); // ���� 䠩�� � �ଠ� char* ��� �㭪権 remove � rename

    bool cycle = 1;
    int choose;
    while (cycle){
        std::cout << COMMANDS << std::endl; std::cin >> choose;

        switch (choose){
        case 1:{
            // ������ ᨬ����� � ������� ᫮����
            old_file.open(path, std::ios::in|std::ios::binary);
            // �६���� 䠩�, �㤠 �����뢠� ���� ����
            // ⠪�� ���७�� ⮫쪮 �⮡� � ����� ��砩�� �� �������� ⠪�� 䠩�
            std::ofstream new_file("temp_file.cxc", std::ios::out|std::ios::binary);
            if (old_file){
                while(old_file.get(byte)){
                    new_file << encode_byte(byte, keys, new_keys, array_size);
                }
            }

            // ����뢠�� 䠩����, ��२�����뢠��
            old_file.close();
            new_file.close();
            remove(charpath);
            rename("temp_file.cxc", charpath);

            std::cout << "�ᯥ譮 ����஢���!" << std::endl << std::endl;
        }
            break;
        case 2:{
            // ������ ᨬ����� � ������� ᫮����
            old_file.open(path, std::ios::in|std::ios::binary);
            std::ofstream new_file("temp_file.cxc", std::ios::out|std::ios::binary); // �६���� 䠩�, �㤠 �����뢠� ���� ����
            if (old_file){
                while(old_file.get(byte)){
                    new_file << encode_byte(byte, new_keys, keys, array_size); // ��� ���� �������� ���⠬� keys � new_keys
                }
            }

            // ����뢠�� 䠩����, ��२�����뢠��
            old_file.close();
            new_file.close();
            remove(charpath);
            rename("temp_file.cxc", charpath);

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

// �뢮� �����
void print_bitset(std::bitset<4> binary_num1){
    for(int i = 0; i < 4; i++){
        std::cout << (binary_num1[i]);
    }
}

// �஢�ઠ, ���� �� ����� � ���ᨢ� ����⮢
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

// ���� ������ �����
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


// ᮧ����� ���ᨢ� ����⮢ �� 䠩��
std::bitset<4>* create_keys(std::ifstream& file, int& array_size){
    std::bitset<4> *keys = new std::bitset<4>[16];
    int number_of_keys = 0;

    char byte;
    if (file){
        while(file.get(byte) and number_of_keys < 16){
            // 2 �����, � ���஬ �࠭���� ���� 4 � ��᫥���� 4 ��� �祩�� �����
            std::bitset<4> binary_num1;
            // ��࠭���� ��⮢ � �����
            for(int i = 7; i >= 4; i--){
                binary_num1[7-i] = ( (byte >> i) & 1);
            }

            std::bitset<4> binary_num2;
            for(int i = 3; i >= 0; i--){
                binary_num2[3-i] = ( (byte >> i) & 1);
            }

            // �������� �� ������, �᫨ �� ��� ��� � ���ᨢ� ���ᨢ��
            // (ࠧ��� ���ᨢ� = number_of_keys �⮡� �஢�ઠ �� ���ࠣ����� ������, ����� ��� �� �뫮 ��᢮��� ���祭��
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


// ᮧ����� ࠭������� ���ᨢ� ����⮢ (��室�� �㪢� ��䠢��)
std::bitset<4>* create_random_keys(int array_size){
    std::bitset<4>* keys = new std::bitset<4>[array_size];

    std::bitset<4> temp_num;

    for (int i = 0; i < array_size; i++){
        do {
            for (int j = 0; j < 4; j++){
                temp_num[j] = rand() % 2; // ࠭����� bool
            }
        } while (elem_is_in_array(temp_num, keys, i)); // ��� ⠪ �� ࠧ��� ���ᨢ� = i �⮡� �� �஢����� ��譨� ������

        for (int j = 0; j < 4; j++){
            keys[i] = temp_num;
        }
    }
    return keys;
}

// �뢮� ����⮢, ���᫥��⢨� �� �ᯮ�짮���, ����� ���� �� ࠡ�⠥�
void show_bitsets(std::bitset<4>* array, int array_size){
    for (int j = 0; j < array_size; j++){
        for (int i = 0; i < 4; i++){
            std::cout << array[j][i];
        }
        std::cout << std::endl;
    }
}

// �뢮� ᫮���� ����஢����
void show_dict(std::bitset<4>* array1, std::bitset<4>* array2, int arrays_size){
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

    // ॢ������ ����� ��⮬� �� ��� ����� ��祬�-� ���ࠢ��쭮 ࠡ�⠥� � �����ᠬ�, � ������ ������� � 横��� 㦥 ����
    for(int i = 0; i < 4; i++) {
        bool t = temp_num[i];
        temp_num[i] = temp_num[8-i-1];
        temp_num[8-i-1] = t;
    }

    new_byte = static_cast<char>(temp_num.to_ulong());
    return new_byte;
}
