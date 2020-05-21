// leetcode 78. Subsets
#include <bits/stdc++.h>
using namespace std;

// recursive method
// time complexity : O(2^n)
// space complexity : O(2^n)
void subsetUTIL(vector<int> nums, vector<int> ans, vector<vector<int>>& result){
    if(nums.size() == 0){
        result.push_back(ans);
        return ;
    }

    int item = nums[0]

    nums.erase(nums.begin());

    subsetUTIL(nums, ans, result);
    ans.push_back(item);
    subsetUTIL(nums, ans, result);
}

vector<vector<int>> subsets(vector<int>& nums) {
    vector<vector<int>> result;
    vector<int> ans;
    subsetUTIL(nums, ans, result);
    return result;
}

// iterative method
/*
    Using [1, 2, 3] as an example, the iterative process is like:

    Initially, one empty subset [[]]
    1. Adding 1 to []: [[], [1]];
    2. Adding 2 to [] and [1]: [[], [1], [2], [1, 2]];
    3. Adding 3 to [], [1], [2] and [1, 2]: [[], [1], [2], [1, 2], [3], [1, 3], [2, 3], [1, 2, 3]].
*/
// time complexity : O(n^2)
// space complexity : O(n)
vector<vector<int>> subsets(vector<int>& nums) {
    vector<vector<int>> subs = {{}};
    for (int num : nums) {
        int n = subs.size();
        for (int i = 0; i < n; i++) {
            subs.push_back(subs[i]);
            subs.back().push_back(num);
        }
    }
    return subs;
}

// Driver function
int main(){
    vector<int> arr({1, 2, 3});

    vector<vector<int>> result = subsets(arr);
    for(auto i:result){
        for(auto j:i)
            cout << j << " ";
        cout << endl;
    }

    return 0;
}
