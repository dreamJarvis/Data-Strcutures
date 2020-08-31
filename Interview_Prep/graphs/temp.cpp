#include <bits/stdc++.h>
using namespace std;

#define INF INT_MAX
typedef pair<int, int> iPair;

class Graph{
    int V;
    list<iPair> *adj;
public:
    Graph(int V) : V(V), adj(new list<iPair>[V]) {}
    void addEdge(int u, int v, int w);
    void shortestPath(int src);
};

void Graph::addEdge(int u, int v, int w){
    adj[u].push_back({v, w});
    adj[v].push_back({u, w});
}

void Graph::shortestPath(int src){
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

    cout << "vector \tDistance from source node\n";
    for(int i = 0; i < V; i++)
        cout << " " << i << "\t\t" << dist[i] << endl;
}

// Driver function
int main(){
    // create the graph given in above fugure
    int V = 9;
    Graph g(V);

    //  making above shown graph
    g.addEdge(0, 1, 4);
    g.addEdge(0, 7, 8);
    g.addEdge(1, 2, 8);
    g.addEdge(1, 7, 11);
    g.addEdge(2, 3, 7);
    g.addEdge(2, 8, 2);
    g.addEdge(2, 5, 4);
    g.addEdge(3, 4, 9);
    g.addEdge(3, 5, 14);
    g.addEdge(4, 5, 10);
    g.addEdge(5, 6, 2);
    g.addEdge(6, 7, 1);
    g.addEdge(6, 8, 6);
    g.addEdge(7, 8, 7);

    g.shortestPath(0);

    return 0;
}
