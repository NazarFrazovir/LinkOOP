//
// Created by Nazar Frazovir on 11.04.2024.
//

#ifndef OOPLDATASTRUCTURE_STACKARRAY_H
#define OOPLDATASTRUCTURE_STACKARRAY_H
#include <iostream>

template<typename T>
class StackArray{
private:
    T* elements;
    size_t capacity;
    size_t top;
public:

    StackArray(size_t initialCapacity = 10):capacity(initialCapacity),top(0){
        elements= new T[capacity];
    }
    ~StackArray(){
        delete[] elements;
    }

};
#endif //OOPLDATASTRUCTURE_STACKARRAY_H
