#ifndef ORDEREDLINKEDLIST_H
#define ORDEREDLINKEDLIST_H
#include <iostream>

template <class Type>
struct Node
{
    Type data;
    Node *next;
};

template <class Type>
class Stack;

template <class Type>
std::ostream& operator<<(std::ostream&, const Stack<Type>& stack);


template <class Type>
class Stack
{
public:
    Stack();//set stack to a empty state
    Stack(const Stack& other);//create a deep copy
    Stack<Type>& operator=(const Stack<Type>& other);//create a deep copy and clean up memory
    ~Stack();//clean up memory

    int size() const;//return size DONE
    bool empty() const;//check if it empty or not DONE
    Type top() const;//return the top item of the stack
    void push(const Type&);//put item on top of the stack
    void pop();//reomove the item on the top of the stack, if it empty, it does nothing
    void pop(int n);//pop n amount of the top of the stack
    Type topPop();//pop AND return the top value of the stack
    void clear();//clear the stack
    friend std::ostream& operator<< <>(std::ostream&, const Stack<Type>& list);
    Type get(int) const;

protected:
    Node<Type>* front;//front is top
    Node<Type>* back;

    int count ;

};

template <class Type>
Stack<Type>::Stack()
{
    front = nullptr;
    back = nullptr;
    count = 0;
}

template <class Type>
Stack<Type>::Stack(const Stack<Type>& other)//set the default deep copy
{
    front = nullptr;
    back = nullptr;
    count = 0;
    *this = other;
}

template <class Type>
Stack<Type>& Stack<Type>::operator=(const Stack& other) {//copy the stack to the deep copy
    clear();
    for (int i = other.count - 1; i >= 0; i--) {
        auto value = other.get(i);
        push(value);
    }
}
template <class Type>
Stack<Type>::~Stack()
{
}

template <class Type>
int Stack<Type>::size() const//return the size (count)
{
    return count;
}

template <class Type>
bool Stack<Type>::empty() const//check if count is empty
{
    if (count == 0){
        return true;
    }
    return false;
}

template <class Type>
Type Stack<Type>::top() const//return the top (front) item, if none, throw logic error
{
    if(count == 0){
        throw std::logic_error("Error");
    }
    return front->data;
}

template <class Type>
void Stack<Type>::push(const Type& item){//push item to the front of the list
    Node<Type>* temp = new Node<Type>;//make item
    temp->data = item;
    if(count == 0){//if no items in a list, set the front, back to null, and add one
        count++;
        front = temp;
        back = temp;
        front->next = nullptr;
        return;
    }
    count++;
    temp->next = front;//set the current node to point to the first item in the node, making it the second item
    back = temp;
    front = temp;//set the front as temp

}

template <class Type>
void Stack<Type>::pop()//pop the first item in the list
{
    if(count == 0){//if no items exist, return nothing
        return;
    }
    count--;
    auto holdfront = front;
    front = holdfront->next;
    delete holdfront;
}

template <class Type>
void Stack<Type>::pop(int count)//repeat pop function x amount of times
{
    for (int i = 0; i < count; ++i) {
        pop();
    }
}

template <class Type>
Type Stack<Type>::topPop()//pop the top, but check if it emptu
{
    if(count == 0){
        throw std::logic_error("Error");
    }
    auto hold = front->data;
    pop();
    return hold;
}

template <class Type>
void Stack<Type>::clear()//clear the list
{
    auto hold = front;
    if(hold == nullptr){
        return;
    }
    while(front){//while there is front (if there an item in a list)
        count--;//subtract one from count
        front = hold->next;
        delete front;
        hold = hold->next;
    }
    front = nullptr;
    back = nullptr;
}

template <class Type>
Type Stack<Type>::get(int pos) const//get the data position of the stack
{
    int currentNodeNum = 0;
    auto currentNode = front; //set as front

    while(currentNodeNum != pos){
        try {
            currentNodeNum > count;
        }
        catch (const std::out_of_range& oor) {//if item is out of range, throw out of range error
            std::cerr << "Out of Range error: " << oor.what() << '\n';
        }
        currentNodeNum++;
        currentNode = currentNode->next;
    }
    return currentNode->data;
}

template <class Type>
std::ostream& operator<<(std::ostream& out, const Stack<Type>& list)//create a out string of the stack
{
    for(int i = list.count-1; i >= 0; i--){
        auto value = list.get(i);
        out << value;
        if(i!=0) {
            out << "->";
        }
    }
    return out;
}
#endif