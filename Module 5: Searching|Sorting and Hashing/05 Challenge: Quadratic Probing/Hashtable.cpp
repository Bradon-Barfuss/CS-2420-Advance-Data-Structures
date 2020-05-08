//
// Created by bradon on 3/20/20.
//

#include <cstdlib>
#include <iostream>
#include <cmath>
#include "Hashtable.h"

Hashtable::Hashtable() {//DONE
    cap = 17;
    sz = 0;
    LoadFactorThreshold = .65;
    hashtable = new int[17];
    duringresize = false;

}

Hashtable::Hashtable(int size) {//DONE
    cap = size;
    hashtable = new int[size];
    sz = 0;
    LoadFactorThreshold = .65;
    duringresize = false;

}

Hashtable::Hashtable(int c, double LFT) {//DONE
    cap = c;
    hashtable = new int[c];
    sz = 0;
    LoadFactorThreshold = LFT;
    duringresize = false;

}
Hashtable::Hashtable(const Hashtable &other) {
    cap = other.cap;
    sz = other.sz;
    LoadFactorThreshold = other.LoadFactorThreshold;
    int i = 0;
    for (int i = 0; i < cap; ++i) {
        int temp = other.hashtable[i];
        hashtable[i] = temp;
    }
    for (int j = 0; j < sz; ++j){
        int temp = other.insertorder[i];
        insertorder[j] = temp;
    }
}
Hashtable &Hashtable::operator=(const Hashtable &other) {
    cap = other.cap;
    sz = other.sz;
    LoadFactorThreshold = other.LoadFactorThreshold;
    for (int i = 0; i < cap; ++i) {
        hashtable[i] = other.hashtable[i];
    }
    for (int j = 0; j < sz; ++j){
        insertorder[j] = other.insertorder[j];
    }
}


int Hashtable::size() const {//DONE
    return sz;
}

Hashtable::~Hashtable() {
    delete[] hashtable;
}

int Hashtable::capacity() const {//DONE
    return cap;
}

double Hashtable::getLoadFactorThreshold() const {
    return LoadFactorThreshold;
}

bool Hashtable::empty() const {//DONE
    return sz==0;
}


void Hashtable::resize(){
    //std::cout << "RESIZING AT: " << sz << "  THE HOLD CAP IS: " << getLoadFactorThreshold()*capacity() << "  THE CURRENT CAP IS: " << capacity()<<"\n";
    cap = cap + 10;//add to the new cap
    while(!isPrime(cap)){
        cap++;
    }

    delete hashtable;//delete the old hash table
    hashtable = new int[cap];//create the new hashtable with the new size
    for (int j = 0; j < cap; ++j) {//set everything too zero
        hashtable[j] = 0;
    }
    duringresize = true;
    for (int i = 0; i < sz; ++i) {//insert the new numbers
        insert(insertorder[i]);//insert the new array
    }
    duringresize = false;
}

void Hashtable::insert(int item) {
    if(!duringresize) {
        double holdcap = LoadFactorThreshold * capacity();
        if ((sz+1.0) >= holdcap) {
        //if((sz+1.0)/LoadFactorThreshold){
            resize();
        }
        insertorder[sz] = item;//run after resize
        sz++;

    }
    int key = item % cap;
    int hold = key;
    for (int i = 1; i <= cap; ++i) {
        if (hashtable[hold]) {//check if the current position has a value
            hold = key + std::pow(i,2);//add to the key by...
            if(hold > cap){
                hold = (-1*(cap-hold));
            }
        }
        else if (!hashtable[hold]){
            hashtable[hold] = item;
            return;
        }
    }
}

void Hashtable::remove(int item) {
    int key = item % cap;
    int hold = key;
    for (int i = 1; i <= cap; ++i) {
        if (hashtable[hold]!=item) {//check if the current position has a value
            hold = key + std::pow(i,2);//add to the key by...
            if(hold > cap){
                hold = (-1*(cap-hold));
            }
        }
        else if (hashtable[hold]==item){
            hashtable[hold] = 0;
            sz--;
        }
    }
    for (int j = 0; j < sz; ++j) {
        if(insertorder[j] == item) {
            while (insertorder[j]){
                insertorder[j] = insertorder[j + 1];
                j++;
            }
            return;
        }
    }
}

bool Hashtable::contains(int item) const {
    int key = item % cap;
    int hold = key;
    for (int i = 1; i <= cap; ++i) {
        if (hashtable[hold]!=item) {//check if the current position has a value
            hold = key + std::pow(i,2);//add to the key by...
            if(hold > cap){
                hold = (-1*(cap-hold));
            }
        }
        else if (hashtable[hold]==item){
            return true;
        }
    }
    return false;
}

void Hashtable::clear() {
    for (int i = 0; i < cap; ++i) {
        hashtable[i] = 0;
    }
    sz=0;
}

int Hashtable::indexOf(int item) const {
    for (int i = 0; i < cap; i++) {
        if(hashtable[i] == item){
            return i;
        }
    }
    return -1;
}

bool Hashtable::isPrime(int n) {
    // Corner case
    if (n <= 1)
        return false;

    // Check from 2 to n-1
    for (int i = 2; i < n; i++)
        if (n % i == 0)
            return false;

    return true;
}

int Hashtable::nextPrime(int n) {
    return 0;
}




