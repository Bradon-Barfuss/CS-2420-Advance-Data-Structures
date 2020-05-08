#include "Graph.h"
#include <fstream>
#include <cstdint>
#include <stdexcept>
#include <climits>

using std::list;
using std::ifstream;
using std::invalid_argument;

Graph::Graph(std::string filename) {
    ifstream input;
    input.open(filename);
    if (!input){
        throw invalid_argument("could not find file");
    }
    input >> numNodes;
    adjList = new list<Pair>[numNodes]
;    for (int i = 0; i < numNodes; ++i) {
        int value;
        int cost;
        input >> value;
        while(value >= 0){
            input >> cost;
            adjList[i].push_back(Pair(value, cost));
            input >> value;
        }
    }
}

int Graph::shortestCost(int start, int finish) {
    int *dist = new int[numNodes];
    list<int> remaining;
    list<int> finished;
    for (int i = 0; i < numNodes; ++i) {
        if (i == start) {
            dist[i] = 0;
        } else {
            dist[i] = INT_MAX;
        }
        remaining.push_back(i);
    }
    while (!remaining.empty()) {
        int minDist = INT_MAX;
        int minIndex = -1;
        for (list<int>::iterator listIt = remaining.begin(); listIt != remaining.end(); listIt++) {
            if (dist[*listIt] < minDist) {
                minDist = dist[*listIt];
                minIndex = *listIt;
            }
        }
        int cur = minIndex;
        for (list<Pair>::iterator listIt = adjList[cur].begin(); listIt != adjList[cur].end(); listIt++) {
            int next = (*listIt).node;
            int nextweight = (*listIt).weight;
            if (dist[cur] + nextweight < dist[next]) {
                dist[next] = dist[cur] + nextweight;
            }
        }
        remaining.remove(cur);
        finished.push_back(cur);
    }
    int shortCost = dist[finish];
    delete[] dist;
    return shortCost;
    //

    //
}
