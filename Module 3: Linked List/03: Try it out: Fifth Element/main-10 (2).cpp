
#include "FifthElement.h"
#include <iostream>
#include <sstream>



void  testGetFifthElement();
void testFiveElements();
void addingFourElements();
void testStrings();
void  testInsertNewFifthElement();
void testInsertNewFifthElementSizeFour();
void  testDeleteFifthElement();
void  testSwapFourthAndFifthElement();

bool checkTest(std::string testName, std::string whatItShouldBe, std::string whatItIs);
bool checkTest(std::string testName, int whatItShouldBe, int whatItIs);
bool checkTestMemory(std::string testName, int whatItShouldBe, int whatItIs);

int main()
{
    testGetFifthElement();
    testFiveElements();
    addingFourElements();
    testStrings();
    testInsertNewFifthElement();
    testInsertNewFifthElementSizeFour();
    testDeleteFifthElement();
    testSwapFourthAndFifthElement();

    return 0;
}



//This helps with testing, do not modify.
bool checkTest(std::string testName, std::string whatItShouldBe, std::string whatItIs) {

    if (whatItShouldBe == whatItIs) {
        std::cout << "Passed " << testName <<std:: endl;
        return true;
    }
    else {
        std::cout << "****** Failed test " << testName << " ****** " << std::endl << "     Output was " << whatItIs << std::endl << "     Output should have been " << whatItShouldBe << std::endl;
        return false;
    }
}

//This helps with testing, do not modify.
bool checkTest(std::string testName, int whatItShouldBe, int whatItIs) {

    if (whatItShouldBe == whatItIs) {
        std::cout << "Passed " << testName << std::endl;
        return true;
    }
    else {
        std::cout << "****** Failed test " << testName << " ****** " << std::endl << "     Output was " << whatItIs << std::endl << "     Output should have been " << whatItShouldBe << std::endl;
        return false;
    }
}

//This helps with testing, do not modify.
bool checkTestMemory(std::string testName, int whatItShouldBe, int whatItIs) {

    if (whatItShouldBe == whatItIs) {
        std::cout << "Passed " << testName << std::endl;
        return true;
    }
    else {
        std::cout << "***Failed test " << testName << " *** " << std::endl << "  You lost track of " << whatItIs << " bytes in memory!" << std::endl;
        return false;
    }
}



//This helps with testing, do not modify.
void testGetFifthElement() {

    FifthElement<int> si;
    for (int i = 10; i < 20; i++) {
        si.insert(i);
    }
    std::ostringstream output;
    output << si;
    //Test just to make sure the data went in the list.
    checkTest("test #1: adding elements", "10 11 12 13 14 15 16 17 18 19", output.str());

    //Test retrieving item.
    int item = si.getFifthElement();
    checkTest("test #2: checking 5th element", 14, item);
}

void testFiveElements(){

    FifthElement<int> si;

    for (int i = 10; i < 15; i++) {
        si.insert(i);
    }
    std::ostringstream output;
    output << si;

    //Test just to make sure the data went in the list.
    checkTest("test #3: adding only 5 elements", "10 11 12 13 14", output.str());

    //Test retrieving item.
    int item = si.getFifthElement();
    checkTest("test #4: checking 5th at end", 14, item);

}

void addingFourElements(){

    FifthElement<int> si;
    for (int i = 10; i < 14; i++) {
        si.insert(i);
    }
    std::ostringstream output;
    output << si;
    //Test just to make sure the data went in the list.
    checkTest("test #5: adding 4 elements", "10 11 12 13", output.str());

    //Try to access out of bounds.
    std::string caughtError = "";
    try {
        int item = si.getFifthElement();
    }
    catch (std::exception& e) {
        caughtError = "caught";
    }
    checkTest("test #6: testing exception ", "caught", caughtError);
}

void testStrings(){

    FifthElement<std::string> ss;
    ss.insert("Fire");
    ss.insert("Water");
    ss.insert("Wind");
    ss.insert("Earth");
    ss.insert("Love");
    ss.insert("Leeloo");
    checkTest("test #7: testing strings", "Love", ss.getFifthElement());

}

//This helps with testing, do not modify.
void testInsertNewFifthElement() {

    FifthElement<int> si;
    for (int i = 10; i < 20; i++) {
        si.insert(i);
    }
    std::ostringstream output;
    output << si;
    //Test just to make sure the data went in the list.
    checkTest("add test #1: int test", "10 11 12 13 14 15 16 17 18 19", output.str());

    //Test inserting an item
    si.insertNewFifthElement(97);

    output.str("");
    output.clear();
    output << si;
    checkTest("add test #2: adding 5th in middle", "10 11 12 13 97 14 15 16 17 18 19", output.str());
}

void testInsertNewFifthElementSizeFour(){
    FifthElement<int> si;
    for (int i = 10; i < 15; i++) {
        si.insert(i);
    }

    std::ostringstream output;
    output << si;
    //Test just to make sure the data went in the list.
    checkTest("add test #3: adding 5 values", "10 11 12 13 14", output.str());

    //Test inserting an item
    si.insertNewFifthElement(97);
    output.str("");
    output.clear();
    output << si;
    checkTest("add test #4: adding 5th near end", "10 11 12 13 97 14", output.str());


    si.remove(0);
    si.remove(0);

    output.str("");
    output.clear();
    output << si;
    //Test just to make sure the data went in the list.
    checkTest("add test #5: adding only 4 values", "12 13 97 14", output.str());

    //Test inserting an item
    si.insertNewFifthElement(97);
    output.str("");
    output.clear();
    output << si;
    checkTest("add test #6: adding to end", "12 13 97 14 97", output.str());

}


//This helps with testing, do not modify.
void testDeleteFifthElement() {
    // Note from the instructor: Please do not delete the actual movie.  It's very good and shouldn't be removed.

    FifthElement<int> si;
    for (int i = 10; i < 20; i++) {
        si.insert(i);
    }
    std::ostringstream output;
    output << si;
    //Test just to make sure the data went in the list.
    checkTest("delete test #1: adding int values", "10 11 12 13 14 15 16 17 18 19", output.str());

    //Test deleting an item
    si.deleteFifthElement();
    output.str("");
    output.clear();
    output << si;

    checkTest("delete test #2: delete 5th value", "10 11 12 13 15 16 17 18 19", output.str());



    FifthElement<int> si2;
    for (int i = 10; i < 15; i++) {
        si2.insert(i);
    }

    output.str("");
    output.clear();
    output << si2;
    //Test just to make sure the data went in the list.
    checkTest("delete test #3: adding only 5", "10 11 12 13 14", output.str());

    si2.deleteFifthElement(); //Test deleting an item

    output.str("");
    output.clear();
    output << si2;

    checkTest("delete test #4: delete last item", "10 11 12 13", output.str());

}


//This helps with testing, do not modify.
void testSwapFourthAndFifthElement() {
    // Note from the instructor: Please do not delete the actual movie.  It's very good and shouldn't be removed.
    FifthElement<int> si ;

    for (int i = 10; i < 20; i++) {
        si.insert(i);
    }
    std::ostringstream output;
    output << si;
    //Test just to make sure the data went in the list.
    checkTest("swap test #1", "10 11 12 13 14 15 16 17 18 19", output.str());
    si.swapFourthAndFifthElement();
    //Test swapping an item
    output.str("");
    output.clear();

    output << si;

    checkTest("swap test #2", "10 11 12 14 13 15 16 17 18 19", output.str());

}
