//
// Created by bradon on 2/10/20.
//

#ifndef _FIFTHELEMENT_CPP
#define  _FIFTHELEMENT_CPP


#include "FifthElement.h"

template<typename T>
T FifthElement<T>::getFifthElement(){
    return this->peek(4);
}

template<typename T>
void FifthElement<T>::insertNewFifthElement(const T &value){
    int currentNodeNum = 0;

    auto currentNode = this->front; //set as front

    auto* temp = new Node<T>();
    temp->data = value;

    while(currentNodeNum < 3){
        currentNodeNum++;
        currentNode = currentNode->next;
    }

    temp->next = currentNode->next;
    currentNode->next = temp;


}

template<typename T>
void FifthElement<T>::deleteFifthElement(){
    this->remove(4);
}


template<typename T>
void FifthElement<T>::swapFourthAndFifthElement(){
    int currentNodeNum = 0;

    auto currentNode = this->front; //set as front
    while(currentNodeNum < 3){
        currentNodeNum++;
        currentNode = currentNode->next;
    }



    auto hold = currentNode->data;
    currentNode->data = currentNode->next->data;
    currentNode->next->data = hold;
}


#endif