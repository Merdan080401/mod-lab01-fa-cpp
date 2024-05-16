#include <iostream>
#include "fun.h"

int main() {
    const char *str = "Hello World 123Hello hello world world";
    
    std::cout << "Задание 1: " << faStr1(str) << std::endl;
    std::cout << "Задание 2: " << faStr2(str) << std::endl;
    std::cout << "Задание 3: " << faStr3(str) << std::endl;

    return 0;
}
