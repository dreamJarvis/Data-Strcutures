// leetcode 494. Target Sum
#include <bits/stdc++.h>
using namespace std;

// to find the no. of ways to achieve the target sum
// int count = 0;
int findTargetSumWays(vector<int>& nums, int S, int k, int d, int index) {
    // base condition
    if(index > nums.size())
        return 0;

    if(S - d == k)
        return 1;

    int sum=0, count = 0;
    for(int i = index; i < nums.size();i++){
        sum += arr[i];
        count = findTargetSumWays(nums, S, k, sum, i+1);
    }

    return count;
}

// Driver function
int main(){
    vector<int> arr({1, 1, 1, 1});
    int k = 3;
    int sum = 0;
    for(auto item:arr)
        sum+=item;

    cout << findTargetSumWays(arr, sum, k, 0, 0) << endl;

    return 0;
}
