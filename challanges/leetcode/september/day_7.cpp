/*
    835. Image Overlap
    https://leetcode.com/problems/image-overlap/
*/
#include <bits/stdc++.h>
using namespace std;

// 2 pass method
// tc : 2*O(N^4)
class Solution {
public:
    int largestOverlap(vector<vector<int>>& A, vector<vector<int>>& B) {
        int n = A.size();

        if(n == 0)  return 0;
        if(n == 1){
            if(A[0][0] == 1 && B[0][0] == 1) return 1;
            else    return 0;
        }

        // here we are finding B in A (i.e. B is a subset of A)
        int count = 0;
        for(int i = 0; i < n; i++){
            for(int j =0; j < n; j++){
                int tempCount = 0;
                int row = i;
                int col = j;
                for(int k = 0; k < n; k++){
                    for(int l = 0; l < n; l++){
                        if(row + k < n && col + l < n){
                            if(B[row+k][col+l] && A[k][l]){
                                tempCount++;
                            }
                        }
                    }
                }
                count = max(count, tempCount);
            }
        }

        // here we are finding A in B (i.e. A is a subset of B)
        for(int i = 0; i < n; i++){
            for(int j =0; j < n; j++){
                int tempCount = 0;
                int row = i;
                int col = j;
                for(int k = 0; k < n; k++){
                    for(int l = 0; l < n; l++){
                        if(row + k < n && col + l < n){
                            if(A[row+k][col+l] && B[k][l]){
                                tempCount++;
                            }
                        }
                    }
                }
                count = max(count, tempCount);
            }
        }

        return count;
    }
};

// Driver function
int main(){
    // vector<vector<int>> A({
    //     {1, 1, 0},
    //     {0, 1, 0},
    //     {0, 1, 0},
    // });
    //
    // vector<vector<int>> B({
    //     {0, 0, 0},
    //     {0, 1, 1},
    //     {0, 1, 0},
    // });

    // vector<vector<int>> A({
    //     {1, 0},
    //     {1, 0}
    // });
    // vector<vector<int>> B({
    //     {1, 1},
    //     {1, 0}
    // });

    // vector<vector<int>> A({
    //     {1, 0},
    //     {0, 0}
    // });
    // vector<vector<int>> B({
    //     {0, 1},
    //     {1, 0}
    // });

    vector<vector<int>> A({
        {0, 0, 0, 0, 0},
        {0, 1, 0, 0, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 0, 1},
        {0, 1, 0, 0, 1}
    });

    vector<vector<int>> B({
        {1, 0, 1, 1, 1},
        {1, 1, 1, 1, 1},
        {1, 1, 1, 1, 1},
        {0, 1, 1, 1, 1},
        {1, 0, 1, 1, 1}
    });

    Solution s;
    cout << s.largestOverlap(A, B) << endl;

    return 0;
}
