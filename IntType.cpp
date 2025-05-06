#include "IntType.h"
#include <iostream>
#include <fstream>
namespace Type{
    void IntType::spinToLeft() {
        std::ifstream file(path);
        std::string type;
        std::getline(file, type);
        file.close();
        while(type[pos] != ' ' & pos != 0){
            --pos;
        }
        pos = pos ? pos - 1 : 0;
    }
    void IntType::spinToRight(){
        std::ifstream file(path);
        std::string type;
        std::getline(file, type);
        file.close();
        while(type[pos] != ' ' & pos != 0){
            --pos;
        }
        pos = type[pos] != '\0' ? pos + 1 : pos - 1;
    }
    int IntType::read(){
        std::ifstream file(path);
        std::string type;
        std::getline(file, type);
        file.close();
        std::string number;
        int temp = pos;
        while(type[temp] != ' ' & temp != 0){
          --temp;
        }
        temp = temp ? temp + 1 : 0;
        while(type[temp] != ' ' & type[temp] != '\0'){
            number += type[temp];
        }
        int result = std::stoi(number);
        return result;
    }
    void IntType::write(int value){
        std::fstream file(path);
        std::string type;
        std::string number;
        std::getline(file, type);
        number = std::to_string(value);
        int temp = pos;
        while(type[temp] != ' ' & type[temp] != '\0'){
            ++temp;
        }
        std::string end;
        std::copy(type.begin() + temp, type.end(), std::back_inserter(end));
        --temp;
        while(type[temp] != ' ' & temp != '0'){
            --temp;
        }
        std::copy(number.begin(), number.end(), type.begin() + temp);
        std::copy(end.begin(), end.end(), type.begin() + temp + number.size());
        type += '\0';
        file << type;
        file.close();
    }
}