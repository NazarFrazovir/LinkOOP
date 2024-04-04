//
// Created by Nazar Frazovir on 04.04.2024.
//

#ifndef OOPLDATASTRUCTURE_SINGLELIST_H
#define OOPLDATASTRUCTURE_SINGLELIST_H
#include <iostream>
#include "memory"


template<typename T>
struct Node{
    T data;
    std::shared_ptr<Node<T>> next;

};

template<typename T>
class SingleList{
private:
    std::shared_ptr<Node<T>> head;
    size_t size;
public:
    SingleList():head(nullptr),size(0){}

    //--- Методи вставки---
    void pushFront(const T& value);
    void pushBack(const T& value);

    //--- Методи видалення---
    void popFront();
    void popBack();

    //---Доступ до елементів---
    T& operator[](size_t index)const;

    //---Додавання та віднімання за індексом---
    void insertAt(size_t index,const T& value);
    void removeAt(size_t index);

};


#endif //OOPLDATASTRUCTURE_SINGLELIST_H
