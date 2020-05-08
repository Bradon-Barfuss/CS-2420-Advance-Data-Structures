//
// Created by bradon on 2/10/20.
//

#ifndef FIFTHELEMENT_FIFTHELEMENT_H
#define FIFTHELEMENT_FIFTHELEMENT_H

#include "LinkedList.h"


template<typename Type>
class FifthElement : public LinkedList<Type> {
public:
    Type getFifthElement();//returns the data at the fifth node, throw length error if no fifth element
    void insertNewFifthElement(const Type &value);//inserts a node containing value between 4 and 5 element, making the 5th node the 6th. if only 4 nodes, make fifth the last node
    void deleteFifthElement();//delete the fifth node, if six node exists, point the fourth node to the sixth
    void swapFourthAndFifthElement();//change the 4th and 5th node pointers, not data
};

#include "FifthElement.cpp"


#endif //FIFTHELEMENT_FIFTHELEMENT_H
