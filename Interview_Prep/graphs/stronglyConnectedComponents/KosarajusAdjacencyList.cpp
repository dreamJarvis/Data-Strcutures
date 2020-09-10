/*
    Strongly Connected Components
    https://www.geeksforgeeks.org/strongly-connected-components/
*/
#include <iostream>
#include <list>
#include <stack>
using namespace std;

// TC : O(V+E)
class Graph {
    int V;                  // no. of vertices
    list<int> *adj;         // adjacency list
    /* fills Stack woth vertices (in increasing order of finishing times)
    The top element of stacks has the maximum finishing time
    */
    void fillOrder(int v, bool visited[], stack<int> &Stack);

    // a recursive function to print DFS starting from v
    void DFSUtil(int v, bool visited[]);
public:
    Graph(int V) : V(V), adj(new list<int>[V]) {}
    void addEdge(int v, int w);

    /*Kosaraju's algorithm to find SCC's*/
    void printSCCs();

    // get's the transpose of the matrix
    Graph getTranspose();
};

void Graph::addEdge(int u, int v){
    adj[u].push_back(v);
}

void Graph::fillOrder(int v, bool visited[], stack<int> &Stack){
    // marks the current node as visited and print it
    visited[v] = true;

    // recur for all the neighbours
    for(auto i:adj[v])
        if(!visited[i])                         // if not visited, then only visit it
            fillOrder(i, visited, Stack);

    // all v's neighbours has been processed by now
    Stack.push(v);
}

// reversing the edges of the graph
Graph Graph::getTranspose(){
    Graph g(V);

    // transposing the edges
    for(int v = 0; v < V; v++)
        for(auto i:adj[v])
            g.adj[i].push_back(v);

    return g;
}

// recursively print all the neighbours of v using DFS
void Graph::DFSUtil(int v, bool visited[]){
    visited[v] = true;
    cout << v << " ";

    for(auto i:adj[v])
        if(!visited[i])
            DFSUtil(i, visited);
}

void Graph::printSCCs(){
    stack<int> Stack;
    bool *visited = new bool[V];
    for(int i = 0; i < V; i++)      // mark all the node as not visited
        visited[i] = false;

    // fill the vertices in stack according to their finishing times
    for(int i = 0; i < V; i++)
        if(!visited[i])
            fillOrder(i, visited, Stack);

    // reversing the order of the graph
    Graph reverseOrder = getTranspose();

    // mark all the vertices as not visited
    for(int i = 0; i < V; i++)
        visited[i] = false;

    // process all the vertices in order defined by the Stack
    while(!Stack.empty()){
        int v = Stack.top();
        Stack.pop();

        // print's SCC's
        if(!visited[v]){
            reverseOrder.DFSUtil(v, visited);
            cout << endl;
        }
    }
}

// Driver function
int main(){
    // Create a graph given in the above diagram
    Graph g(5);
    g.addEdge(1, 0);
    g.addEdge(0, 2);
    g.addEdge(2, 1);
    g.addEdge(0, 3);
    g.addEdge(3, 4);

    cout << "SCC's of Graph 1 : \n";
    g.printSCCs();

    Graph g8(8);
    g8.addEdge(3, 7);
    g8.addEdge(3, 4);
    g8.addEdge(7, 3);
    g8.addEdge(7, 5);
    g8.addEdge(4, 5);
    g8.addEdge(5, 6);
    g8.addEdge(5, 0);
    g8.addEdge(6, 2);
    g8.addEdge(6, 4);
    g8.addEdge(6, 0);
    g8.addEdge(2, 0);
    g8.addEdge(0, 1);
    g8.addEdge(1, 2);

    cout << "\nSCC's of Graph 2 : \n";
    g8.printSCCs();


    Graph g1(5);
    g1.addEdge(1, 0);
    g1.addEdge(0, 2);
    g1.addEdge(2, 1);
    g1.addEdge(0, 3);
    g1.addEdge(3, 4);

    cout << "\nSCC's of Graph 3 : \n";
    g1.printSCCs();

    Graph g2(4);
    g2.addEdge(0, 1);
    g2.addEdge(1, 2);
    g2.addEdge(2, 3);

    cout << "\nSCC's of Graph 4 : \n";
    g2.printSCCs();

    Graph g3(7);
    g3.addEdge(0, 1);
    g3.addEdge(1, 2);
    g3.addEdge(2, 0);
    g3.addEdge(1, 3);
    g3.addEdge(1, 4);
    g3.addEdge(1, 6);
    g3.addEdge(3, 5);
    g3.addEdge(4, 5);

    cout << "\nSCC's of Graph 5 : \n";
    g3.printSCCs();

    Graph g4(11);
    g4.addEdge(0,1);g4.addEdge(0,3);
    g4.addEdge(1,2);g4.addEdge(1,4);
    g4.addEdge(2,0);g4.addEdge(2,6);
    g4.addEdge(3,2);
    g4.addEdge(4,5);g4.addEdge(4,6);
    g4.addEdge(5,6);g4.addEdge(5,7);g4.addEdge(5,8);g4.addEdge(5,9);
    g4.addEdge(6,4);
    g4.addEdge(7,9);
    g4.addEdge(8,9);
    g4.addEdge(9,8);

    cout << "\nSCC's of Graph 6 : \n";
    g4.printSCCs();

    Graph g5(5);
    g5.addEdge(0,1);
    g5.addEdge(1,2);
    g5.addEdge(2,3);
    g5.addEdge(2,4);
    g5.addEdge(3,0);
    g5.addEdge(4,2);

    cout << "\nSCC's of Graph 7 : \n";
    g5.printSCCs();


    return 0;
}
