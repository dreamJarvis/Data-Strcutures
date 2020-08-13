/*
Transitive closure of a graph
Given a directed graph, find out if a vertex j is reachable from another vertex i for all vertex pairs (i, j) in the given graph. Here reachable mean that there is a path from vertex i to j. The reach-ability matrix is called transitive closure of a graph.
*/

// program to print the transitive clousure using floyd-Warshall algo
#include <bits/stdc++.h>
using namespace std;

// number of vertices in the graph
#define V 4

// a function to print the solution matrix
void printSolution(int reach[][V]);

// prints transitive closure of graph[][] using floyd warshall algorithm
void transitiveClosure(int graph[][V]){
    int reach[V][V];

    // for the first vertex, if it can reach all the vertices
    for(int i = 0; i < V; i++){
        for(int j = 0; j < V; j++){
            reach[i][j] = graph[i][j];
        }
    }

    for(int k = 0; k < V; k++){
        for(int i = 0; i < V; i++){
            for(int j = 0; j < V; j++){
                reach[i][j] = reach[i][j] || (reach[i][k] && reach[k][j]);
            }
        }
    }

    printSolution(reach);
}

void printSolution(int reach[][V]){
    cout << "Transitive clousure of the given graph" << endl;

    for(int i = 0; i < V; i++){
        for(int j = 0; j < V; j++){
            cout << reach[i][j] << "\t";
        }
        cout << endl;
    }
}

// Driver function
int main(){
    int graph[V][V] = {
        {1, 1, 0, 1},
        {0, 1, 1, 0},
        {0, 0, 1, 1},
        {0, 0, 0, 1}
    };

    transitiveClosure(graph);

    return 0;
}
