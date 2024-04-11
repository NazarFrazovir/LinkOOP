//
// Created by Nazar Frazovir on 11.04.2024.
//

#ifndef OOPLDATASTRUCTURE_STACK_H
#define OOPLDATASTRUCTURE_STACK_H
#include<iostream>
#include "DoubleList.h"

template<typename T>
class Stack {
private:
    DoubleList<T> list;

public:
    Stack() : list() {}

};
#endif //OOPLDATASTRUCTURE_STACK_H
