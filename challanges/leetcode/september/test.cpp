/*
    https://leetcode.com/problems/partition-labels/
    763. Partition Labels
*/
#include <bits/stdc++.h>
using namespace std;

string checkPath(vector<vector<int>> &arr, int i, int j,
                unordered_map<string, bool> &visited, string path)
{
    
}

vector<int> allPossiblePaths(vector<vector<int>> &arr){
    int n = arr.size();
    vector<string> paths;
    unordered_map<string, bool> visited;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(arr[i]){
                string res = checkPath(arr, i, j, visited, "");
                paths.push_back(res);
            }
        }
    }
}

// Driver function
int main(){
    vector<vector<int>> arr({
        {1, 1, 0},
        {0, 1, 0},
        {0, 1, 0},
    });

    // vector<vector<int>> B({
    //     {0, 0, 0},
    //     {0, 1, 1},
    //     {0, 1, 0},
    // });
    return 0;
}
