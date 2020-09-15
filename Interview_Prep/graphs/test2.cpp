#include <iostream>
using namespace std;

#define V 5
#define INF 999999

int minKey(int key[], bool mstSet[]){
    int minVal = INF, minIndex;
    for(int i = 0; i < V; i++){
        if(!mstSet[i] && key[i] < minVal){
            minVal = key[i];
            minIndex = i;
        }
    }

    return minIndex;
}

void printMST(int parent[], int graph[V][V]){
    for(int i = 1; i < V; i++)
        cout << parent[i] <<  " - " << i << "\t" << graph[i][parent[i]] << endl;
}

void primMST(int graph[V][V]){
    int key[V];
    int parent[V];
    bool mstSet[V];

    for(int i = 0; i < V; i++){
        key[i] = INF;
        mstSet[i] = false;
    }

    parent[0] = -1;
    key[0] = 0;

    for(int count = 0; count < V-1; count++){
        int u = minKey(key, mstSet);

        mstSet[u] = true;

        for(int v = 0; v < V; v++){
            if(graph[u][v] && !mstSet[v] && graph[u][v] < key[v]){
                key[v] = graph[u][v];
                parent[v] = u;
            }
        }
    }

    printMST(parent, graph);
}

// Driver function
int main(){
    int graph[V][V] = {
        {0, 2, 0, 6, 0},
        {2, 0, 3, 8, 5},
        {0, 3, 0, 0, 7},
        {6, 8, 0, 0, 9},
        {0, 5, 7, 9, 0}
    };

    primMST(graph);

    return 0;
}
