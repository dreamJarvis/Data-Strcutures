/*
    377. Combination Sum IV
    https://leetcode.com/problems/combination-sum-iv/
*/
#include <bits/stdc++.h>
using namespace std;

// unordered_map<string, int> dp;
vector<string> subsets;
int helper(vector<int>& nums, int target, int n, string str){
    // string key = to_string(n) + '_' + to_string(target);

    if(n < 0){
        if(target == 0){
            subsets.push_back(str);
            return 1;
        }
        return 0;
    }

    if(target == 0){
        subsets.push_back(str);
        return 1;
    }

    // if(dp.count(key))
    //     return dp[key];

    if(nums[n] > target)
        return helper(nums, target, n-1, str);
    else{
        return  (
            helper(nums, target-nums[n], n, str+to_string(nums[n])) +
            helper(nums, target, n-1, str)
        );
    }

    // return dp[key];
}

int combinationSum4(vector<int>& nums, int target) {
    int n = nums.size();
    // vector<bool> visited(nums.size(), false);
    int res = helper(nums, target, n-1, "");

    cout << "subsets : " << endl;
    for(auto &i:subsets)
        cout << i << endl;

    return res;
}

// Driver function
int main(){
    // vector<int> arr({1, 2, 3});
    // int target = 4;

    vector<int> arr({1, 2, 3});
    int target = 4;

    cout << combinationSum4(arr, target) << endl;

    return 0;
}
