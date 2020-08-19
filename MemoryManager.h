#include <stdlib.h>
#include <new>
#include "MemoryPool.h"
class MemoryManager 
{
private:

    // a default poolID for pools
    int DefaultPoolID;

    // pointer pointing to the first pool in the list of pools
    MemoryPool *FirstPool;

    // pointer pointing to the last pool in the list of pools 
    MemoryPool *LastPool;

    // this function will return pointer to the alligned memory address of a new memory pool
    void* AllignedMalloc(const size_t requiredBytes, const size_t allignment, void** original);
    
public:

    // constructor
    MemoryManager();

    // destructor
    ~MemoryManager();

    // method to add new pool
    // poolSize in KBs
    void AddNewPool(const int poolSize, const int poolID);

    // delete the pool for the given ID
    void DeletePool(const int poolID);

    // a method to print the error on the screen
    void debugString(const char* errorMessage);


    // getter function for FirstPool
    MemoryPool* getFirstPool();

    // getter function for LastPool
    MemoryPool* getLastPool();

    // setter function for FirstPool
    void setFirstPool(MemoryPool* firstPool);

    // setter function for LastPool
    void setLastPool(MemoryPool* lastPool);

}; 



// Overloaded new and delete operators
void* operator new  (std::size_t count );
void* operator new[](std::size_t count );
void* operator new  (std::size_t count, const std::nothrow_t& tag);
void* operator new[](std::size_t count, const std::nothrow_t& tag);

void operator delete  (void* ptr); 	
void operator delete[](void* ptr);
void operator delete  (void* ptr, const std::nothrow_t& tag);
void operator delete[](void* ptr, const std::nothrow_t& tag);

