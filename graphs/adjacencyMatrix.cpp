#include <bits/stdc++.h>
using namespace std;

// inserting in the matrix
void adjacencyMatrix(vector<vector<int>> &matrix, int n){
    bool flag = false;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout << i << j << " : " ;
            cin >> flag;
            matrix[i][j] = int(flag);
        }

        cout << endl;
    }
}

// display Matrix
void displayMatrix(vector<vector<int>> &arr){
    int n = arr.size();

    for(int i = 0; i < n; i++){
        cout << i << " --> ";
        for(int j = 0; j < n; j++){
            cout << arr[i][j] << ", ";
        }

        cout << endl;
    }
}

// Driver function
int main(){
    // no. of vertices
    int n;
    cin >> n;

    // initializing a 2d matrix
    vector<vector<int>> matrix(n, vector<int>(n, -1));

    adjacencyMatrix(matrix, n);

    cout << "adjacency graph : " << endl;
    displayMatrix(matrix);

    return 0;
}
