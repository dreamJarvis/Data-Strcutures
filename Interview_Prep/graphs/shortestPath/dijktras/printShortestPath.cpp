/*
    Printing Paths in Dijkstra’s Shortest Path Algorithm
    https://www.geeksforgeeks.org/printing-paths-dijkstras-shortest-path-algorithm/
*/
#include <bits/stdc++.h>
using namespace std;

#define INF INT_MAX                 // defines infinity
typedef iPair pair<int, int>;       // representing variables as pair

class Graph{
    int V;
    list<iPair> *adj;
public:
    Graph(int V) : V(V), adj(new list<iPair>[V]) {}
    void addEdge(int u, int v, int weight);
    void shortestPath(int src);
};

void Graph::addEdge(int u, int v, int weight){
    adj[u].push_back({v, weight});
}

void shortestPath(int src){
    priority_queue<iPair, vector<iPair>, greater<iPair>> pq;
    vector<int> dist(V, INF);

    pq.push({0, src});
    dist[src] = 0;

    while(!pq.empty()){
        int u = pq.top().second;
        pq.pop();

        for(auto i:adj[u]){
            int v = i.first;
            int weight = i.second;

            if(dist[v] > dist[u] + weight){
                dist[v] = dist[u] + weight;
                pq.push({dist[v], v});
            }
        }
    }
}

// Driver function
int main(){

    return 0;
}
