#include <iostream>
#include "Graph.h"
#include <string>
#include <fstream>
#include <iomanip>

int main() {
    Graph g1("thisisa.txt");
    std::cout << "0->3" << g1.shortestCost(0, 3) << std::endl;
    std::cout << "0->1" << g1.shortestCost(0, 1) << std::endl;
    std::cout << "0->2" << g1.shortestCost(0, 2) << std::endl;
//0->3:2
//0->1:3
//0->2:4
    return 0;
}