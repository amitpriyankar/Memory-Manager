#include "MemoryPool.h"
#include <iostream>

MemoryPool::MemoryPool(int ID, void* original, void* alligned)
{
    PoolID = ID;
    OriginalMemoryPointer = original;
    AllignedMemoryPointer = alligned;

}
MemoryPool::~MemoryPool()
{
    // std::cout << "hi " << std::endl;
}
void* MemoryPool::GetOriginalMemoryStart()
{
    return OriginalMemoryPointer;
}

int MemoryPool::GetPoolID()
{
    return PoolID;
}


MemoryPool* MemoryPool::GetNextPool()
{
    return NextPool;
}

MemoryPool* MemoryPool::GetPrevPool()
{
    return PrevPool;
}

void MemoryPool::SetNextPool(MemoryPool* next)
{
    NextPool = next;
}

void MemoryPool::SetPrevPool(MemoryPool* prev)
{
    PrevPool = prev;
}