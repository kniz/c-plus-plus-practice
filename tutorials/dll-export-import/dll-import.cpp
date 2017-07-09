#include "dll-export.hpp"

int main()
{
    A a;
    a.print();

    return 0;
}

// g++ -o dll-import.exe dll-import.cpp dll-export.so