/*
    leetcode 77. Combinations
    https://leetcode.com/problems/combinations/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void helper(vector<int> arr, vector<int> list, int pos, int k,
        vector<vector<int>> &result)
    {
        if(list.size() == k){
            result.push_back(list);
            return;
        }

        for(int i = pos; i < arr.size(); i++){
            int tp = arr[i];

            list.push_back(tp);
            helper(arr, list, pos+=1, k, result);
            list.pop_back();
        }
    }

    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> result;
        vector<int> arr(n);
        for(int i = 0; i < n; i++)
            arr[i] = i+1;

        helper(arr, vector<int>(), 0, k, result);

        return result;
    }
};

// Driver function
int main(){
    int n = 4, k = 2;

    Solution s;
    for(auto i:s.combine(n, k)){
        for(auto j:i)
            cout << j << " ";
        cout << endl;
    }

    return 0;
}
