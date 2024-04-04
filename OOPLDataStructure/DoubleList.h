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

}
#endif //OOPLDATASTRUCTURE_DOUBLELIST_H
