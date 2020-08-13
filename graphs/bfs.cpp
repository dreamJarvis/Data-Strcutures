// bfs : breadth first implementation of a undirected graph
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

    void BFS(int s);                //  bfs traversal
};


// breadth firs traversal of the graph
// goes wide : forms concentric circles, around the root element
void Graph::BFS(int root){
    cout << "\n\nBFS : \t";

    queue<int> q;
    unordered_map<int, bool> visited;

    q.push(root);

    while(!q.empty()){
        int curr = q.front();
        q.pop();

        if(!visited.count(curr)){
            visited[curr] = true;
            cout << curr << " ";
        }

        for(auto value:adjList[curr]){
            if(!visited.count(value)){
                q.push(value);
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

    list.BFS(7);

    return 0;
}
