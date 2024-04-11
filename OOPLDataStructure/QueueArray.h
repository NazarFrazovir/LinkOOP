//
// Created by Nazar Frazovir on 11.04.2024.
//

#ifndef OOPLDATASTRUCTURE_QUEUEARRAY_H
#define OOPLDATASTRUCTURE_QUEUEARRAY_H

#include <iostream>
const int SIZE = 5;

template<typename T>
class QueueArray{
private:
    T element[SIZE];
    int front;
    int rear;
public:
    QueueArray(){
        front = -1;
        rear = -1;
    }
    
};
#endif //OOPLDATASTRUCTURE_QUEUEARRAY_H
