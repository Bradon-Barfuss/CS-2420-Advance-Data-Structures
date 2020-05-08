//
// Created by bradon on 4/2/20.
//

#ifndef EXPRESSIONTREETEST_EXPRESSIONTREE_H
#define EXPRESSIONTREETEST_EXPRESSIONTREE_H

#include <iostream>
#include <sstream>

using namespace std;
struct Node{
    std::string data;
    Node* left;
    Node* right;
};

class ExpressionTree{
public:
    ExpressionTree(); // default constructor creates an empty expression tree
    ~ExpressionTree();
    ExpressionTree(std::string expr); // Creates an expression tree from the given string expression
    void setExpression(std::string expr); // Clears the expression tree and stores the given expression in a new tree
    std::string getResult(); // return the results of evaluating the expression tree
    ostream& printParseTreeInOrder(std::ostream&); // outputs the tree to the ostream& using an in-order traversal
    ostream& printParseTreePostOrder(std::ostream&); // outputs the tree to the ostream& using post-order traversal
    void insert(std::string item);
private:
    char charTemp[16];
    int charpostion;
protected:
    Node* root;
    ostream& InOrder(Node* curr, ostream&);
    ostream& PostOrder(Node* curr, std::ostream&);
    void insert(std::string item, Node* curr);
    void digitinsert(std::string item, Node* curr);
    int position;
    void destory(Node* curr);

    int getValue(Node *pNode);
};

//ALL OF THIS IS UNTESTED, PREPARE FOR TEN MILLION BUGS
//To transvers the string, we will using the variable position to access different positions of the inputed string
ExpressionTree::ExpressionTree() {
    position = 0;
    int charposition = 0;
    root = nullptr;
}

ExpressionTree::ExpressionTree(std::string expr) {
    setExpression(expr);

}
ExpressionTree::~ExpressionTree() {
    destory(root);

}
std::string ExpressionTree::getResult() {

    int value = getValue(root);
    string str = to_string(value);
    return str;
}
int ExpressionTree::getValue(Node *curr) {
    if(curr == nullptr){
        return 0;
    }
    if(curr->data == "("){
        getValue(curr->left);
    }
    if(curr->left == nullptr && curr->right == nullptr){
        if(curr->data != "(" && curr->data != ")") {
            string hold = root->data;
            if(isdigit(hold[0])) {
                int hold2 = stoi(hold);
                return hold2;
            }
        }
    }

    int l_val = getValue(curr->left);
    int r_val = getValue(curr->right);

    if(curr->data == "+")
        return l_val+r_val;
    if(curr->data == "-")
        return r_val-l_val;
    if(curr->data == "*")
        return r_val*l_val;
    if(curr->data == "-"){
        return r_val/l_val;
    }
}

void ExpressionTree::setExpression(std::string expr) {//set all the string
    if(root == nullptr)
        insert(expr);

    destory(root);
    insert(expr);
}

void ExpressionTree::destory(Node *curr) {
    if(curr != nullptr){
        curr->data = "";
        destory(curr->left);
        destory(curr->right);
    }
}

void ExpressionTree::insert(std::string item){//the public insert
    if(root == nullptr){
        root = new Node;
        root->right = nullptr;
        root->left = nullptr;
    }
    insert(item, root);
}


void ExpressionTree::insert(std::string item, Node* curr){
    if(item[position] == '\0'){
        return;
    }
    else if(item[position] == '('){
        auto temp = new Node;
        curr->left = temp;
        curr->right = nullptr;
        position++;
        insert(item, curr->left);
    }
    else if(item[position]==')'){
        position++;
    }
    else if(isdigit(item[position])){//check if it is a digit
        digitinsert(item, curr);//check if their is another digit
    }
    else if((item[position] == '+') || (item[position] == '-') || (item[position] == '/') || (item[position] == '*')){
        curr->data = item;
        auto temp = new Node;
        curr->right = temp;
        position++;
        insert(item, curr->right);
    }
    return;
}
void ExpressionTree::digitinsert(std::string item, Node *curr) {
    charTemp[charpostion] = item[position];//put the digit in a char string
    if(isdigit(item[position+1])){
        charpostion++;
        position++;
        digitinsert(item, curr);
    }

    string hold;//create a new string
    for (int i = 0; i < charpostion; ++i) {//loop throgh the charTemp
        hold[i] = charTemp[i];//add to the string array
    }
    curr->data = hold;//set the current node data to the string
    position++;//move to the new global string position
}
ostream& ExpressionTree::printParseTreeInOrder(std::ostream &out) {
    InOrder(root, out);
    return out;
}
ostream& ExpressionTree::printParseTreePostOrder(std::ostream &out) {
    PostOrder(root, out);
    return out;
}


ostream &ExpressionTree::InOrder(Node *curr, ostream &out) {
    if (curr != nullptr) {
        InOrder(curr->left, out);
        if(curr->data != "(" || curr->data != ")")
            out << curr->data;
        InOrder(curr->right, out);
    }
}

ostream &ExpressionTree::PostOrder(Node *curr, std::ostream &out) {
    if(curr != nullptr) {
        PostOrder(curr->left, out);
        PostOrder(curr->right, out);
        if (curr->data != "(" && curr->data != ")")
            out << curr->data;
    }
    return out;
}
#endif //EXPRESSIONTREETEST_EXPRESSIONTREE_H
