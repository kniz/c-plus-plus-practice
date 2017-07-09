#include "dll-export.hpp"
#include <iostream>
void A::print() {
    std::cout << "A::print()\n";
}

// g++ -fPIC -shared dll-export.cpp -o dll-export.so