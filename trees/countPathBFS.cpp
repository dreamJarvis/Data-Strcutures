// To count the total numbe of paths using BFS
#include <bits/stdc++.h>
using namespace std;

#define R 4
#define C 4

// Returns the no. of valid paths in the given matrix
int Maze(int matrix[R][C]){
    queue<pair<int, int>> q;

    // insert the starting point , (0, 0) in the queue
    q.push(make_pair(0, 0));

    // count the no. of posiible paths
    int count = 0;

    while(!q.empty()){
        pair<int, int> p = q.front();
        q.pop();

        // increment , when any of the queue componenets reach destination
        if(p.first == R-1 and p.second == C-1)
            count++;

        // if moving to the next row is valid 
        if(p.first + 1 < R and matrix[p.first+1][p.second] == 1)
            q.push(make_pair(p.first+1, p.second));

        // if moving to the next column is valid
        if(p.second + 1 < C and matrix[p.first][p.second+1] == 1)
            q.push(make_pair(p.first, p.second+1));
    }

    return count;
}

// Driver function
int main(){
    int maze[R][C] = {
                    { 1,  1, 1, 1},
                    { 0, -1, 1, 1},
                    {-1, 1, 1,  1},
                    { 1,  1, 1, 1}
                    };

    cout << Maze(maze) << endl;
    
    return 0;
}
