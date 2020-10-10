/*
    Maximize The Cut Segments
    https://practice.geeksforgeeks.org/problems/cutted-segments/0
    https://www.techiedelight.com/rot-cutting/
*/
#include <iostream>
#include <string>
#include <unordered_map>
#include <climits>
#include <cstring>
using namespace std;


// ======================================== Memo ===================================== //
// tc : O(n*L)
// sc : O(n*L)
unordered_map<string, int> dp;
int maxSegments(int *arr, int L, int n){
    string key = to_string(n) + '_' + to_string(L);
    if(n < 0){
        if(L==0)
            return 0;
        return INT_MIN;
    }

    if(L == 0)
        return 0;

    if(arr[n] > L)
        return maxSegments(arr, L, n-1);
    else{
        if(!dp.count(key)){
            dp[key] = max(
                    maxSegments(arr, L-arr[n], n) + 1,
                    maxSegments(arr, L, n-1)
                );
        }
    }

    return dp[key];
}

// ====================================== Top Down ==========================================//
// tc : O(n*L)
// sc : O(n*L)
int maxSegmentsTopDown(int *arr, int L, int n){
    int dp[n+1][L+1];
    memset(dp, 0, sizeof dp);

    for(int i = 0; i <= n; i++)
        dp[i][0] = 0;

    for(int i = 0; i <= L; i++)
        dp[0][i] = 0;

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= L; j++){
            if(j >= arr[i-1]){
                if((dp[i][j-arr[i-1]] > 0) || (j == arr[i-1])){
                    dp[i][j] = max(
                                dp[i][j-arr[i-1]]+1,
                                dp[i-1][j]
                            );
                }else{
                    dp[i][j] = max(
                                dp[i][j-arr[i-1]],
                                dp[i-1][j]
                            );
                }
            }
            else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }

    return dp[n][L];
}

// Driver function
int main(){
    int tc;
    cin >> tc;

    while(tc--){
        int l;
        cin >> l;

        int arr[3];
        for(int i = 0; i < 3; i++)
            cin >> arr[i];

        cout << maxSegments(arr, l, 2) << endl;
        // cout << maxSegmentsTopDown(arr, l, 3) << endl;
    }

    return 0;
}
