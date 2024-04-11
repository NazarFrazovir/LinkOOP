//
// Created by Nazar Frazovir on 11.04.2024.
//

#ifndef OOPLDATASTRUCTURE_CIRCULARQUEUEARRAY_H
#define OOPLDATASTRUCTURE_CIRCULARQUEUEARRAY_H
#include <iostream>
template<typename T>
class CircularQueueArray{
private:
//    std::shared_ptr<T>elements;
    T* elements;
    int front;
    int rear;
    int capacity;
    int currentSize;
public:
    CircularQueueArray(int size = 10):capacity(size),front(-1),rear(-1),currentSize(0){
//        elements = std::make_shared<T>(capacity);
            elements = new T[capacity];
    }
    ~CircularQueueArray(){
        delete[] elements;
    }


};
#endif //OOPLDATASTRUCTURE_CIRCULARQUEUEARRAY_H
