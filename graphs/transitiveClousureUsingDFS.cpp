/*
Given a directed graph, find out if a vertex v is reachable from another vertex u for all vertex pairs (u, v) in the given graph. Here reachable mean that there is a path from vertex u to v. The reach-ability matrix is called transitive closure of a graph.
*/
// to print the transitive closure of a graph using DFS
#include <bits/stdc++.h>
using namespace std;

class Graph{
    int V;                      // no. of vertices
    bool **tc;                  // to store transitive closure
    list<int> *adj;             // array of adjacency lists
    void DFSUtil(int u, int v);

public:
    Graph(int V);

    // function to add an edge to graph
    void addEdge(int v, int w){
        adj[v].push_back(w);
    }

    // to print transitive clousure matrix
    void transitiveClosure();
};

// initializing graph
Graph::Graph(int V){
    this->V = V;
    adj = new list<int>[V];

    tc = new bool*[V];

    for(int i = 0; i < V; i++){
        tc[i] = new bool[V];
        memset(tc[i], false, V*sizeof(bool));
    }
}

void Graph::DFSUtil(int s, int v){
    // marks the reachability from s --> t as true
    tc[s][v] = true;

    // find all the vertices reachable through vertex v
    for(auto i:adj[v]){
        if(!tc[s][i])
            DFSUtil(s, i);
    }
}

// This function finds transitive clousures. It uses recursive DFSUtil()
void Graph::transitiveClosure(){
    // every  vertex is reachable from self
    for(int i = 0; i < V; i++)
        DFSUtil(i, i);

    for(int i = 0; i < V; i++){
        for(int j = 0; j < V; j++)
            cout << tc[i][j] << "\t";
        cout << endl;
    }
}

// Driver function
int main(){
    Graph g(4);

    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);

    cout << "Transitive clousure matrix is \n\n";
    g.transitiveClosure();

    return 0;
}
