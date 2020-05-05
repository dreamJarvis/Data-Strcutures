#include <bits/stdc++.h>
using namespace std;

// displays the list
void display(list<int> adj_list[], int v){
    cout << "adjacency list : \n\n";
    for(int i = 0; i < v; i++){
        cout << i << " ---> ";

        for(auto value: adj_list[i])
            cout << value << " ";
        cout << endl;
    }
}

// inserting edges for each vertex
// undirected graph
void add_edge(list<int> adj_list[], int u, int v){
    adj_list[u].push_back(v);
    adj_list[v].push_back(u);
}

// Driver function
int main(){
    int vertex = 5;

    list<int> adj_list[vertex];

    // for 0
    add_edge(adj_list, 3, 7);
    add_edge(adj_list, 3, 4);
    add_edge(adj_list, 4, 5);
    add_edge(adj_list, 4, 6);
    add_edge(adj_list, 4, 7);
    add_edge(adj_list, 5, 6);
    add_edge(adj_list, 6, 7);


    display(adj_list, vertex);

    return 0;
}
