#ifndef _COLLECTION_CPP
#define _COLLECTION_CPP

#include "Collection.h"

Collection::Collection(){
    maxsize = 8;//set intial maxsize to 8
    array = new double[maxsize];//set main array size to 8
    length = 0;
}
Collection::~Collection(){
    delete[] array;//create a deconstructor to delete MainArray
}
Collection::Collection(int size){//set the size of the MainArray
    maxsize = size;//variable to keep the max size of the array
    array = new double[maxsize];
    length = 0;
}
Collection::Collection(const Collection& other){
    maxsize = other.maxsize;
    length = other.length;
    if(maxsize <= length){
        maxsize = maxsize * 2;
    }

    double* temp = new double[maxsize];//make new array
    for (int i = 0; i < length; i++) {//copy elements over
        temp[i] = other.array[i];
    }

    array = new double[maxsize];

    for (int i = 0; i < length; i++) {//copy elements over
        array[i] = temp[i];
    }
    return;
}

int Collection::getSize() const{
    return length;//a variable to keep the number of elements in a array
    return -1;
}
int Collection::getCapacity() const{
    return maxsize; //return the max amount of doubles the array can hold
    return -1;
}
double Collection::get(int ndx) const{
    try {
        array[ndx];
    }
    catch (const std::out_of_range& oor) {
        std::cerr << "Out of Range error: " << oor.what() << '\n';
    }
    return array[ndx];
}
double Collection::getFront() const{

    double hold = array[0];//get the first position of the array
    try {
        array[0];
    }
    catch (const std::out_of_range& oor) {
        std::cerr << "Out of Range error: " << oor.what() << '\n';
    }
    return hold;
}
double Collection::getEnd() const{//get last position of the array
    double hold = array[length];
    try {
        array[length];
    }
    catch (const std::out_of_range& oor) {
        std::cerr << "Out of Range error: " << oor.what() << '\n';
    }
    return hold;
}

int Collection::find(double needle) const{//find the position of a number
    for (int i = 0; i < length; ++i) {
        if(needle == array[i]){
            return i;
        }
    }
    return -1;//if nothing found return -1
}
void Collection::add(double item){

    if(length < maxsize){//make sure it is less than, not equal too
        array[length] = item;
        length++;
    }
    else {
        maxsize = maxsize * 2;
        double *temp = new double[maxsize];//make new array
        for (int i = 0; i < length; i++) {//copy elements over
            temp[i] = array[i];
        }

        array = new double[maxsize];

        for (int i = 0; i < length; i++) {//copy elements over
            array[i] = temp[i];
        }
        delete []temp;

        array[length] = item;
        length++;
    }

}
void Collection::removeFront(){
    try {
        array[0];
    }
    catch (const std::out_of_range& oor) {
        std::cerr << "Out of Range error: " << oor.what() << '\n';
    }

    for (int i = 0; i < length; ++i) {
        array[i] = array[i + 1];
    }
    length--;

}

void Collection::removeEnd(){
    try {
        array[length];
    }
    catch (const std::out_of_range& oor) {
        std::cerr << "Out of Range error: " << oor.what() << '\n';
    }
    length--;
    array[length] = -1;//remove the last element
}

void Collection::remove(double item){
    int hold = find(item);//look for element position
    if(hold != -1){//if it is there
        array[hold] = 0;//set it to 0
        length--;
        for (int i = hold; i < length; ++i) {
            array[i] = array[i + 1];
        }
    }
}
Collection& Collection::operator=(Collection& other){//set the
    maxsize = other.getCapacity();
    length = other.length;
    array = new double[maxsize];
    for(int i = 0; i < other.getSize(); i++){
        array[i] = other[i];
    }
    return *this;
}


double& Collection::operator[](int ndx){
    //TODO:remove tmp and return a refernce
    //to the actual value in the collection

    return array[ndx];

}

Collection& Collection::operator-(int count){
    for (int i = 0; i < count; ++i) {
        removeEnd();
    }
    return *this;
}
Collection& Collection::operator+(double item){
    add(item);
    return *this;
}
Collection& Collection::operator+(const Collection& other){
    for (int i = 0; i < other.length; ++i) {
        add(other.array[i]);
    }
    return *this;
}
Collection& Collection::operator<<(double item){
    add(item);
    return *this;
}
std::ostream& operator<<(std::ostream& out, const Collection& other){
    for (int i = 0; i < other.length; ++i) {
        out << other.array[i];
    }
    return out;
}

#endif
