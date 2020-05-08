#ifndef ORDEREDLINKEDLIST_H
#define ORDEREDLINKEDLIST_H
#include <iostream>
#include <sstream>

template <class Type>
struct Node
{
    Type data;
    Node *next;
};

template <class Type>
class OrderedLinkedList;

template <class Type>
std::ostream& operator<<(std::ostream&, const OrderedLinkedList<Type>& list);


template <class Type>
class OrderedLinkedList
{
public:
    OrderedLinkedList(); // initializes the list to an empty state.
    OrderedLinkedList(const OrderedLinkedList& other); //creates a deep-copy of the other list.
    OrderedLinkedList<Type>& operator=(const OrderedLinkedList<Type>& other);//creates a deep-copy of the other list and cleans up any previously used memory.
    ~OrderedLinkedList();// cleans up any previously used memory.

    int size() const;//returns the current number of items in the list.
    bool empty() const;// returns true if the list is currently empty (i.e. the size is 0)
    Type get(int) const; //returns the item at the specified position in the list. Throws an out_of_range_exception if the pos is outside the bounds of the list.
    Type getFirst() const; //returns the first item in the list. Throws an out_of_range exception if the list is empty
    Type getLast() const; //; returns the last item in the list. Throws an out_of_range exception if the list is empty
    int insert(const Type&); //inserts the item into the list in the correct order.
    int find(const Type&) const;// returns the position of the item in the list if it is found or -1 if the item is not in the list. Use the "==" operator to determine if the item is the one being found.
    void remove(const Type&);// Removes the item from the list. If the item is not in the list this method has no effect. Use the "==" operator to determine if the item is the one to be removed.
    void clear(); //deletes the entire list and resets it to an empty state.
    OrderedLinkedList<Type> everyOtherOdd(); //returns a new list that contains every other item in the list starting with the first item (index 0).
    OrderedLinkedList<Type> everyOtherEven(); //); returns a new list that contains every other item in the list starting with the second item (index 1).
    friend std::ostream& operator<< <>(std::ostream&, const OrderedLinkedList<Type>& list); //; Outputs the items in the list formated as item1->item2->...->itemn. For example. if the list is 1,2,3,4. This method outputs 1->2->3->4

protected:
    Node<Type>* front;
    Node<Type>* back;
    int count;
};

template <class Type>
OrderedLinkedList<Type>::OrderedLinkedList()
{
    front = nullptr;
    back = nullptr;
    count = 0;
}

template <class Type>
OrderedLinkedList<Type>::OrderedLinkedList(const OrderedLinkedList<Type>& other) {
    front = nullptr;
    back = nullptr;

    count = 0;
    for (int i = 0; i < other.count; ++i) {
        insert(other.get(i));
    }
}

template <class Type>
OrderedLinkedList<Type>& OrderedLinkedList<Type>::operator=(const OrderedLinkedList& other)//creates a deep-copy of the other list and cleans up any previously used memory.
{
    count = 0;
    front = nullptr;
    back = nullptr;

    for (int i = 0; i < other.count; ++i) {
        insert(other.get(i));
    }

}

template <class Type>
OrderedLinkedList<Type>::~OrderedLinkedList()
{
    clear();
}

template <class Type>
int OrderedLinkedList<Type>::size() const
{
    return count;
}

template <class Type>
bool OrderedLinkedList<Type>::empty() const
{
    if(count == 0) {
        return true;
    }
    else{
        return false;
    }
}

template <class Type>
Type OrderedLinkedList<Type>::get(int pos) const {
    int i = 0;
    auto currentNode = front; //set as front

    if(pos >= count || pos < 0) {
        throw std::out_of_range("out_of_range error");
    }
    while (i != pos) {
        i++;
        currentNode = currentNode->next;
    }
    if(i == pos){
        return currentNode->data;
    }
}

template <class Type>
Type OrderedLinkedList<Type>::getFirst() const
{
    if(count == 0) {
        throw std::out_of_range("out_of_range error");
    }
    Type ret;
    auto currentNode = front; //set as front

    return currentNode->data;//return first position
}

template <class Type>
Type OrderedLinkedList<Type>::getLast() const
{
    if(count == 0) {
        throw std::out_of_range("out_of_range error");
    }
    Type ret;
    int currentNodeNum = 0;
    auto currentNode = front; //set as front
    for(int i = 0; i < count-1; i++){//loop threw the linked list
        currentNodeNum++;
        currentNode = currentNode->next;
    }
    return currentNode->data;
}

template <class Type>
int OrderedLinkedList<Type>::insert(const Type& item){
    Node<Type>* temp = new Node<Type>; // make the new node
    temp->data = item;//set the new ndoe data
    temp->next = nullptr;
    if(front == nullptr) {//check if it the end of the list or not
        this->front = temp;
        this->back = temp;
        count++;
        return -1;
    }
    else{
        auto currentNode = this->front;
        while(currentNode != this->back){
            if(temp->data < currentNode->next->data && (!(temp->data < currentNode->data))){
                temp->next = currentNode->next;
                currentNode->next = temp;
                count++;
                return -1;
            }
            else{//loop threw the away (not the right threw, I know)
                currentNode = currentNode->next;
            }
        }
    }
    if(temp->data < front->data){//if the new value is less than the first value
        temp->next = front;//set the next node of temp to the front
        this->front = temp;//set the orginal node front to temp
        count++;//increase count by 1
    }
    else{
        temp->next = nullptr;
        back->next = temp;
        back = temp;
        count++;
        return -1;
    }

}

template <class Type>
int OrderedLinkedList<Type>::find(const Type& item) const {
    int currentNodeNum = 0;
    auto currentNode = front; //set as front
    for (int i = 0; i < count; i++) {
        if(currentNode == nullptr){
            return -1;
        }
        if(currentNode->data == item){
            return currentNodeNum;
        }
        currentNodeNum++;
        currentNode = currentNode->next;

    }
    return -1;
}

template <class Type>
void OrderedLinkedList<Type>::remove(const Type& item)
{

    auto currentNode = front;
    auto location = find(item);
    if(location == -1) {//end if nothing is there
        return;
    }
    if (location == 0) {//if its in the first position
        front = currentNode->next;//set front to the next position
        free(currentNode);//clear the current node
        count--;
        return;
    }
    for (int i = 0; i < count; ++i) {//loop though the array
        if(!(currentNode->next->data == item)){//if the next Item equals the current item
            currentNode = currentNode->next;//loop through the array
        }
        else if (currentNode->next != back) {
            auto hold = currentNode->next;
            currentNode->next = currentNode->next->next;
            free(hold);
            count--;
            return;
        }
        else if (currentNode->next != back) {//if the next position doesn't equal the back ability
            auto hold = currentNode->next;
            currentNode->next = currentNode->next->next;//set the next address to equal the next next address
            free(hold);//clear next position
            count--;
            return;
        } else {
            count--;
            auto hold = currentNode->next;
            back->next = currentNode;
            free(hold);
            return;
        }
    }
}

template <class Type>
void OrderedLinkedList<Type>::clear()
{
    auto currentNode = front;
    auto& temp = front;
    auto holdcount = count;

    for (int i = 0; i < holdcount; i++) {//loop thought the linked list size
        temp = currentNode;
        currentNode = currentNode->next;
        free(temp);

        count--;
    }
    front = nullptr;//set front to null;
}



template <class Type>
OrderedLinkedList<Type> OrderedLinkedList<Type>::everyOtherOdd(){
    OrderedLinkedList<Type> retVal;
    for(int i = 0; i < count; i += 2){//loop though each node jumping by 2 starting at position 1
        retVal.insert(get(i));
    }
    return retVal;
}

template <class Type>
OrderedLinkedList<Type> OrderedLinkedList<Type>::everyOtherEven(){
    OrderedLinkedList<Type> retVal;
    for(int i = 1; i < count; i += 2){
        retVal.insert(get(i));
    }
    return retVal;
    return retVal;
}

template <class Type>
std::ostream& operator<<(std::ostream& out, const OrderedLinkedList<Type>& list)
{
    if(list.count==0){
        int hold;
    }else {
        for (int i = 0; i < list.count - 1; ++i) {
            out << list.get(i);
            out << "->";
        }
        out << list.get(list.count - 1);
    }
}



//template <class Type>
//OrderedLinkedList operator==(const OrderedLinkedList<Type>& list)
//{
//
//}
#endif