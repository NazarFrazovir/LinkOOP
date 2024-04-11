//
// Created by Nazar Frazovir on 11.04.2024.
//

#ifndef OOPLDATASTRUCTURE_CIRCULARQUEUE_H
#define OOPLDATASTRUCTURE_CIRCULARQUEUE_H
#include <iostream>
#include "DoubleList.h"

template<typename T>
class CircularQueue {
private:
    DoubleList<T> list;
    size_t capacity;  // ---- Макс. місткість черги
public:
    CircularQueue() = default;

    CircularQueue(size_t capacity) : list(), capacity(capacity) {}

};
#endif //OOPLDATASTRUCTURE_CIRCULARQUEUE_H
