#ifndef COLLECTION_H
#define COLLECTION_H
#include <iostream>


class Collection {
public:
    Collection();
    ~Collection();
    Collection(int size);
    Collection(const Collection& other);
    virtual int getSize() const;
    virtual int getCapacity() const;
    virtual void add(double item);
    virtual double get(int ndx) const;
    virtual int find(double needle) const;
    virtual double getFront() const;
    virtual double getEnd() const;
    virtual void removeFront();
    virtual void removeEnd();
    virtual void remove(double item);
    virtual double& operator[](int ndx);

    virtual Collection& operator-(int count);
    virtual Collection& operator+(double item);
    virtual Collection& operator+(const Collection& other);
    virtual Collection& operator<<(double item);
    virtual Collection& operator=(Collection& other);
    friend std::ostream& operator<<(std::ostream& out, const Collection& other);

    double* array = nullptr;
    int length;
    int maxsize;
private:
};
#endif