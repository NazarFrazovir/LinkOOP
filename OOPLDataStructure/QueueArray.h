//
// Created by Nazar Frazovir on 11.04.2024.
//

#ifndef OOPLDATASTRUCTURE_QUEUEARRAY_H
#define OOPLDATASTRUCTURE_QUEUEARRAY_H

#include <iostream>

template<typename T>
class QueueArray{
private:
    T element[SIZE];
    int front;
    int rear;
public:
    QueueArray(){
        front = -1;
        rear = -1;
    }

    bool isEmpty() const {
        return front == -1 && rear == -1;
    }
    bool isFull()const{
        return rear == SIZE - 1;
    }
    void enqueue(T value){
        if (isFull()){
            throw std::overflow_error("Queue is full");
        }
        if (isEmpty()){
            front = rear = 0;
        }else{
            rear++;
        }
        element[rear] = value;
//        std::cout<<"Enqueued: "<<value<<std::endl;
    }
    T dequeue(){
        if (isEmpty()){
            throw std::underflow_error("Queue is empty");
        }
        T removedElem = element[front];
        if (front == rear){
            front = rear = -1;
        }else{
            front++;
        }
//        std::cout << "Dequeued: " << removedElem << std::endl;
        return removedElem;
    }
    T peek(){
        if (isEmpty()){
            throw std::out_of_range("Queue is empty");
        }
        return element[front];
    }

    friend std::ostream& operator<<(std::ostream& os, const QueueArray<T>& queue) {
        if (queue.isEmpty()) {
            os << "Queue is empty";
        } else {
            int i = queue.front;
            while (i != queue.rear) {
                os << queue.element[i] << " ";
                i = (i + 1) % SIZE;
            }
            os << queue.element[i];
        }
        return os;
    }
};
#endif //OOPLDATASTRUCTURE_QUEUEARRAY_H
