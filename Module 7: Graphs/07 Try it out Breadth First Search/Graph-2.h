#include <list>
#include <string>
#include <ostream>

class Graph {
public:
    Graph(std::string);
    std::ostream& printBFS(std::ostream& str, int s);

private:
    std::list<int>* adjList;
    int numNodes;//count how many nodes there are
};
