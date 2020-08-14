#include <stdlib.h>
#include <new>
class MemoryManager {

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

void sayHello();