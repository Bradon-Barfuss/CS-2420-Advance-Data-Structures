#ifndef SORTED_DOUBLE_COLLECTION_H
#define SORTED_DOUBLE_COLLECTION_H
#include "Collection.h"

class SortedCollection: public Collection{
public:
    SortedCollection();
    SortedCollection(const SortedCollection& other);
    ~SortedCollection();
    void add(double item) override;


    double& operator[](int ndx);
    SortedCollection& operator-(int count);
    SortedCollection& operator+(double item);
    SortedCollection& operator+(const SortedCollection& other);
    SortedCollection& operator<<(double item);

private:

    friend std::ostream& operator<<(std::ostream& out, const SortedCollection& other);/**TODO: override any methods necessary
 *
 * to keep this collection of doubles in
 * sorted order.  Hint - Whenever you
 * add an item add it in the "correct"
 * spot to maintain sorted order and
 * remember there are several ways to add
 * items to the collection.
 */
};
#endif