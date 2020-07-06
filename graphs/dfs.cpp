// bfs : breadth firsg implementation of a undirected graph
#include <bits/stdc++.h>
using namespace std;

// this class represents a unidrected graph using adjacency list
class Graph{
    unordered_map<int, list<int>> adjList;

public:
    // inserting values into the list
    void addEdge(int v, int u){
        adjList[v].push_back(u);
        adjList[u].push_back(v);
    }

    // displays the adjancecy list
    void display(){
        for(auto items:adjList){
            cout << items.first << "-->";
            for(auto values:items.second)
                cout << values << " ";
            cout << endl;
        }
    }

    void DFS(int s);                //  dfs traversal
};


// Depth firs traversal of the graph
// goes deeeeeeeeep: it will exhaust every connected element to the root element, then move to another element int the list
// V -> vertices, E -> edges
// time complexity : O(|v| + |E|)
// space complexity : O(|v|)
void Graph::DFS(int root){
    cout << "\n\nDFS : \t";

    stack<int> s;
    unordered_map<int, bool> visited;

    s.push(root);

    while(!s.empty()){
        int curr = s.top();
        s.pop();

        // if this node has not been visited
        if(!visited.count(curr)){
            visited[curr] = true;
            cout << curr << " ";
        }

        for(auto value:adjList[curr]){
            // if this node has not been visited
            if(!visited.count(value)){
                s.push(value);
            }
        }
    }
}

// Driver function
int main(){
    Graph list;

    list.addEdge(1, 2);
    list.addEdge(1, 6);
    list.addEdge(2, 7);
    list.addEdge(2, 3);
    list.addEdge(3, 4);
    list.addEdge(4, 7);
    list.addEdge(4, 8);
    list.addEdge(4, 5);
    list.addEdge(8, 6);
    list.addEdge(8, 7);
    list.addEdge(5, 6);

    list.display();

    list.DFS(7);

    return 0;
}
