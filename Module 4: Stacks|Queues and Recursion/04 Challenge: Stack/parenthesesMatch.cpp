#include "parenthesesMatch.h"
#include "Stack.h"
bool parenthesesMatch(const char* str){
    Stack<char> s;

    int i = 0;
    while(str[i] != '\0'){//while not at end of string
        if(str[i] == '('){
            s.push('(');//push to stack
        }
        if(str[i] == ')'){
            s.pop();//pop from stack
        }
        i++;
    }
    return s.empty();
}