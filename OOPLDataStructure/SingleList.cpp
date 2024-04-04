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