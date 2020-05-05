// adjacency List
#include <bits/stdc++.h>
using namespace std;

// adjacency list : filling the list
void adjacencyListGraph(unordered_map<int, list<int>> &arr, int n){
    int vertex;
    int edges;
    for(int i = 0; i < n; i++){
        cout << "vertex : ";
        cin >> vertex;
        cout << "no. of edges : ";
        cin >> edges;

        list<int> edge;
        int temp_1;
        cout << "Enter edges : \t";
        for(int i = 0; i < edges; i++){
            cin >> temp_1;
            edge.push_back(temp_1);
        }

        arr[vertex] = edge;
    }
}

// displaying the list
void display(unordered_map<int, list<int>> &arr){
    cout << "adjacency List: " << endl;
    for(auto value: arr){
        cout << value.first << " --> ";

        list<int> temp = arr[value.first];
        for(auto val: temp){
            cout << val << ", ";
        }
        cout << endl;
    }
}

// Driver function
int main(){
    // no. of vertices
    cout << "No. of vertex : \t";
    int n;
    cin >> n;

    unordered_map<int, list<int>> adjacencyList;

    adjacencyListGraph(adjacencyList, n);
    display(adjacencyList);

    return 0;
}
