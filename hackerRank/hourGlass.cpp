#include <bits/stdc++.h>
using namespace std;

int hourglassSum(vector<vector<int>> arr, int r, int c, int rows, int cols){
    int r1 = arr[r][c-1] + arr[r][c] + arr[r][c+1];
    int r2 = arr[r+1][c];
    int r3 = arr[r+2][c-1] + arr[r+2][c] + arr[r+2][c+1];

    return (r1+r2+r3);
}

int hourglassSumUTIL(vector<vector<int>> arr){
    int rows = arr.size();
    int cols = arr[0].size();

    int maxSum = 0;
    for(int i = 0; i < rows-2; i++){
        for(int j = 1; j < cols-1; j++){
            maxSum = max(maxSum, hourglassSum(arr, i, j, rows, cols));
        }
    }

    return maxSum;
}

// Driver function
int main(){
    vector<vector<int>> matrix({
        {-9, -9, -9, 1, 1, 1},
        { 0, -9,  0, 4, 3, 2},
        {-9, -9, -9, 1, 2, 3},
        { 0,  0,  8, 6, 6, 0},
        { 0,  0,  0, -2, 0, 0},
        { 0,  0,  1,  2, 4, 0}
    });

    cout << hourglassSumUTIL(matrix) << endl;

    return 0;
}
