#include "MemoryManager.h"
#include <iostream> // for debugging purpose
#include <malloc.h>
MemoryManager::MemoryManager()
{
    FirstPool = nullptr;
    LastPool = nullptr;
}


MemoryManager::~MemoryManager()
{

}

void MemoryManager::AddNewPool(const int poolSize, const int poolID)
{
    void* allignedPoolPointer;      // alligned pointer pointing to the memory from where the pool starts
    void* allignedMemoryPointer;    // alligned pointer pointing to the memory from which the free space starts
    void* originalPoolPointer;      // pointer pointing to the start address of the allocated space
    MemoryPool* newPool;

    // allocate the memory(alligned) then use placement new to correction call the constructor 

    /*
        In 64-bit architecture, we can have a long double which takes 16 bytes of memory
        therfore, the allignement needs to done w.r.t 16 bytes. Hence, the memory address returned
        by the function should be divisible by 16.
    */
    allignedPoolPointer = AllignedMalloc(poolSize * 1024, 16, &originalPoolPointer);
   
    if(allignedPoolPointer == nullptr)
    {
        // execption handling if a new pool cannot be created
        return;
    }
  
    allignedMemoryPointer = reinterpret_cast<void *>(reinterpret_cast<long unsigned int>(allignedPoolPointer) + sizeof(MemoryPool));
    
    newPool = new(allignedPoolPointer) MemoryPool(poolID, originalPoolPointer, allignedMemoryPointer);


    // Update the Memory Manager and Memory Pool Pointers
  
    if(FirstPool == nullptr)
    {
        FirstPool = newPool;
        LastPool = newPool;
        FirstPool->SetPrevPool(nullptr); 
        LastPool->SetNextPool(nullptr);

    }
    else 
    {
        LastPool->SetNextPool(newPool);
        newPool->SetPrevPool(LastPool);
        LastPool = newPool;
        LastPool->SetNextPool(nullptr); 
    }
    
    //debugging
    // MemoryPool* cur = FirstPool;
    // char string[500];
    // while(cur != nullptr)
    // {
    //     sprintf(string, "%d -> ", cur->GetPoolID());   
    //     debugString(string);
    //     cur = cur->GetNextPool();
    // }
    // debugString("\n");

    
    return;
}

void MemoryManager::DeletePool(const int poolID)
{
    MemoryPool* cur = FirstPool;

    // search for the pool which needs to be deleted
    char string[500];

    while(cur != nullptr)
    {
        if(cur->GetPoolID() == poolID)
            break;
        cur = cur->GetNextPool();
    }

    if(cur == nullptr)
    {
        // memory pool with poolID is not present
        return;
    }
    else if(cur == FirstPool)
    {
        FirstPool = FirstPool->GetNextPool();
    }
    else if(cur == LastPool)
    {
        LastPool = LastPool->GetPrevPool();
    }
    else
    {
        cur->GetPrevPool()->SetNextPool(cur->GetNextPool());
        cur->GetNextPool()->SetPrevPool(cur->GetPrevPool());
    }

    // deleting the pool and freeing the memory
    void* memoryStart = cur->GetOriginalMemoryStart();
    cur->~MemoryPool();
    free(memoryStart);


    // debugging
    // cur = FirstPool;
    // while(cur != nullptr)
    // {
    //     sprintf(string, "%d -> ", cur->GetPoolID());   
    //     debugString(string);
    //     cur = cur->GetNextPool();

    // }
    // debugString("\n");


    return;
}


void* MemoryManager::AllignedMalloc(const size_t requiredBytes, const size_t allignment, void** original)
{
    void* alligned;    

    // offset denotes how extra memory would be required if we want alligned pointer
    // pointing to the memory address which also stores the information of class MemoryPool itself
    size_t offset;

    offset = allignment - 1 + sizeof(MemoryPool);

    *original = malloc(requiredBytes + offset);

   
    if(*original == nullptr)
    {
        debugString("Memory pool allocator problem");
        return nullptr;
    }

    /*
        Since, allignment is always going to be in power of 2. Let's assume if it is 16 i.e. 0...00010000
        (allignment - 1)  => 0...00001111
        ~(allignment - 1) => 1...11110000
        Now, if we'll AND this value to any integer then it we will get an integer which is largest integer less
        than the orginal one which is divisible by 16. That basically means, we have got alligned integer. 
    */
    alligned = reinterpret_cast<void*>(reinterpret_cast<size_t>(*original) + (offset & ~(allignment - 1))- sizeof(MemoryPool));


    return alligned;

}


void MemoryManager::debugString(const char* errorMessage)
{
    std::cout << errorMessage;
}


MemoryPool* MemoryManager::getFirstPool()
{
    return FirstPool;
}

MemoryPool* MemoryManager::getLastPool()
{
    return LastPool;
}


void MemoryManager::setFirstPool(MemoryPool* firstPool)
{
    FirstPool = firstPool;
}

void MemoryManager::setLastPool(MemoryPool* lastPool)
{
    LastPool = lastPool;
}















void* operator new  (std::size_t count ) {
    return malloc(count);
}

void* operator new[](std::size_t count ) {

}

void* operator new  (std::size_t count, const std::nothrow_t& tag) {

}

void* operator new[](std::size_t count, const std::nothrow_t& tag) {

}

void operator delete  (void* ptr) {
    free(ptr);
} 	

void operator delete[](void* ptr) {

}

void operator delete  (void* ptr, const std::nothrow_t& tag) {

}

void operator delete[](void* ptr, const std::nothrow_t& tag) {

}


