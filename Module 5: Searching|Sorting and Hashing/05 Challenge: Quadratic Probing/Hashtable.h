//
// Created by bradon on 3/20/20.
//

#ifndef QUADRATIC_PROBING_HASHTABLE_H
#define QUADRATIC_PROBING_HASHTABLE_H


class Hashtable {
public:
    Hashtable(); //Constructs and empty hash table with a default capacity of 17 and a default load factor threshold of .65
    Hashtable(int size); //Constructs and empty hash table with the given capacity and a default load factor threshold of .65
    Hashtable(int, double); //Constructs and empty hash table with the given capacity and load factor threshold values

    Hashtable(const Hashtable& other); //creates a deep-copy of the given hashtable
    Hashtable& operator=(const Hashtable& other); //replaces the current hashtable with a deep-copy of the given hash table
    ~Hashtable(); //cleans up all allocated memory of the hashtable
    int size() const; //retunrs the number of items currently in the hashtable
    int capacity() const; //returns the capacity of the hashtable (i.e. the size of the array)
    double getLoadFactorThreshold() const; //returns the load factor threshold used to determine when to resize the hashtable.
    bool empty() const; //returns true if the table is empty or false otherwise
    void insert(const int); //Inserts the given value into the hashtable. Automatically resizes the table as necessary.
    void remove(int); //Removes the given value from the hashtable. If the value is not present it takes no action and throws no errors.
    bool contains(int) const; //Returns true if the given value is contained in the hashtable or false if the value is not in the hashtable.
    int indexOf(int) const; //Returns the index of the given value. If the value is not in the hashtable, returns -1. This is not a normal mehtod for a hashtable and is here solely to test that your hashtable does quadratic probing.
    void clear(); //Removes all values from the hashtable, resetting it to an empty state
    void resize();
    static bool isPrime(int n); //Returns true if the value is a prime number. One way to implement this method is to check if the number is divisible by 2-sqrt(n).
    // If it is then it is not prime. If it is not then it is prime. 2 and 3 must be tested separately.
    static int nextPrime(int n); //Returns the next prime number greater than or equal to n. One way to implement this method
    // is to test if n is prime and then repeatedly increment n and test again if it is prime.
private:
    int sz;
    int cap;
    double LoadFactorThreshold;
    int* hashtable;
    bool duringresize;
    int insertorder[300];

};


#endif //QUADRATIC_PROBING_HASHTABLE_H
