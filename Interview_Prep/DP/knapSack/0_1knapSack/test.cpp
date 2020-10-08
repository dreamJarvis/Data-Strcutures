#include <bits/stdc++.h>
using namespace std;

int findTargetSumWays(vector<int>& nums, int S) {
    int n = nums.size();
    int sum = 0, countOfZeroes = 0;
    for(auto &i:nums)
        sum += i;

    if(S > sum) return 0;
    if((S+sum)%2 != 0)  return 0;

    int s = (S+sum)/2;

    int dp[n+1][s+1];
    memset(dp, 0, sizeof dp);

    for(int i = 0; i <= n; i++)
        dp[i][0] = 1;

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= s; j++){
            if(nums[i-1] && nums[i-1] <= j)
                dp[i][j] = dp[i-1][j-nums[i-1]] + dp[i-1][j];
            else
                dp[i][j] = dp[i-1][j];
        }
    }

    return (pow(2, countOfZeroes)*dp[n][s]);
}

// Driver function
int main(){
    vector<int> arr({1, 1, 1, 1, 1});
    int S = 3;
    cout << findTargetSumWays(arr, S) << endl;

    return 0;
}
