/*
    Shortest distance between two cells in a matrix or grid
    https://www.geeksforgeeks.org/shortest-distance-two-cells-matrix-grid/
*/
#include<bits/stdc++.h>
using namespace std;

bool isValid(int r, int c, int R, int C){
    if(r >= 0 && c >= 0 && r < R && c < C)  return true;
    return false;
}

int shortestPath(vector<vector<char>> &arr, char d){
    int n = arr.size();
    int m = arr[0].size();
    char dest = 'd';
    char obs = '0';
    int sr = 0, sc = 3;

    set<pair<int, int>> visited;
    queue<int> rows;
    queue<int> cols;

    int rDir[] = { 0, 1, 0, -1 };
    int cDir[] = { 1, 0, -1, 0 };

    int r = 0,  c = m-1;

    rows.push(r);
    cols.push(c);

    // agr queue's empty ho gye , mtlb destination nhi mila
    while(!rows.empty() && !cols.empty()){
        int tempRow = rows.front();
        int tempCol = cols.front();

        rows.pop();
        cols.pop();
        // cout << tempRow << ", " << tempCol << endl;

        if(isValid(tempRow, tempCol, n, m)){
            if(arr[tempRow][tempCol] == dest){
                return (abs(abs(tempRow) - abs(sr)) + abs(abs(tempCol) - abs(sc)));
            }
        }

        for(int i = 0; i < 4; i++){
            r = tempRow + rDir[i];
            c = tempCol + cDir[i];

            if(isValid(r, c, n, m) && (visited.find({r, c}) == visited.end()) && arr[r][c] != obs){
                if(arr[r][c] == dest){
                    return (abs(abs(r) - abs(sr)) + abs(abs(c) - abs(sc)));
                }

                rows.push(r);
                cols.push(c);

                visited.insert({r, c});
            }
        }
    }

    return -1;
}

// Driver function
int main(){
    vector<vector<char>> arr{
        { '0', '*', '0', 's' },
        { '*', '0', '*', '*' },
        { '0', '*', '*', '*' },
        { 'd', '*', '*', '*' }
    };

    cout << shortestPath(arr, 'd') << endl;

    return 0;
}
