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

    //---Метод видалення--
    void popBack();
    void popFront();

    //---Додавання та віднімання за індексом--
    void insertAt(size_t index, const T& value);
    void removeAt(size_t index);

    //---Методи для роботи з розміром---
    size_t Size() const { return size; }
    bool isEmpty() const { return size == 0; }

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

template<typename T>
void DoubleList<T>::popBack() {
    if (tail == nullptr)
        throw std::out_of_range("List is empty");
    if (head == tail) {
        head.reset();
    } else {
        tail->prev->next.reset();
    }
    tail = tail->prev;
    size--;
}

template<typename T>
void DoubleList<T>::popFront() {
    if (head == nullptr)
        throw std::out_of_range("List is empty");
    if (head == tail) {
        tail.reset();
    } else {
        head->next->prev.reset();
    }
    head = head->next;
    size--;
}

template<typename T>
void DoubleList<T>::insertAt(size_t index, const T& value) {
    if (index > size)
        throw std::out_of_range("Index out of range");
    if (index == 0) {
        pushFront(value);
    } else if (index == size) {
        pushBack(value);
    } else {
        std::shared_ptr<Node2<T>> current = getNode(index);
        std::unique_ptr<Node2<T>> newNode = std::make_unique<Node2<T>>();
        newNode->data = value;
        newNode->next = current;
        newNode->prev = current->prev;
        current->prev->next.reset(newNode.release());
        current->prev = current->prev->next;
        size++;
    }
}

template<typename T>
void DoubleList<T>::removeAt(size_t index) {
    if (index >= size)
        throw std::out_of_range("Index out of range");
    if (index == 0) {
        popFront();
    } else if (index == size - 1) {
        popBack();
    } else {
        std::shared_ptr<Node2<T>> current = getNode(index);
        current->prev->next = current->next;
        current->next->prev = current->prev;
        size--;
    }
}




#endif //OOPLDATASTRUCTURE_DOUBLELIST_H
