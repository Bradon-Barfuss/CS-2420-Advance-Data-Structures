#include <iostream>
#include "Graph.h"
#include <string>
#include <fstream>
#include <iomanip>

int main() {
    Graph g1("graph2.txt");
    std::ostringstream output;
    g1.printBFS(output, 2);
    std::cout << output.str();
    return 0;
}