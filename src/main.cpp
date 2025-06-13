#include "uci.hpp"

#include <string>
#include <iostream>

int main(){
    while(true){
        std::string command;
        std::getline(std::cin, command);
        parse_command(command);
    }
}
