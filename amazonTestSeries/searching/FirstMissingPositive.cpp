/*
    leetcode : 41. First Missing Positive
    https://leetcode.com/problems/first-missing-positive/

    gfg : 11. Smallest Positive missing number
    https://practice.geeksforgeeks.org/problems/smallest-positive-missing-number3051/0/?track=amazon-searching&batchId=192

    reference :
        https://www.youtube.com/watch?v=-lfHWWMmXXM
*/
#include <bits/stdc++.h>
using namespace std;

// tc: O(n)
// sc: O(n)
// int firstMissingPositiveII(vector<int>& nums){
//     int n = nums.size();
//     int minPos = INT_MAX, maxPos = 1;
//
//     unordered_map<int, bool> visit;
//     for(int i = 0; i < n; i++){
//         if(nums[i] > 0){
//             minPos = min(minPos, nums[i]);
//             maxPos = max(maxPos, nums[i]);
//             visit[nums[i]] = true;
//         }
//     }
//
//     if(minPos > 1)
//         return 1;
//
//     for(int i = 1; i <= maxPos; i++){
//         if(!visit.count(i))
//             return i;
//     }
//
//     return maxPos+1;
// }

// tc : O(n)
// sc : O(1)
int firstMissingPositive(vector<int>& nums) {
    int n = nums.size();

    for(int i = 0; i < n; i++){
        while(nums[i] >= 1 && nums[i] <= n && nums[i] != nums[nums[i]-1]){
            swap(nums[i], nums[nums[i]-1 ]);
        }
    }

    for(int i = 0; i < n; i++){
        if(nums[i] != i+1)
            return i+1;
    }

    /* if we have reached till here, then it means
        all the nums exist's in array from 1 -> n,
        .'. the smallest possible number is n+1
    */
    return n+1;
}

// Driver function
int main(){
    // vector<int> arr({1, 2, 0});
    // vector<int> arr({7,8,9,11,12});
    vector<int> arr({3, 4, -1, 1});

    cout << firstMissingPositive(arr) << endl;
    // cout << firstMissingPositiveII(arr) << endl;

    return 0;
}
