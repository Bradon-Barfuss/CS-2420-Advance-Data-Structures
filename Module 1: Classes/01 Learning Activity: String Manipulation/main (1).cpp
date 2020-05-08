#include "StringFunctions.h"
#include <iostream>
#include <stdexcept>
#include <cstring>

using std::cout;
using std::endl;
using std::out_of_range;
using std::strcmp;

template <typename T>
void test(int testNum, int& correct, T actual, T expected){

   if(actual == expected){
      correct++;
      cout << "Passed Test " << testNum << endl;
   }
   else{
      cout << "***Failed Test " << testNum << "***" << endl;
      cout << "Actual: " << actual << " Expected: " << expected << endl;
   }
}

void testString(int testNum, int& correct, const char* actual, const char* expected){

   if(actual && expected && strcmp(actual, expected) == 0){
      correct++;
      cout << "Passed Test " << testNum << endl;
   }
   else{
      cout << "***Failed Test " << testNum << "***" << endl;
      if(actual && expected){
         cout << "Actual: " << actual << " Expected: " << expected << endl;
      }
   }
}

int main(){

   int testNum  = 1;
   int correct = 0;

   /*Static string length tests*/
   cout << "--------Length Tests--------" << endl;
   test(testNum++, correct, StringFunctions::myStringLen("a"), 1);
   test(testNum++, correct, StringFunctions::myStringLen("abc"), 3);
   test(testNum++, correct, StringFunctions::myStringLen("a12db932"), 8);
   test(testNum++, correct, StringFunctions::myStringLen("aaa"), 3);
   test(testNum++, correct, StringFunctions::myStringLen(""), 0);
   test(testNum++, correct, StringFunctions::myStringLen("fun"), 3);
   test(testNum++, correct, StringFunctions::myStringLen("some super duper long string that does not say anyting important at all."), 72);
   test(testNum++, correct, StringFunctions::myStringLen("just a few more strings"), 23);
   test(testNum++, correct, StringFunctions::myStringLen("It should handle !@#$%^&*"), 25);
   test(testNum++, correct, StringFunctions::myStringLen("Yeah!"), 5);

   cout << "Passed " << correct << "/" << --testNum << " tests" << endl;
   cout << "Score: " << correct/float(testNum) << endl;
   cout << "Points: " << 60*correct/float(testNum) << endl;

}