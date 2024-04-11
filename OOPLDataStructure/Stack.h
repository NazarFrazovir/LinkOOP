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

    bool IsEmpty() const{
        return list.isEmpty();
    }

    T Peek()const{
        if (list.isEmpty()){
            throw std::out_of_range("Stack is empty");
        }
        return list[Size() - 1];
    }

    void Push(const T& value){
        list.pushBack(value);
    }

    T Pop(){
        if (IsEmpty()){
            throw std::underflow_error("Stack is empty");
        }
        T value = list[Size() - 1];
        list.popBack();
        return value;
    }

    size_t Size()const{
        return list.Size();
    }

    friend std::ostream& operator<<(std::ostream& os, const Stack<T>& stack) {
        os << stack.list;
        return os;
    }
};
#endif //OOPLDATASTRUCTURE_STACK_H
