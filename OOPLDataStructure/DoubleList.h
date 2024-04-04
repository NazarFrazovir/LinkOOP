//
// Created by Nazar Frazovir on 05.04.2024.
//

#ifndef OOPLDATASTRUCTURE_DOUBLELIST_H
#define OOPLDATASTRUCTURE_DOUBLELIST_H
#include <iostream>
#include "memory"

template<typename T>
struct Node2 {
    T data;
    std::shared_ptr<Node2<T>> next;
    std::shared_ptr<Node2<T>> prev;
};

template<typename T>
class DoubleList {
private:
    std::shared_ptr<Node2<T>> head;
    std::shared_ptr<Node2<T>> tail;
    size_t size;

    std::shared_ptr<Node2<T>> getNode(size_t index) const;

public:
    DoubleList() : head(nullptr), tail(nullptr), size(0) {}

    //---Метод вставки---
    void pushBack(const T& value);
    void pushFront(const T& value);


};

template<typename T>
void DoubleList<T>::pushBack(const T& value) {
    std::unique_ptr<Node2<T>> newNode = std::make_unique<Node2<T>>();
    newNode->data = value;
    newNode->next = nullptr;
    newNode->prev = tail;
    if (tail != nullptr) {
        tail->next = std::move(newNode);
        tail = tail->next;
    } else {
        head = std::move(newNode);
        tail = head;
    }
    size++;
}

template<typename T>
void DoubleList<T>::pushFront(const T& value) {
    std::unique_ptr<Node2<T>> newNode = std::make_unique<Node2<T>>();
    newNode->data = value;
    newNode->next = head;
    newNode->prev = nullptr;
    if (head != nullptr) {
        head->prev = std::move(newNode);
    } else {
        tail = std::move(newNode);
    }
    head = newNode->prev;
    size++;
}
#endif //OOPLDATASTRUCTURE_DOUBLELIST_H
