// 85. Maximal Rectangle
#include <bits/stdc++.h>
using namespace std;

int maximalRectangle(vector<vector<char>>& matrix) {
    int row = matrix.size();
    int col = matrix[0].size();

    // dp table
    vector<vector<int>> dp(row, vector<int>(col, 0));
    int maxRect = 0;

    for(int i = 0; i < col; i++){
        dp[0][i] = matrix[0][i];
        maxRect = max(maxRect, matrix[0][i]);
    }

    for(int i = 0; i < row; i++){
        dp[i][0] = matrix[i][0];
        maxRect = max(maxRect, matrix[i][0]);
    }

    
}

// Driver function
int main(){

    return 0;
}
