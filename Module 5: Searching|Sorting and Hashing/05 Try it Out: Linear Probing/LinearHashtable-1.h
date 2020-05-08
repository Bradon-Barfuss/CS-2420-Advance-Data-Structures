//
// Created by bradon on 3/10/20.
//

#ifndef LINEARHASHTESTER_LINEARHASHTABLE_H
#define LINEARHASHTESTER_LINEARHASHTABLE_H

#include <iomanip>
#include <iostream>

template <class Type>
class LinearHashtable;

template <class Type>
std::ostream& operator << (std::ostream& out, const LinearHashtable<Type>& t);


template <class Type>
class LinearHashtable{
public:
    LinearHashtable(int capacity);
    ~LinearHashtable();
    void add(Type item);
    bool contains(Type item);
    bool remove(Type item);
    bool full();
    int size();
    bool empty();
    Type &operator[] (int ndx);
    friend std::ostream& operator << <>(std::ostream& out, const LinearHashtable<Type>& t);
protected:
    int* htable;
    int sz;
    int cap;
    int hold[10];
};

template<class Type>
LinearHashtable<Type>::LinearHashtable(int capacity) {
    sz = 0;
    cap = capacity;
    htable = new int[cap];
}

template<class Type>
LinearHashtable<Type>::~LinearHashtable() {
    delete [] htable;
}

template<class Type>
void LinearHashtable<Type>::add(Type item) {
    if(full())
        throw std::runtime_error("table is full");
    sz++;
    int key = item % cap;
    while(htable[key] != 0) {
        key++;
        if (key >= cap) {
            key = 0;
        }
    }

    htable[key] = item;
    hold[key] = item;
}

template<class Type>
bool LinearHashtable<Type>::contains(Type item) {
    int key = item % cap;
    for (int i = 0; i < cap; ++i) {
        if(htable[key] == item) {
            return true;
        }
        key++;
        if (key > cap) {
            key = 0;
        }
    }
    return false;
}

template<class Type>
bool LinearHashtable<Type>::remove(Type item) {
    for (int i = 0; i <= cap; ++i) {
        if(htable[i] == item) {
            htable[i] = 0;
            sz--;
            return true;
        }
    }
    return false;
}

template<class Type>
bool LinearHashtable<Type>::full() {
    return sz == cap;
}

template<class Type>
int LinearHashtable<Type>::size() {
    return sz;
}

template<class Type>
bool LinearHashtable<Type>::empty() {
    return sz==0;
}

template<class Type>
Type &LinearHashtable<Type>::operator[](int ndx) {
    return htable[ndx];
}

template <class Type>
std::ostream& operator << (std::ostream& out, const LinearHashtable<Type>& t){
    return out;
}

#endif //LINEARHASHTESTER_LINEARHASHTABLE_H
