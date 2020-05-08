#ifndef BINARY_TREE_H
#define BINARY_TREE_H

template <class Type>
struct Node {
    Type item;
    Node<Type> *left;
    Node<Type> *right;
};

template <class Type>
class BinaryTree
{
public:
    BinaryTree();
    ~BinaryTree();
    void insert(Type item);
    void preOrder();
    void inOrder();
    void postOrder();
    int nodeCount();
    Node<Type>*find(Type item);
    Node<Type>*findRightMostNode(Node<Type> *find);
    void remove(Type item);
    int  height();
    int leavesCount();


protected:
    Node<Type> *root;

private:
    void destroy(Node<Type> * curr);
    void insert(Type item, Node<Type> * curr);
    void preOrder(Node<Type> *curr);
    void postOrder(Node<Type> *curr);
    void inOrder(Node<Type> * curr);
    int nodeCount(Node<Type> * curr);
    int leavesCount(Node<Type> * curr);
    Node<Type>*find(Type item, Node<Type> *curr);
    Node<Type>* remove(Type item, Node<Type>*curr);
    int height(Node<Type>*curr);

    int max(int a, int b);

protected:
    int lheight;
    int rheight;
};

template <class Type>
BinaryTree<Type>::BinaryTree(){
    root = nullptr;
    lheight = 0;
    rheight = 0;
}

template <class Type>
BinaryTree<Type>::~BinaryTree(){
   // destroy(root);
}

template <class Type>
void BinaryTree<Type>::destroy(Node<Type> * curr){
    if(curr != nullptr){
        destroy(curr->left);
        destroy(curr->right);
    }
}

template <class Type>
void BinaryTree<Type>::insert(Type data) {
    if (root == nullptr) {
        root = new Node<Type>;
        root->item = data;
        root->left = nullptr;
        root->right = nullptr;
    } else
        insert(data, root);
}

template <class Type>
void BinaryTree<Type>::insert(Type data, Node<Type> * curr){
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

template <class Type>
void BinaryTree<Type>::preOrder(){
    preOrder(root);
}
template <class Type>
void BinaryTree<Type>::preOrder(Node<Type> *curr){
    if(curr){
        std::cout << curr->item << "  ";
        preOrder(curr->left);
        preOrder(curr->right);
    }
}

template <class Type>
void BinaryTree<Type>::inOrder(){
    inOrder(root);
}

template <class Type>
void BinaryTree<Type>::inOrder(Node<Type> *curr){
    if(curr){
        preOrder(curr->left);
        std::cout << curr->item << "  ";
        preOrder(curr->right);
    }
}

template <class Type>
void BinaryTree<Type>::postOrder(){
    postOrder(root);
}
template <class Type>
void BinaryTree<Type>::postOrder(Node<Type> *curr){
    if(curr){
        preOrder(curr->left);
        preOrder(curr->right);
        std::cout << curr->item << "  ";
    }
}

template <class Type>
int BinaryTree<Type>::nodeCount(){
    return nodeCount(root);
}

template <class Type>
int BinaryTree<Type>::nodeCount(Node<Type> *curr){
    if(curr){
        return 1 + nodeCount(curr->left) + nodeCount(curr->right);
    }
    return 0;
}

template <class Type>
int BinaryTree<Type>::leavesCount(){
    return leavesCount(root);
}

template <class Type>
int BinaryTree<Type>::leavesCount(Node<Type> *curr){
    if(curr == nullptr){
        return 0;
    }
    if(curr->left == nullptr && curr->right == nullptr){
        return 1;
    }
    else{
        return leavesCount(curr->left) + leavesCount(curr->right);
    }
}

template <class Type>
Node<Type>*BinaryTree<Type>::find(Type item){
    auto hold = find(item, root);
    return hold;
}

template <class Type>
Node<Type>*BinaryTree<Type>::find(Type item, Node<Type>*curr) {
    if(curr == nullptr){
        return nullptr;
    }
    if (curr != nullptr) {
        if (item < curr->item) {
            return curr->left = find(item, curr->left);
        }
        else if (item > curr->item) {
            return curr = find(item, curr->right);
        }
        else if (item == curr->item){
            return curr;
        }
    }
}


template <class Type>
Node<Type>*BinaryTree<Type>::findRightMostNode(Node<Type> *curr) {
    while (curr && curr->right != nullptr) {
        curr = curr->right;
    }
    return curr;
}

template <class Type>
void BinaryTree<Type>::remove(Type item) {
    remove(item, root);
}


/*she has this on here page
1.  * Find the node you wish to delete
2. If the left pointer is null, replace the node with the right branch
3. else If the right pointer is null, replace the node with the left branch
4. Otherwise, replace the node's value with the value in the rightmost node of the left branch and remove the rightmost node on the left branch.
 */

template <class Type>
Node<Type>* BinaryTree<Type>::remove(Type item, Node<Type>* curr){
    if (curr == nullptr) {
        return curr;
    }
    if (item < curr->item) { //if Item we are look for is less then the current item, use recursive but to the left node
        curr->left = remove(item, curr->left);
    } else if (item > curr->item) {//if Item is greater than the current item, use recursive but to the right node
        curr = remove(item, curr->right);
    } else {//if item and current item are the same
        //second step
        if (curr->left == nullptr) {//if there is nothing to the left, do the second step
            auto temp = new Node<Type>;//create new node
            temp = curr->right;//set the new node to the right possition of the current node
            free(curr);//delete current node
            return temp;//return the new node//third step
        } else if (curr->right == nullptr) {//if there is something to the left, but nothing to the right
            auto temp = new Node<Type>;//do the same thing but for the left side
            temp = curr->left;
            free(curr);
            return temp;
        }//fourth step
    auto temp = new Node<Type>;
    temp = findRightMostNode(curr->left);
    curr->item = temp->item;
    curr->left = remove(item, curr->right);
    }
    return curr;
}

template <class Type>
int BinaryTree<Type>::height(){
    return height(root)+1;
}
template <class Type>
int BinaryTree<Type>::height(Node<Type>*curr) {
    if (!curr) {
        return 0;
    } else {
        lheight = height(curr->left);
        rheight = height(curr->right);

        return max(lheight, rheight) + 1;
    }
}

template <class Type>
int BinaryTree<Type>::max(int a, int b) {
    return((a>b) ? a : b);
}

#endif // BINARY_TREE_H