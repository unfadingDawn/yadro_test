#include "IntType.h"
#include <iostream>
#include <fstream>
#include <thread>
#include <unistd.h>

namespace Tape{
    void IntTape::spinToLeft() {
        std::this_thread::sleep_for(delay);
        std::ifstream file(path);
        std::string type;
        std::getline(file, type);
        file.close();
        while(type[pos] != ' ' & pos != 0){
            --pos;
        }
        pos = pos ? pos - 1 : 0;
    }
    void IntTape::spinToRight(){
        std::this_thread::sleep_for(delay);
        std::ifstream file(path);
        std::string type;
        std::getline(file, type);
        file.close();
        while(type[pos] != ' ' & type[pos] != '\0'){
            ++pos;
        }
        if(type[pos] == ' ') {
            ++pos;
        }
        if(type[pos] == '\0') {
            type += ' ';
            type += '0';
            pos += 1;
            std::ofstream file_write(path, std::ios::trunc);
            file_write << type;
            file_write.close();
        }
    }
    int IntTape::read(){
        std::this_thread::sleep_for(delay);
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
            ++temp;
        }
        int result = std::stoul(number);
        return result;
    }
    void IntTape::write(int value){
        std::this_thread::sleep_for(delay);
        std::ifstream file(path);
        std::string type;
        std::string number;
        std::getline(file, type);
        file.close();
        number = std::to_string(value);
        int temp = pos;
        while(type[temp] != ' ' && temp != 0){
            --temp;
        }
        std::string start;
        std::copy(type.begin(), type.begin() + temp, std::back_inserter(start));
        if (temp != 0) {
            ++temp;
        }
        while(type[temp] != ' ' && type[temp] != '\0'){
            ++temp;
        }
        int end_of_number = temp;
        std::string end;
        std::copy(type.begin() + end_of_number, type.end(), std::back_inserter(end));
        std::ofstream file_write(path, std::ios::trunc);
        if (!start.empty()) {
           start += ' ';
        }
        file_write << start;
        file_write << number;
        file_write << end;
        file_write.close();
    }
}
