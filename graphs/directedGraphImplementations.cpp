// Directed Graph implementations
#include <bits/stdc++.h>
using namespace std;

// Data structure to store Adjacency list nodes
struct Node {
	int val;
	Node* next;
};

// Data structure to store graph edges
struct Edge {
	int src, dest;
};

class Graph{
    // function to allocate new node of adjacency list
    Node* getAdjListNode(int dest, Node *head){
        Node* newNode = new Node;
        newNode->val = dest;
        newNode->next = head;
        return newNode;
    }

    int N;      // no. of nodes in the graph

public:
    // an array of pointers to node to represent adjacency list
    Node **head;

    Graph(Edge edges[], int n, int N){
        // allocate memory
        head = new Node*[N]();
        this->N =  N;


        // initialize head pointer for all vertices
        for(int i = 0; i < N; i++)  head[i] = nullptr;

        // add edges to the directed graph
        for(unsigned i = 0; i < n; i++){
            int src = edges[i].src;
            int dest = edges[i].dest;

            // insert in the beggining
            Node *newNode = getAdjListNode(dest, head[src]);

            // point head pointer to new node
            head[src] = newNode;
        }
    }

    // destructor
    ~Graph(){
        for(int i = 0; i < N; i++)  delete[] head[i];
        delete[] head;
    }
};

void printList(Node *ptr){
    while(ptr != nullptr){
        cout << " -> " << ptr->val << " ";
        ptr = ptr->next;
    }
    cout << endl;
}

// Driver function
int main(){
    Edge edges[] =
    {
        {0, 1}, {1, 2}, {2, 0}, {2, 1},
        {3, 2}, {4, 5}, {5, 4}
    };

    // no. of vertices in graph
    int N = 6;

    // to calculate no. of edges
    int n = sizeof(edges)/sizeof(edges[0]);

    Graph graph(edges, n, N);

    // print adjacency list representation of graph
    for(int i = 0; i < N; i++){
        cout << i << " -- ";
        printList(graph.head[i]);
    }

    return 0;
}
