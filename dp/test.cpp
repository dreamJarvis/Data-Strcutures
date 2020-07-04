#include <bits/stdc++.h>
using namespace std;

bool canPartitionKSubsets(vector<int>& nums, int k) {
    int n = nums.size(), sum = 0;

    int dp[(1<<16)+2];
    fill(dp, dp+(1<<16)+2, -1);

    dp[0] = 0;

    for (int i = 0; i < n; i++) sum += nums[i];
    if (sum % k) return false;
    int tar = sum/k;

    for (int mask = 0; mask < (1<<n); mask++) {
        if (dp[mask] == -1) continue;  // if current state is illegal, simply ignore it
        for (int i = 0; i < n; i++) {
            if (!(mask&(1<<i)) && dp[mask]+nums[i] <= tar){
                dp[mask|(1<<i)] = (dp[mask]+nums[i]) % tar;
                cout << (1 << i) << "\tdp[" << (mask) << "] --> " << dp[mask] << ",  dp["<< (mask|(1<<i)) << "] --> " << dp[mask|(1<<i)] << endl;
            }
        }
        cout << "\n\n";
    }

    return dp[(1<<n)-1] == 0;
}

// Driver function
int main(){
    // vector<int> nums({4, 3, 2, 3, 5, 2, 1});
    // int k = 4;
    // vector<int> nums({2,2,2,2,3,4,5});
    // int k = 4;
    // vector<int> nums({10,10,10,7,7,7,7,7,7,6,6,6});
    // int k = 3;
    vector<int> nums({5, 3, 2});
    int k = 2;

    cout << canPartitionKSubsets(nums, k) << endl;
    // canPartitionKSubsets(nums, k);

    return 0;
}
/*
[10,10,10,7,7,7,7,7,7,6,6,6]
3
*/
