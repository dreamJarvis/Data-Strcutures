/*
    46. Permutations
    https://leetcode.com/problems/permutations-ii/submissions/
*/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void helper(vector<int> nums, vector<vector<int>> &result, int pos){
        if(pos == nums.size()){
            result.push_back(nums);
            return ;
        }

        for(int i = pos; i < nums.size(); i++){
            /* here we are applying this knowing that our array is sorted
            and all the similar elements appear together, then we can vaoid all the
            repeated elements
            */
            if(i != pos && nums[i] == nums[pos])  continue;

            swap(nums[i], nums[pos]);
            helperII(nums, result, pos+1);

            /* here we are not swapping back in order to maitain the order
            of the array,
            i mean if your gonna mess up the order by swapping up,
            the why did you even sorted the array ?

            remember we swapped back in-order to find all the permutations, even the repeated ones, but if we dont care about the repeated ones then dont swap back
             */
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        helperII(nums, result, 0);
        return result;
    }
};

// Driver function
int main(){

    return 0;
}
