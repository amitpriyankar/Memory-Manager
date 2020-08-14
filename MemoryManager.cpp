#include "MemoryManager.h"
#include <iostream> // for debugging purpose



void* operator new  (std::size_t count ) {
    std::cout << "overloaded new" << std::endl;
    return malloc(count);
}

void* operator new[](std::size_t count ) {

}

void* operator new  (std::size_t count, const std::nothrow_t& tag) {

}

void* operator new[](std::size_t count, const std::nothrow_t& tag) {

}

void operator delete  (void* ptr) {
    std::cout << "overloaded delete" << std::endl;
    free(ptr);
} 	

void operator delete[](void* ptr) {

}

void operator delete  (void* ptr, const std::nothrow_t& tag) {

}

void operator delete[](void* ptr, const std::nothrow_t& tag) {

}


//debuugging
void sayHello() {
    std::cout << "Hello" << std::endl;
}