#include <iostream>
#include "MemoryManager.h"


int main()
{
    int *x = new int;
    delete x;

    MemoryManager manager;
    
    manager.AddNewPool(1, 1);
    manager.AddNewPool(1, 2);

    manager.DeletePool(1);
    manager.AddNewPool(1, 3);
    manager.DeletePool(5);
    manager.DeletePool(2);
    manager.DeletePool(3);
    
}