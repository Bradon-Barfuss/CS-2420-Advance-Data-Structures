#include <list>
#include <string>

struct Pair {
    Pair(int n, int w){
        node = n;
        weight = w;
    }
    int node;
    int weight;
};
class Graph {
public:
    Graph(std::string);
    int shortestCost(int start, int finish);

private:
    std::list<Pair>* adjList;
    int numNodes;//count how many nodes there are
};
