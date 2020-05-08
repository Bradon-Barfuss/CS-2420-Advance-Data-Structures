//
// Created by bradon on 3/31/20.
//

#ifndef BINARYTREETESTER_BTREE_H
#define BINARYTREETESTER_BTREE_H
template <class Type>
struct Node{
    Type item;
    Node<Type> *left;
    Node<Type> *right;
};

template <class Type>
class BTree{
public:
    BTree(); //Constructor: Creates an empty tree
    ~BTree(); //Destructor: Deallocates memory
    void insert(Type data); //Inserts a node into the tree
    void preOrder(); //Displays a pre-order traversal of the tree
    void inOrder(); //Displays an in-order traversal of the tree
    void postOrder(); //Displays a post-order traversal of the tree
    int nodeCount(); //Calculates the number of items in the tree
protected:
    Node<Type>* root;
    void destory(Node<Type>* curr);
    void insert(Type item, Node<Type>* curr);
    void preOrder(Node<Type>* curr);
    void inOrder(Node<Type>* curr);
    void postOrder(Node<Type>* curr);
    int nodeCount(Node<Type>* curr); //Calculates the number of items in the tree

};

template <class Type>
BTree<Type>::BTree(){
    root = nullptr;
}

template <class Type>
BTree<Type>::~BTree() {
    destory(root);
}

template <class Type>
void BTree<Type>::destory(Node<Type> *curr) {
    if(curr != nullptr){
        destory(curr->left);
        destory(curr->right);
    }
}

template <class Type>
void BTree<Type>::insert(Type data){
    if(root == nullptr){
        root = new Node<Type>;
        root->item = data;
        root->left = nullptr;
        root->right = nullptr;
    }
    else{
        insert(data, root);
    }
}

template <class Type>
void BTree<Type>::insert(Type data, Node<Type>* curr){
    if(data < curr->item){
        if(curr->left == nullptr){
            auto tmp = new Node<Type>;
            tmp->item = data;
            tmp->right = nullptr;
            tmp->left = nullptr;
            curr->left = tmp;
        }
        else{
            insert(data, curr->left);
        }
    }
    else if(data > curr->item){
        if(curr->right == nullptr){
            auto tmp = new Node<Type>;
            tmp->item = data;
            tmp->right = nullptr;
            tmp->left = nullptr;
            curr->right = tmp;
        }
        else{
            insert(data, curr->right);
        }
    }
}

template<class Type>
void BTree<Type>::preOrder() {
    std::cout << "Pre Order: ";
    preOrder(root);
}

template<class Type>
void BTree<Type>::inOrder() {
    std::cout << "in Order: ";
    inOrder(root);
}

template<class Type>
void BTree<Type>::postOrder() {
    std::cout << "Post Order: ";
    postOrder(root);
}

template<class Type>
void BTree<Type>::preOrder(Node<Type>* curr) {
    if(curr){
        std::cout << curr->item << "  ";
        preOrder(curr->left);
        preOrder(curr->right);
    }
}

template<class Type>
void BTree<Type>::inOrder(Node<Type>* curr) {
    if(curr){
        preOrder(curr->left);
        std::cout << curr->item << "  ";
        preOrder(curr->right);
    }
}

template<class Type>
void BTree<Type>::postOrder(Node<Type>* curr) {
    if(curr){
        preOrder(curr->left);
        preOrder(curr->right);
        std::cout << curr->item << "  ";

    }
}


template<class Type>
int BTree<Type>::nodeCount() {
    return nodeCount(root);
}

template<class Type>
int BTree<Type>::nodeCount(Node<Type> *curr) {
    if(curr){
        return 1 + nodeCount(curr->left) + nodeCount(curr->right);
    }
    return 0;
}


#endif //BINARYTREETESTER_BTREE_H
