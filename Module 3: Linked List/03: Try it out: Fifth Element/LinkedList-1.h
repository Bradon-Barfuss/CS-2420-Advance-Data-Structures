#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <stdexcept>
#include<iostream>
#include <sstream>

using namespace std;


template<typename Type>
struct Node{
    Type data;
    Node<Type>* next;
};


template<typename Type>
class LinkedList;


template<typename Type>
std::ostream& operator<<(std::ostream& out, const LinkedList<Type>& list);// Returns an output stream for displaying the LinkedList


template<typename Type>
class LinkedList{
public:
    LinkedList();// Default constructor for the LinkedList.  Creates an empty list by setting front and back of the list to nulllptr
    ~LinkedList(); //Destructor for the LinkedList.  Creates an empty list by setting front and back of the list to nulllptr
    void insert(Type data); //Adds to the back of the list
    Type peek(int ndx); //Looks at an element at the given ndx value
    void remove(int ndx); //Removes an element at the given ndx position
    friend std::ostream& operator<< <>(std::ostream& out, const LinkedList<Type>& list);// Returns an output stream for displaying the LinkedList
protected:
    Node<Type>* front;
    Node<Type>* back;
    int count;//keep track of current elements
};



template<typename Type>
LinkedList<Type>::LinkedList(){
    front = nullptr;
    back = nullptr;
    count = 0;
}

template<typename Type>
LinkedList<Type>::~LinkedList(){
    Node<Type>* temp = front;

    while(front != nullptr){
        temp = front;
        front = front->next;
        delete temp;
    }
}

template<typename Type>
void LinkedList<Type>::insert(Type data){
    auto* temp = new Node<Type>();//create the new node
    temp->data = data;//set the new node data

    if(!front){//since we are putting data at the end of the linked list, we will check if it the end of the list or not
        this->front = temp;
        this->back = temp;
    } else{//if it is the end of a list
        temp->next = nullptr;//set the next value to null (last item in the list)
        back->next = temp;//go back a node, and set that nodes next value to current node
        back = temp;//set the current back value to temp
    }
    count++;
}

template<typename Type>
void LinkedList<Type>::remove(int ndx){
    int currentNodeNum = 0;
    auto currentNode = front;

    if(ndx >= count){
        throw std::runtime_error("Item does not exist");
    }

    if(ndx == 0){
        front = front->next;
        delete currentNode;
        return;
    }

    while(currentNodeNum < ndx-1){
        currentNodeNum++;
        currentNode = currentNode->next;
    }
    auto toDelete = currentNode->next;
    currentNode->next = toDelete->next;

    delete toDelete;
}

template<typename Type>
Type LinkedList<Type>::peek(int ndx){
    int currentNodeNum = 0;
    auto currentNode = front; //set as front

    if(ndx >= count){
        throw std::runtime_error("Item does not exist");
    }
    while(currentNodeNum < ndx){
        currentNodeNum++;
        currentNode = currentNode->next;
    }
    return currentNode->data;
}

template<typename Type>
ostream& operator<<(ostream& out, const LinkedList<Type>& list){
    auto currentNode = list.front;
    while(currentNode){
        out << currentNode->data;
        if(currentNode->next){
            out << " ";
        }
        currentNode = currentNode->next;
    }
    return out;
}



#endif