// A C++ program for Prim's Minimum Spanning Tree (MST) algorithm.
// The program is for adjacency matrix representation of the graph
#include <bits/stdc++.h>
using namespace std;

// Number of vertices in the graph
#define V 5

// mstSet --> it contains vertex that are already considered in the MST
// key --> it contains the weight of all the edges that the current root vertex will make with the rest of the vertexes that are not considered in the MST

// keys[] me hr vertes ke liye jo usse minimum weight wala edge bnega ussme uski value rkhenge, and hmne Initialize keys to hr vertex ke liye INT_MAX se kiya h, and hmne condition ye lgai h ki, hm previous wo vertexes include nhi krenge jo already hm MST ke account me le chuke h
// so abhi currently keys[] me jo bhi values h , wo un vertexes ki h jo toh hmare current root vertex (jiske through hm agla vertex dhundh rhe h) se koi edge bna rhe h, ya unki abhi bhi Initialize nhi hue
/* isiliye hm following funciton me hm hr us keys ki value ke liye check rhe h,
        1) jiska vertex MST me already included na ho,
        2) edg with minimum key values, i.e. min weight
*/
int minKey(int key[], bool mstSet[]){
    int min = INT_MAX, min_vertex;

    // to find the next root element, by selecting the edge whose weight is minimum
    for(int v = 0; v < V; v++){
        if(mstSet[v] == false && key[v] < min){
            min = key[v], min_vertex = v;
        }
    }

    // root element, jise jude hua edges nikaalenge hm primMST() me
    return min_vertex;
}

// a utility function to print thr constucted MST stored in parent[]
void printMST(int parent[], int graph[V][V]){
    cout << "Edge \t Weight\n";
    for(int i = 1; i < V; i++)
        cout << parent[i] << " - " << i << "\t" << graph[i][parent[i]] << endl;
}

// Function to construct and print MST for a graph represented using adjacency matrix representation
void primMST(int graph[V][V]){
    int parent[V];      // ye MST store rkhega
    int key[V];         // weight of edge
    bool mstSet[V];     // vertexs already used MST

    // Initialize all edges weight as INT_MAX
    for(int i = 0; i < V; i++){
        key[i] = INT_MAX, mstSet[i] = false;
    }

    // always include first vertex in MST, make key 0, so that vertex is picked as first vertex
    key[0] = 0;
    parent[0] = -1; // first node is always root in MST

    // MST will have V vertices
    for(int count = 0; count < V-1; count++){
        // abhi ye wo vetex pick up krega jo mstSet me nhi h, and jiske edge ki value min h keys me
        int u = minKey(key, mstSet);

        // ye root vertex ko true set kr denge, cause we have included in the MST
        mstSet[u] = true;


        // Update key value and parent index of the adjacent vertices of the picked vertex.
        // Consider only those vertices which are not yet included in MST

        // ab root vertex se jitne bhi vertex edge bna rhe, unmese jiska minimum weight higa, hm usse select krenge, and then ussko as a next root element le knege..yhi process chlta rhega  graph ke hr vetex ke liye
        for(int v = 0; v < V; v++){
            // graph[u][v] is non zero only for adjacent vertices of m
            // mstSet[v] is false for vertices not yet included in MST
            // Update the key only if graph[u][v] is smaller than key[v]
            if(graph[u][v] && mstSet[v] == false && graph[u][v] < key[v])
                parent[v] = u, key[v] = graph[u][v];
        }
    }

    // prints the MST
    printMST(parent, graph);
}

// Driver code
int main(){
    int graph[V][V] = { { 0, 2, 0, 6, 0 },
                        { 2, 0, 3, 8, 5 },
                        { 0, 3, 0, 0, 7 },
                        { 6, 8, 0, 0, 9 },
                        { 0, 5, 7, 9, 0 } };

    // Print the solution
    primMST(graph);

    return 0;
}
