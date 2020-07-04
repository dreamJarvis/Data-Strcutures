// Find a Mother Vertex in a Graph
#include <bits/stdc++.h>
using namespace std;

class directedGraph{
public:
    unordered_map<int, list<int>> adjList;

    // directed graph
    void addEdge(int v, int u){
        adjList[v].push_back(u);
    }

    // display the adjanceny List
    void display(){
        for(auto item:adjList){
            cout << item.first << "-->";
            for(auto value:item.second)
                cout << value << " ";
            cout << endl;
        }
    }

    int findMotherVertex();
    int DFS(int root);
    int noOfVertices();
};

// time complexity : O(V * E)
int directedGraph::noOfVertices(){
    unordered_set<int> elements{};
    for(auto item:adjList){
        for(auto items:item.second){
            if(!elements.count(items)){
                elements.insert(items);
            }
        }
    }

    int len = elements.size();
    return len;
}

int directedGraph::DFS(int root){
    stack<int> s;
    unordered_map<int, bool> visited;

    s.push(root);

    while(!s.empty()){
        int curr = s.top();
        s.pop();

        if(!s.empty()){
            visited[curr] = true;
        }

        for(auto &value:adjList[curr]){
            if(!visited.count(value))
                s.push(value);
        }
    }

    int len = visited.size();
    return len;
}

// to find the mother vertex
// time complexity : O(V(E+V))
int directedGraph::findMotherVertex(){
    int len = noOfVertices();
    for(auto& vertex:adjList){
        int temp = DFS(vertex.first);
        if(temp == len)
            return vertex.first;
    }

    return -1;
}

// Driver function
int main(){
    directedGraph graph;


    graph.addEdge(0, 1);
    graph.addEdge(0, 2);
    graph.addEdge(1, 3);
    graph.addEdge(4, 1);
    graph.addEdge(5, 2);
    graph.addEdge(5, 6);
    graph.addEdge(6, 0);
    graph.addEdge(6, 4);

    cout << graph.findMotherVertex() << endl;

    return 0;
}
