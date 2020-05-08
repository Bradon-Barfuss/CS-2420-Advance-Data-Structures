//
// Created by bradon on 2/26/20.
//

#ifndef QUEUE_QUEUE_H
#define QUEUE_QUEUE_H

#include "ostream"
using namespace std;

template <class Type>
struct Node{
    Type data;
    Node* next;
};

template <class Type>
class Queue;

template <class Type>
std::ostream& operator<<(std::ostream&, const Queue<Type>& list);


template <class Type>
class Queue{
public:
    Queue(); //DONE
    Queue(const Queue &other);
    ~Queue();
    void enqueue(Type item);//Add item at end of queue
    void dequeue();//remove item at the front of the queue
    Type peek();//return value of the item at the front of the queue
    int size();
    bool empty();
    void clear();
    friend std::ostream& operator<< <>(std::ostream&, const Queue<Type>& list);

protected:
    Node<Type>* front;
    Node<Type>* back;
    int count;
};

template <class Type>
Queue<Type>::Queue() {
    front = nullptr;
    back = nullptr;
    count = 0;
}

template<class Type>
Queue<Type>::Queue(const Queue &other) {
    back = nullptr;
    front = nullptr;

    auto hold = other.front;
    for (int i = 0; i < other.count; ++i) {

        if(hold != NULL) {
            enqueue(hold->data);
            hold = hold->next;
        }
    }
}

template<class Type>
Queue<Type>::~Queue() {}

template<class Type>
void Queue<Type>::enqueue(Type item) {
    auto *temp = new Node<Type>();//create the new node
    temp->data = item;//set the new node data
    count++;
    if (!front) {//since we are putting data at the end of the linked list, we will check if it the end of the list or not
        this->front = temp;
        this->back = temp;
    } else {//if it is the end of a list
        temp->next = nullptr;//set the next value to null (last item in the list)
        back->next = temp;//go back a node, and set that nodes next value to current node
        back = temp;//set the current back value to temp
    }
    temp->data = item;//set the new node data

}


template<class Type>
void Queue<Type>::dequeue(){
    auto currentNode = front;
    count--;
    front = front->next;
    delete currentNode;
    return;

}

template<class Type>
Type Queue<Type>::peek(){

    auto curNode = front;


    if(count == 0){
        throw std::runtime_error("Item does not exist");
    }

    if(curNode == nullptr){
        return 0;
    }

    return curNode->data;
}

template<class Type>
int Queue<Type>::size(){
    return count;
}

template<class Type>
bool Queue<Type>::empty(){
    if(count == 0){
        return true;
    }
    return false;
}

template<class Type>
void Queue<Type>::clear(){
    auto currentNode = front;
    auto& temp = front;
    auto orginal = front;


    while(count > 0){
        temp = currentNode;
        currentNode = currentNode->next;
        free(temp);

        count--;
    }
}

template <class Type>
std::ostream& operator<<(std::ostream& out, const Queue<Type>& list)
{
    auto hold = list.front;
    while(hold != list.back){
        out << hold->data;
        out << "->";
        hold = hold->next;
    }

    out << hold->data;
    hold = hold->next;


    return out;
}




#endif //QUEUE_QUEUE_H
