#ifndef GRAPH_H
#define GRAPH_H
#include <stack>
#include <list>
#include <stack>
#include <vector>
#include <iostream>
#include <climits>
#include <algorithm>

using std::endl;
using std::cout;
using std::ostream;
using std::stack;
using std::vector;
using std::list;

/* I have started to use Breadth first search instead of ___ algithm
 * I have made a 2d vector the called vertice (vector<vector<T>>* vertice)
 *
 * The logic of vertex[x].push_back(y) should be working but it isn't
 * See: https://stackoverflow.com/questions/27241177/inserting-elements-into-2d-vector
 *
 * and the logic of vertex[index] = x or vertex.at(index) = x is not working
 * https://stackoverflow.com/questions/2624232/how-to-change-a-particular-element-of-a-c-stl-vector/32834097

 */

template <typename T>
class Graph;

template <typename T>
ostream& operator << (ostream & out, Graph<T> g);

template <typename T>
class Graph{
private:
    int NumberOfvectors;
    //the 2d vector
    vector<vector<T>> TwoDvector;
public:
    Graph();
    Graph(int);
    void addVertex(T vertex);
    void addEdge(T source, T target);
    vector<T> getPath(T, T);
    int findVertexPos(T item);
    int getNumVertices();
    friend ostream& operator << <>(ostream & out, Graph<T> g);
    void pop_front(std::vector<T> &v);
};

//Constructs an empty graph with a max number of verticies of 100
template<typename T>
Graph<T>::Graph(){
    NumberOfvectors = 0;
    TwoDvector.resize(100);
}


//Constructs an empty graph with a given max number of verticies
template<typename T>
Graph<T>::Graph(int maxVerticies){
    TwoDvector.resize(maxVerticies);
    NumberOfvectors = 0;
}

//Adds a Vertex to the GraphIf number of verticies is less than the
//Max Possible number of verticies.
template <typename T>
void Graph<T>::addVertex(T vertex){
    TwoDvector[NumberOfvectors].push_back(vertex);
    NumberOfvectors++;
}


//Returns the current number of vertices
template<typename T>
int Graph<T>::getNumVertices(){
    return NumberOfvectors;
}


// Returns the position in the verticies list where the given vertex is located, -1 if not found.
template <typename T>
int Graph<T>::findVertexPos(T item){

    for (int i = 0; i < NumberOfvectors; ++i) {
        if(TwoDvector[i][0] == item){
            return i;
        }
    }
    return -1;
}


//Adds an edge going in the direction of source going to target
template <typename T>
void Graph<T>::addEdge(T source, T target) {\
    int i = findVertexPos(source);
    if(i != -1){
        TwoDvector[i].push_back(target);
    }
}



/*********************************************
* Returns a display of the graph in the format
* vertex: edge edge
Your display will look something like the following
    9: 8 5
    2: 7 0
    1: 4 0
    7: 6 2
    5: 6 8 9 4
    4: 5 1
    8: 6 5 9access
    3: 6 0
    6: 7 8 5 3
    0: 1 2 3
*********************************************/
template <typename T>
ostream& operator << (ostream & out, Graph<T> g){
    for(int i =0 ; i < g.getNumVertices(); i++){
        out << g.TwoDvector[i][0] << ": ";
        for(int j = 1; j < g.TwoDvector[i].size(); j++){
            out << g.TwoDvector[i][j] << " ";
        }
        out << std::endl;
    }
    return out;
}


/*
  getPath will return the shortest path from source to dest.
  If you would like a challenge, use a depth first search to traverse
  graph to find the solution.  With that sais, you are not limited to
  that altorihtm, you may use breadth first, shortest path first, or any
  other graph algorithm.
  You will return a vector with the solution.  The source will be in position 1
  the destination is in the last position of the solution, and each node in between
  are the verticies it will travel to get to the destination.  There will not be any
  other verticies in the list.
  Given the test graph:

[0]-----------[2]
|  \            \
|   \            \
[1]  [3]----[6]---[7]
|          /  \
|         /    \
|        /      \
|     [5]--------[8]
|    /   \       /
|   /     \     /
|  /       \   /
[4]         [9]
getPath(0, 5) should return
0 -> 1 -> 4 -> 5   or   0 -> 3 -> 6 -> 5

  Hint: As you find the solution store it in a stack, pop all the items of the stack
  into a vector so it will be in the correct order.
*/

template <typename T>
vector<T> Graph<T>::getPath(T s, T dest){
    vector<T> solution;

    bool* visted = new bool[NumberOfvectors];
    for (int i = 0; i < NumberOfvectors; ++i) {
        visted[i] = false;

    }

    vector<T> queue;

    int a = findVertexPos(s);
    visted[a] = true;
    queue.push_back(s);


    while(!queue.empty()) {
        s = queue.front();
        a = findVertexPos(s);
        //   cout << a;

        solution.push_back(s);
        pop_front(queue);
        int first=0;
        for (auto i = TwoDvector[a].begin(); i < TwoDvector[a].end(); ++i) {
            int a = findVertexPos(*i);

            if (first == 0) {
                if (!visted[a]) {
                    // cout << "PUSH FIRST: " << a << endl;
                    visted[a] = true;
                    queue.push_back(*i);
                    first++;

                }
                if (*i == dest) {
                    queue.push_back(*i);
                    solution.push_back(*i);
                    goto here;
                }
            } else {
                if (!visted[a]) {
                    visted[a] = true;
                    if(findVertexPos(queue.front()) <= a){
                        //    cout << "POP_FRONT: " << queue.front() << endl;
                        pop_front(queue);
                        queue.push_back(*i);
                        //   cout << " PUSHED: " << a << endl;
                    }
                }
                if (*i == dest) {
                    queue.push_back(*i);
                    solution.push_back(*i);
                    goto here;
                }
            }
        }
    }

    here:
    for (int j = 0; j < solution.size(); ++j) {
        cout << solution[j] << " ";
    }

    return solution;

}


template<typename T>
void Graph<T>::pop_front(std::vector<T> &v)
{
    if (v.size() > 0) {
        v.front() = std::move(v.back());
        v.pop_back();
    }
}

#endif