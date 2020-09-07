/*
    leetcode 867. Transpose Matrix
*/
#include <iostream>
#include <algorithm>
#include <climits>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& A) {
        int n = A.size();
        int m = A[0].size();

        if(n == m){
            for(int i = 0; i < n; i++){
            int row = i;
            int col = i;

                for(int j = row; j < n; j++){
                    swap(A[row][j], A[j][col]);
                }
            }
        }
        else {
            vector<vector<int>> matrix(m, vector<int>(n, 0));
            for(int i = 0; i < m; i++){
                for(int j = 0; j < n; j++)
                    matrix[i][j] = A[j][i];
            }

            return matrix;
        }

        return A;
    }
};
int main(){
    // vector<vector<int>> matrix({
    //     {1, 2, 3},
    //     {4, 5, 6},
    //     {7, 8, 9}
    // });
    vector<vector<int>> matrix({
        {1, 2, 3},
        {4, 5, 6}
    });

    Solution s;
    for(auto i:s.transpose(matrix)){
        for(auto j:i)
            cout << j << "  ";
        cout << endl;
    }

    return 0;
}
