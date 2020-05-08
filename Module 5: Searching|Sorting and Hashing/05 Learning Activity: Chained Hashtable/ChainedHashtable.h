//
// Created by bradon on 3/10/20.
//

#ifndef CHAINEDHASHTABLETESTER_CHAINEDHASHTABLE_H
#define CHAINEDHASHTABLETESTER_CHAINEDHASHTABLE_H

#include <ostream>
#include <iomanip>

template <class Type>
struct Node{
    Type info;
    Node<Type>* next;//pointer to the next value
};

template<class Type>
class ChainedHashtable;

template <class Type>
std::ostream& operator<<(std::ostream &out, ChainedHashtable<Type> &t);//Returns an output stream for displaying the Hashtable


template<class Type>
class ChainedHashtable {
public:
    ChainedHashtable(int max);// Constructor for the Hashtable.  Creates an empty list
    ~ChainedHashtable(); //Deconstructor for the Hashtable.  Deallocates memory
    void add(Type item);//Adds to the hashtable
    bool remove(Type item);//Removes an item from the hashtable.  Returns true if the item was successfully removed
    bool contains(Type item);//Determines if the value is in the hashtable
    bool empty();//Determines if the hashtable is empty
    int size();//Determines the number of items in the hashtable
    friend std::ostream& operator<< <>(std::ostream &out, ChainedHashtable<Type> & t);//Returns an output stream for displaying the Hashtable <> stand for function definition
protected:
    Node<Type>** htable;
    int sz;//total elements in hash table
    int capacity;//how many the orginal has table can hold
};


template <class Type>
ChainedHashtable<Type>::ChainedHashtable(int max) {
    sz = 0;//this is the size of list of pointers
    capacity = max;//how big the intial list is
    htable = new Node<Type>* [capacity];//this is a list of pointers

}
template <class Type>
ChainedHashtable<Type>::~ChainedHashtable() {
    delete [] htable;
}

template <class Type>
int ChainedHashtable<Type>::size() {
    return sz;
}

template <class Type>
bool ChainedHashtable<Type>::empty(){
    return (sz == 0);
}

template <class Type>
void ChainedHashtable<Type>::add(Type item) {
    int key = item % capacity;//make the key for the position in the list where you want to add the item
    if(htable[key]){//if has item in the table, true or false
        auto node = new Node<Type>();//make new node
        node->info = item;//set the info to item
        node->next = htable[key];
        htable[key] = node;
        sz++;
    }
    else{
        htable[key] = new Node<Type>();
        htable[key]->info = item;
        sz++;
    }
}

template <class Type>
bool ChainedHashtable<Type>::contains(Type item) {
    int key = item % capacity;
    auto curr = htable[key];
    while(curr){
        if(curr->info == item){
            return true;
        }
        curr = curr->next;
    }
    return false;
}

template <class Type>
bool ChainedHashtable<Type>::remove(Type item) {
    if(empty())
        std::runtime_error("table is empty");
    int key = item % capacity;
    auto curr = htable[key];
    Node<Type>* prev = nullptr;//the last pointer
    while(curr){
        if(curr->info == item) {
            if (prev) {
                prev->next = curr->next;
                delete curr;
            }
            else {
                htable[key] = nullptr;
                delete curr;
                sz--;
                return true;//we successful deleted item;
            }
        }
        prev = curr;
        curr = curr->next;
    }
    return false;
}

template <class Type>
std::ostream& operator<<(std::ostream &out, ChainedHashtable<Type> & t) {
    for (int i = 0; i < t.capacity; ++i) {
        out << std::setw(8) << i << ": ";
        auto curr = t.htable[i];
        while (curr) {
            out << curr->info << " ";
            if(curr->next) out << "->";
            curr = curr->next;
        }
        out << std::endl;
    }
    return out;
}



#endif //CHAINEDHASHTABLETESTER_CHAINEDHASHTABLE_H
