/*
    377. Combination Sum IV
    https://leetcode.com/problems/combination-sum-iv/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void helper(vector<int> &nums, int target, int &count,
                unordered_map<int, list<string>> &map1, unordered_map<string> &map2,
                string index
    ){
        if(target < 0)  return ;

        if(target == 0){
            count++;
            return;
        }

        string key, temp;
        for(int i = 0; i < nums.size(); i++){
            int sum = target-nums[i];
            temp = index + to_string(i);
            if( map1.count(sum) &&
                !map2.count(index + map1[sum]) &&
                !map2.count(map1[sum] + index))
            {
                
                continue;
            }
            helper(nums, target-nums[i], count);
        }
    }
    int combinationSum4(vector<int>& nums, int target) {
        int count = 0;
        unordered_map<int, list<string>> map1;
        unordered_map<strign> map2;
        helper(nums, target, count, map1, map2, "");
        return count;
    }
};

// Driver function
int main(){
    // vector<int> arr({1, 2, 3});
    // int target = 4;
    vector<int> arr({4, 2, 1});
    int target = 321;

    Solution s;
    cout << s.combinationSum4(arr, target) << endl;

    return 0;
}
