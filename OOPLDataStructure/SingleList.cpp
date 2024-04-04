//
// Created by Nazar Frazovir on 04.04.2024.
//
#include "SingleList.h"
#include <iostream>


template<typename T>
void SingleList<T>::pushBack(const T &value) {
    std::unique_ptr<Node<T>> newNode = std::make_unique<Node<T>>(value);
    newNode->next = head;
    head = newNode;
    size++;
}

template<typename T>
void SingleList<T>::pushFront(const T &value) {
    std::unique_ptr<Node<T>> newNode = std::make_unique<Node<T>>(value);
    if (head == nullptr){
        head = newNode;
    } else{
        std::shared_ptr<Node<T>> current = head;
        while (current->next != nullptr){
            current = current->next;
            current->next = newNode;
        }
    }
    size++;
}

template<typename T>
void SingleList<T>::popBack() {
    if (head == nullptr)
        throw std::out_of_range("List is empty");
    if(head->next == nullptr){
        head.reset();       // звільнення памʼяті
    }else{
        std::shared_ptr<Node<T>> current = head;
        while (current->next->next != nullptr ){
            current = current->next;
            current->next.reset();
        }
    }
    size--;
}

template<typename T>
void SingleList<T>::popFront() {
    if (head == nullptr)
        throw std::out_of_range("List is empty");
    head = head->next;
    size--;
}

template<typename T>
T &SingleList<T>::operator[](size_t index) const {
    if(index >= size){
        throw std::out_of_range("Index out of range");
    }
    std::shared_ptr<Node<T>> current = head;
    for (size_t i = 0; i < index; ++i) {
        current = current->next;
    }
    return current->data;
}

template<typename T>
void SingleList<T>::insertAt(size_t index, const T &value) {
    if (index>=size)
        throw std::out_of_range("Index out of range");
    if (index == 0){
        pushFront(value);
    }else{
        std::shared_ptr<Node<T>> newNode = std::make_unique<Node<T>>(value);
        std::shared_ptr<Node<T>> current = head;
        for(size_t i = 0; i < index; i++){
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
        size++;
    }
}

template<typename T>
void SingleList<T>::removeAt(size_t index) {
    if (index >= size){
        throw std::out_of_range("Index out of range");
    }
    if (index == 0){
        popFront();
    }else{
        std::shared_ptr<Node<T>> current = head;
        for(size_t i = 0; i < index - 1; i++){
            current = current->next;
        }
        std::shared_ptr<Node<T>> temp = current->next;
        current->next = current->next->next;
        temp.reset();
        size--;
    }

}

template<typename T>
size_t SingleList<T>::Size() {
    return size;
}

template<typename T>
bool SingleList<T>::isEmpty() {
    return size == 0;
}

template<typename T>
bool SingleList<T>::Find(const T &value)const {
    std::shared_ptr<Node<T>> current = head;
    while (current != nullptr){
        if (current->data == value){
            return true;
        }
        current = current->next;
    }
    return false;
}
