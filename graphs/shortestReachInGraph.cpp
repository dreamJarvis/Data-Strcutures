#include <bits/stdc++.h>
using namespace std;

class Graph {
    int n;
    unordered_map<int, list<int>> adjList;
public:
    Graph(int n) {
        this->n = n;
    }

    // un-directed
    void add_edge(int u, int v) {
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    vector<int> shortest_reach(int start) {
        queue<int> q;
        vector<bool> visited(n, false);
        vector<int> result(n, -1);

        visited[start] = true;
        result[start] = 0;
        q.push(start);

        while(!q.empty()){
            int s = q.front();
            q.pop();

            for(auto i:adjList[s]){
                if(!visited[i]){
                    result[i] = result[s]+6;
                    visited[i] = true;
                    q.push(i);
                }
            }
        }

        return result;
    }
};

int main() {
    int queries;
    cin >> queries;

    for (int t = 0; t < queries; t++) {

		int n, m;
        cin >> n;
        // Create a graph of size n where each edge weight is 6:
        Graph graph(n);
        cin >> m;
        // read and set edges
        for (int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;
            u--, v--;
            // add each edge to the graph
            graph.add_edge(u, v);
        }
		int startId;
        cin >> startId;
        startId--;
        // Find shortest reach from node s
        vector<int> distances = graph.shortest_reach(startId);

        for (int i = 0; i < distances.size(); i++) {
            if (i != startId) {
                cout << distances[i] << " ";
            }
        }
        cout << endl;
    }

    return 0;
}
