// floyd warshall algorithm
#include <bits/stdc++.h>
using namespace std;

// umber of vertices in graph
#define V 4

// Dfine infinite as a large enough number value.These values will be used for vertices not connected to each other
#define INF 999999

// A function to print the solution matrix
void printSolution(int dist[][V]);

// all pairs shortest path problem
void floydWarshall(int graph[][V]){
    // dist[][V] will be the output matrix that will finally have the shortest distances between every pair of vertices
    int dist[V][V], i, j, k;

    // initialize the solution matrix same as input graph matrix, or we can say initial values of shortest distances are based on shortest path considering no intermediate vertex
    for(i = 0; i < V; i++){
        for(j = 0; j < V; j++){
            dist[i][j] = graph[i][j];
        }
    }

    // hr next k'th value usse previous values pr updation krta h
    // kyuki hm already existing values me se he values utha ke table ko update kr rhe h
    for(k = 1; k < V; k++){
        // pick all vertices as source one by one
        for(i = 0; i < V; i++){

            // pick all vertices as destination for the above picked source
            for(j = 0; j < V; j++){

                // agar vertex k se hme shorter path mil rha h toh hm dist[i][j] ki values ko update kr denge
                // if i ---> k ---> j  < i -- > j, then update the values
                if(dist[i][k] + dist[k][j] < dist[i][j])
                    dist[i][j] = dist[i][k] + dist[k][j];
            }
        }
    }

    printSolution(dist);
}

void printSolution(int dist[][V]){
    cout << "Shortest distance between every pair of vertices \n" << endl;

    for(int i = 0; i < V; i++){
        for(int j = 0; j < V; j++){
            if(dist[i][j] == INF)
                cout << "INF" << "\t";
            else
                cout << dist[i][j] << "\t";
        }
        cout << endl;
    }
}

// Driver function
int main(){
    int graph[V][V] = {
        {0, 5, INF, 10},
        {INF, 0, 3, INF},
        {INF, INF, 0, 1},
        {INF, INF, INF, 0}
    };

    // print the solution
    floydWarshall(graph);
    // printSolution(graph);

    return 0;
}
