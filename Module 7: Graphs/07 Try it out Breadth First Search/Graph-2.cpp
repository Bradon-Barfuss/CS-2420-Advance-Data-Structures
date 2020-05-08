#include "Graph.h"
#include <list>
#include <fstream>
#include <cstdint>
#include <stdexcept>
#include <climits>
#include <iostream>
#include <sstream>

using std::list;
using std::ifstream;
using std::invalid_argument;
using namespace std;

Graph::Graph(std::string filename) {
    ifstream input;
    input.open(filename);
    if (!input){
        throw invalid_argument("could not find file");
    }
    input >> numNodes;
    adjList = new list<int>[numNodes]
;    for (int i = 0; i < numNodes; ++i) {
        int value;
        input >> value;
        while(value >= 0){
            adjList[i].push_back(value);
            input >> value;
        }
    }
}

std::ostream& Graph::printBFS(std::ostream& output, int s){
    bool* visted = new bool[numNodes];
    for (int i = 0; i < numNodes; ++i) {
        visted[i] = false; //set the intial visted array to false
    }

    list<int> queue;//make a list for a queue

    visted[s] = true;
    queue.push_back(s);
    list<int>::iterator i;

    while(!queue.empty()){
        s = queue.front();//get the current node we will look at
        output << s << " ";
        queue.pop_front();//remove the current node from the queue
        //check adjacent nodes
        for(i = adjList[s].begin(); i != adjList[s].end(); i++){
            if(!visted[*i]) {//if we have not checked this current node
                visted[*i] = true;
                queue.push_back(*i);
            }
        }
    }
    return output;
}