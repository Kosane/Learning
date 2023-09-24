#include <iostream>
#include <fstream>
#include <bitset>

// потом я понял что эта функция не нужна потому что в классе битсетов и так уже реализован оператор <<. Правда он выводит элементы с конца.
void print_bitset(std::bitset<4> binary_num1){
    for(int i = 0; i < 4; i++){
        std::cout << (binary_num1[i]);
    }
}




int main()
{


    std::ifstream old_file("Text.txt", std::ios::in|std::ios::binary);
    std::ofstream new_file("temp_file.txt", std::ios::out|std::ios::binary);



    std::string line; // строка для чтения файла
    std::bitset<4> keys[16];
    std::bitset<4> binary_num1;
    if (old_file.is_open()){
        char byte;
        int i = 0;
        while(old_file.get(byte)){
            for(int i = 7; i >= 4; i--){
                binary_num1.set(i-4, ((byte >> i) & 1));
                keys[0] = binary_num1;
                print_bitset(keys[0]);
//                std::cout << binary_num1;
                std::cout << std::endl;
//                getchar();
            }
            i++;
            if (i > 5){break;}
        }
    }





    return 0;
}
