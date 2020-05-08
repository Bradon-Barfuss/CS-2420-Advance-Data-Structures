#include "SortedCollection.h"
using namespace std;

SortedCollection::SortedCollection(){
    maxsize = 8;//set intial maxsize to 8
    array = new double[maxsize];//set main array size to 8
    length = 0;
}
SortedCollection::~SortedCollection() {}
SortedCollection::SortedCollection(const SortedCollection& other) {//loop thought the size of the parameter array and add it to the mainarray
    for (int i = 0; i < other.length; ++i) {
        add(other.array[i]);
    }
}

void SortedCollection::add(double item) {
    length++; //add to the current amount of element

    if (length < maxsize) {
        array[length - 1] = item;
        for (int i = length - 1; i > 0; --i) {
            if (array[i] < array[i - 1]) {
                double temp = array[i - 1];
                array[i - 1] = array[i];
                array[i] = temp;
            }
        }
        return;
    }
    maxsize = maxsize * 2;//double the size
    double *temp = new double[maxsize];//make new array
    for (int i = 0; i < length; i++) {//copy elements over
        temp[i] = array[i];
    }
    array = new double[maxsize];

    for (int i = 0; i < length; i++) {//copy elements over
        array[i] = temp[i];
    }
    delete[] temp;//delete the tempary array
    array[length - 1] = item;
    for (int i = length - 1; i > 0; --i) {
        if (array[i] < array[i - 1]) {
            double temp = array[i - 1];
            array[i - 1] = array[i];
            array[i] = temp;
        }
    }
    return;
}

double& SortedCollection::operator[](int ndx){
    //TODO:remove tmp and return a refernce
    //to the actual value in the collection
    return array[ndx];

}

SortedCollection& SortedCollection::operator-(int count){
    for (int i = 0; i < count; ++i) {
        removeEnd();
    }
    return *this;
}
SortedCollection& SortedCollection::operator+(double item){

    add(item);
    return *this;
}
SortedCollection& SortedCollection::operator+(const SortedCollection& other){
    for (int i = 0; i < other.length; ++i) {
        add(other.array[i]);
    }
    return *this;
}

SortedCollection& SortedCollection::operator<<(double item){
    add(item);
    return *this;
}
std::ostream& operator<<(std::ostream& out, const SortedCollection& other){
    for (int i = 0; i < other.length; ++i) {
        out << other.array[i];
    }
    return out;
}


/**TODO: override any methods necessary
 * to keep this collection of doubles in
 * sorted order.  Hint - Whenever you
 * add an item add it in the "correct"
 * spot to maintain sorted order.
 */