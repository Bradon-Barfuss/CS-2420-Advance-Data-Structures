//
// Created by bradon on 1/13/20.
//

#ifndef COLLECTION_COLLECTION_H
#define COLLECTION_COLLECTION_H


#include <iosfwd>

class Collection {
public:
    Collection();//Default constructor
    ~Collection();//Destructor (de-allocates memory for array)
    void initilze();
    int getSize();//get size of array;
    int getCapacity();//get maximum allowed in current array
    void add(double value); //add too array
    void addFront(double value); // add to the front of array
    double get(int ndx); //get a value stored in a specified position.
    double getFront(); //return the first value of array
    double getEnd(); //get last value in array
    int find(double needle); //returns the position of needle in the list, -1 if not found
    friend std::ostream& operator<<(std::ostream&, const Collection & c);
    void checkRuntime();
private:
    double array[20];
    int arrayLength;
};


#endif //COLLECTION_COLLECTION_H
