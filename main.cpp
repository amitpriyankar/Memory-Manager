#include <iostream>
#include "MemoryManager.h"


int main()
{
    int *x = new int;
    delete x;
    sayHello();
}