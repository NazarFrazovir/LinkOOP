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