// to implement Kosaraju's algorithm to print all the Strongly connected components
#include <bits/stdc++.h>
using namespace std;

class Graph{
    int V;                  // no of vertices
    list<int> *adj;         //  list type ka pointer , joki point krega an array of lists, joli adjacency list ko represent krengi hr node ke iss graph me

    // jo node sbse last me khtm hoga wo iss stack ke sbse upr hoga
    void fillOrder(int v, bool visited[], stack<int> &stack);

    // recursively v node se connected sare nodes print krta h
    void DFSUtil(int v, bool visited[]);

public:
    Graph(int V);                   //  initialise graph
    void addEdge(int v, int w);     //   add an edge to the graph

    // finds and prints strongly connected components
    void printSCCs();

    // function that returns reverse of the graph
    Graph reverseGraph();
};

Graph::Graph(int V){
    this->V = V;
    adj = new list<int>[V];         // hr node -> contain krega connected components of that node
}

// a recursive function to print DFS starting from v
void Graph::DFSUtil(int v, bool visited[]){
    // Mark the current node as visited and print it
    visited[v] = true;
    cout << v << " ";

    // recur for all the vertices adjacent to this vertex
    for(auto list:adj[v]){
        if(!visited[list])          //  ki agar iss node ko visit nhi kr rkha toh isspe recur kro
            DFSUtil(list, visited);
    }
}

// graph to reverse krna
Graph Graph::reverseGraph(){
    Graph g(V);

    for(int v = 0; v < V; v++){
        for(auto list:adj[v])
            g.adj[list].push_back(v);
    }

    return g;
}

// directed graph
void Graph::addEdge(int v, int w){
    adj[v].push_back(w);                //  add W to v's list
}

// stack ko fill kr rhe h vertexes ke sath in decreasing order of time interval
// matbl ki jo sbse bash me vertex aayega wo sbse last me insert hoga
// ye v no. of times chelga for v vertices, hr vertex ke connected components stored honge stack me
void Graph::fillOrder(int v, bool visited[], stack<int> &elements){
    visited[v] = true;      //  mark the current node as visited

    // recur from all the vertices adjacent to this vertex
    for(auto items:adj[v]){
        if(!visited[items])
            fillOrder(items, visited, elements);
    }

    // all elements reachable from v are processed by now, push v
    cout << elements.size() << endl;
    elements.push(v);
}

// to find strongly connected components
void Graph::printSCCs(){
    stack<int> Stack;

    // pehle initially koi bhi node visited nhi h
    bool *visited = new bool[V];
    for(int i = 0; i < V; i++)
        visited[i] = false;

    // fill vertices in stack according to their finishing time
    for(int i = 0; i < V; i++){
        if(visited[i] = false)
            fillOrder(i, visited, Stack);
    }

    // create a reversed graph
    Graph reversedGraph = reverseGraph();

    // mark all the vertices as non visited
    for(int i = 0; i < V; i++)
        visited[i] = false;


    cout << Stack.size() << endl;

    // now process all vertices in order defined by stack
    while(!Stack.empty()){
        // cout << "chl rha h ya nhi ?" << endl;
        int v = Stack.top();        //  pop a vertex from stack
        Stack.pop();

        if(visited[v] == false){
            cout << "Strongly connected components : ";
            reversedGraph.DFSUtil(v, visited);
            cout << "\n\n";
        }
    }
}

// Driver function
int main(){
    Graph g(5);

    g.addEdge(1, 0);
    g.addEdge(0, 2);
    g.addEdge(2, 1);
    g.addEdge(0, 3);
    g.addEdge(3, 4);

	cout << "Following are strongly connected components in given graph \n";

    g.printSCCs();

    return 0;
}
