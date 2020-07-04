// find mother vertex in a graph
#include <bits/stdc++.h>
using namespace std;

class Graph {
    int V;
    list<int> *adj;
    void DFSUtil(int v, vector<bool> &visited);
public:
    Graph(int V);
    void addEdge(int v, int w);
    int findMother();
};

Graph::Graph(int V){
    this->V = V;
    adj = new list<int>[V];
}

// DFS Traversal on every node/vertex
// yha pr do he cheeze ho skti h, ya toh current node se sare node visit kr payenge, ya hm kisi leaf nodes se exit kr jayenge, ya hm kisi sub-graph ke group me phas jayenge
void Graph::DFSUtil(int v, vector<bool> &visited){
    visited[v] = true;
    for(auto i:adj[v]){
        if(!visited[i])
            DFSUtil(i, visited);
    }
}

// adding edge to the graph
void Graph::addEdge(int v, int w){
    adj[v].push_back(w);
}

int Graph::findMother(){
    vector<bool> visited(V, false);
    int v = 0;

    // hr wo node jis pr hm current node se visit nhi kr paye, hm waha se chek krenge ki kya mother vertex mil skta he ya nhi
    for(int i = 0; i < V; i++){
        if(visited[i] == false){
            DFSUtil(i, visited);
            v = i;
        }
    }

    fill(visited.begin(), visited.end(), false);
    DFSUtil(v, visited);

    // agr v se koi bhi node visited nhi h toh ye mother vertex nhi h
    for(int i=0; i < V; i++){
        if(visited[i] == false)
            return -1;
    }

    return v;
}

int main(){
	// Create a graph given in the above diagram
	Graph g(7);
	g.addEdge(0, 1);
	g.addEdge(0, 2);
	g.addEdge(1, 3);
	g.addEdge(4, 1);
	g.addEdge(6, 4);
	g.addEdge(5, 6);
	g.addEdge(5, 2);
	g.addEdge(6, 0);

	cout << "A mother vertex is " << g.findMother();

	return 0;
}
