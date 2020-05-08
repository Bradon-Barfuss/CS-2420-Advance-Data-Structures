#include "DynamicString.h"
#include <cctype>
#include <stdexcept>

using namespace std;
using std::out_of_range;
using std::tolower;
using std::toupper;
using std::ostream;

DynamicString::DynamicString(){ //set intial size of strarray (string) to zero
    size = 0;
    strarray = new char[size];
    strarray[0] = '\0';
}
DynamicString::~DynamicString() {
    delete []strarray;
}
DynamicString::DynamicString(const char* str){ //cout the length of the string and set the strarray for each char
    int i = 0;//size of string

    while(*str != '\0'){//until the end of string
        i++;
        str++;
    }
    strarray = new char[i];//set the length of strarray to the length of the string

    while(i >= 0) {//loop through until end of string
        strarray[i] = *str;
        str--;
        i--;
    }
}



DynamicString::DynamicString(const DynamicString& other){//create a deep copy of array

    int size = 0;
    while(other.strarray[size] != '\0'){
        size++;
    }

    char *temp = new char[size];
    for (int j = 0; j < size; ++j) {
        temp[j] = other.strarray[j];
    }
    strarray = new char[size];
    for (int k = 0; k < size; ++k) {
        strarray[k] = temp[k];
    }
    delete[] temp;
}

DynamicString& DynamicString::operator=(const DynamicString &other) {
    char *temp = new char[other.len()];
    for(int i = 0; other.strarray[i] < other.len(); i++){
        temp[i] = other.strarray[i];
    }
    strarray = new char[other.len()];
    for(int i = 0; other.strarray[i] < other.len(); i++){
        strarray[i] = temp[i];
    }
    delete[] temp;
}


int DynamicString::len() const{ //get length of string

    int length = 0;
    int i = 0;
    while(strarray[i] != '\0'){
        i++;
        length++;
    }
    return length;
}

const char* DynamicString::c_str() const{//return the address of strarray
    return strarray;

}

char DynamicString::char_at(int position) const{ //return the char at the position in the shar array
    if(strarray[position] == NULL){
        throw out_of_range("strarray[position]");
    }
    return strarray[position];
}

char& DynamicString::operator[](int position){//return the address of the wanted position
    try{
        (strarray[position] == NULL);
    } catch(const std::exception& e){
        throw out_of_range("strarray[position]");
    }
    return strarray[position];

}

bool DynamicString::startsWith(const DynamicString& other) const{//compare the two strings and see if they start the same string
    int i = other.len() - 1;
    while(i >= 0) {
        if (strarray[i] != other.strarray[i]) {//if they don't, return false
            return false;
        }
        else {//else subtract 1
            --i;
        }
    }
    return true;//if nothing happened, return true;
}

bool DynamicString::endsWith(const DynamicString& other) const{//see if the end with the same string

    int i = other.len(); //get the two lengths of the strings
    int j = len();

    while(i >= 0) { //loop though until the end of string
        if (strarray[j] != other.strarray[i]) {//if they don't match, return false
            return false;
        }
        else {
            --i;
            --j;
        }
    }
    return true;
}

int DynamicString::compare(const DynamicString& other) const { //compare the acsii sizes of the strings,
    int size1 = len();
    int size2 = other.len();

    int i = 1;
    while ((i != size1) || (i != size2)) {//while i is less than the length of either string
        if (strarray[i] < other.strarray[i]) {//if string1 is less than string2, return -1;
            return -1;
        } else if (strarray[i] > other.strarray[i]) {
            return 1;
        }
        i++;
    }
    return 0;
}

int DynamicString::iCompare(const DynamicString& other) const{//same thing as COMPARE but ignoring uppercase
    int size1 = len();
    int size2 = other.len();

    int i = 1;
    while ((i != size1) || (i != size2)) {
        if (tolower(strarray[i]) < tolower(other.strarray[i])) {
            return -1;
        } else if (tolower(strarray[i]) > tolower(other.strarray[i])) {
            return 1;
        }
        i++;
    }
    return 0;
}

DynamicString& DynamicString::toLower(){//set everything to undercase
    int i;
    tolower('A');

    for(i = 0; i < len(); i++) {//while not the end of string
        strarray[i] = tolower(strarray[i]);//set everything to undercase
    }
    return *this;
}
//OLD METHOD
//        if(strarray[i] >= 65 && strarray[i] <= 92)
//        {
//            strarray[i] = strarray[i] + 32;
//        }



DynamicString& DynamicString::toUpper(){
    int i;
    for(i = 0; i <= len(); i++) {//while not end of string
        strarray[i] = toupper(strarray[i]); //set everything to uppercase
    }
    return *this;
}

DynamicString& DynamicString::replace(char old, char newCh) {//replaces a char to a new char
    int len;

    len = DynamicString::len();

    for (int i = 0; i < len; i++) {
        if (strarray[i] == old) {
            strarray[i] = newCh;;//replace char
        }
    }
}

int DynamicString::find(char c, int start) const{//find a character position
    int len;

    len = DynamicString::len();

    for (int i = start; i < len; ++i) {//loop though the length of the string

        if (strarray[i] == c) {//if found, return position
            return start;
        } else if (strarray[i] != c) {//else add to start
            start++;
        }
    }
    return -1;
}

int DynamicString::reverseFind(char c, int start) const{//find char but going backwards
    int len;
    int i;

    for (i = start; i >= 0; --i) {//start at the end of the string until it = to zero
        if (strarray[i] == c) {
            return start;
        } else if (strarray[i] != c) {
            start--;
        }
    }

    return -1;
}

int DynamicString::reverseFind(char c) const{//it like reversefind but starts at the very end
    int len;
    int i;

    len = DynamicString::len();


    for (i = len; i >= 0; --i) {
        if (strarray[i] == c) {
            return len;
        } else if (strarray[i] != c) {
            len--;
        }
    }

    return -1;
}

ostream& operator<<(ostream& out, const DynamicString& str){
    for (int i = 0; i < str.len(); i++) {//loop through the array
        out << str.strarray[i]; //put current array position into out
    }
    return out;//return the ostream
    return out;
}

