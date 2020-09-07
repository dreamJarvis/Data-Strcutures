/*
    835. Image Overlap
    https://leetcode.com/problems/image-overlap/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int largestOverlap(vector<vector<int>>& A, vector<vector<int>>& B) {
        int n = A.size();

        if(n == 0)  return 0;
        if(n == 1){
            if(A[0][0] == 1 && B[0][0] == 1) return 1;
            else    return 0;
        }

        for(int i = 0; i < n; i++){
            
        }

        int count = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                int tempCount = 0;
                int row = i;
                int col = j;
                for(int k = 0; k < n; k++){
                    for(int l = 0; l < n; l++){
                        cout << "B -> r:" << (row + k) << ", c : "<< (col+l) << "\t"
                             << "A -> r:" << k << ", c : " << l << endl;

                        if(row+k < n && col+l<n && B[row+k][col+l] && A[k][l])
                            tempCount++;
                    }
                }
                cout << "\n" << tempCount;
                cout << "\n\n";
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
