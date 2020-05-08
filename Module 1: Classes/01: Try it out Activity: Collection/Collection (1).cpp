//
// Created by bradon on 1/13/20.
//

#include "Collection.h"
#include <iostream>

using namespace std;

Collection::Collection() {
    initilze();
}
Collection::~Collection() {

}
void Collection::initilze(){
    for(int i = 0; i < getCapacity(); i++) {
        array[i] = {0.0};
    }
    arrayLength = 0;
}

int Collection::getSize() {
    return arrayLength;
}

int Collection::getCapacity(){
    double size = sizeof(array)/ sizeof(array[0]);
    return size;
}

void Collection::add(double value) {
    checkRuntime();
    array[arrayLength] = value;
    arrayLength++;
}
void Collection::addFront(double value){
    checkRuntime();
    arrayLength++;
    int size = getSize();
    double hold;
    for (int i = size; i >= 0; --i) {
        hold = array[i];
        array[i+1] = hold;
    }
    array[0] = value;
}
double Collection::get(int ndx) {
    return array[ndx];
}
double Collection::getFront() {
    return array[0];
}
double Collection::getEnd() {
    return array[getSize()];
}
int Collection::find(double needle){
    for (int i = 0; i < getSize(); ++i) {
        if (array[i] == needle) {
            return i;
        }
    }
    return -1;
}
ostream &operator<<(ostream& os, const Collection &c) {
    os << c.array[0] << " ";
    for (int i = 1; i < c.arrayLength; i++) {
        os << c.array[i];
    }
    return os;
}


void Collection::checkRuntime() {
    if(arrayLength == getCapacity()){
        throw runtime_error("List Full");
    }
}
