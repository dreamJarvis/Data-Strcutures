// adjacency list
#include <bits/stdc++.h>
using namespace std;

void displayAdjList(unordered_map<int, list<int> > &adjList){
    for(auto items:adjList){
        cout << items.first << "-->";

        for(auto values:items.second)
            cout << values << " ";
        cout << endl;
    }
}

// inserting values into the list
void addEdge(unordered_map<int, list<int>> &adjList, int v, int u){
    adjList[v].push_back(u);
    adjList[u].push_back(v);
}

// Driver function
int main(){
    unordered_map<int, list<int>> adjList;

    addEdge(adjList, 3, 7);
    addEdge(adjList, 3, 4);
    addEdge(adjList, 4, 5);
    addEdge(adjList, 4, 6);
    addEdge(adjList, 4, 7);
    addEdge(adjList, 5, 6);
    addEdge(adjList, 6, 7);

    displayAdjList(adjList);
    return 0;
}
