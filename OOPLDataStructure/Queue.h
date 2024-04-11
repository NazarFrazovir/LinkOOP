//
// Created by Nazar Frazovir on 11.04.2024.
//

#ifndef OOPLDATASTRUCTURE_QUEUE_H
#define OOPLDATASTRUCTURE_QUEUE_H
#include "DoubleList.h"
#include <iostream>
const int SIZE = 5;


template<typename T>
class Queue{
private:
    DoubleList<T> list;
public:
    Queue() = default;
    Queue(const Queue& other) = default;
    Queue(Queue&& other) = default;

    ~Queue() = default;

    Queue& operator=(const Queue& other) = default;
    Queue& operator=(Queue&& other) noexcept = default;
};
#endif //OOPLDATASTRUCTURE_QUEUE_H
