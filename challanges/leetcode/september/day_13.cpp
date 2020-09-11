/*
    152. Maximum Product Subarray
*/
#include <iostream>
#include <vector>
using namespace std;

// tc : O(N)
// sc : O(1)
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int abhiTkKaMax, abhiTkKaMin;
        int pichlaMax, pichlaMin;

        abhiTkKaMax = abhiTkKaMin = nums[0];
        pichlaMax = pichlaMin = nums[0];

        int ans = nums[0];
        for(int i = 1; i < n; i++){
            abhiTkKaMax = max(nums[i], max(pichlaMax*nums[i], pichlaMin*nums[i]));
            abhiTkKaMin = min(nums[i], min(pichlaMax*nums[i], pichlaMin*nums[i]));

            pichlaMax = abhiTkKaMax;
            pichlaMin = abhiTkKaMin;

            ans = max(ans, abhiTkKaMax);
        }

        return ans;
    }
};

// Driver function
int main(){
    // vector<int> arr({2, 3, -2, 4});
    // vector<int> arr({-2, 0, -1});
    // vector<int> arr({-2, 3, -4});
    vector<int> arr({-3, 0, 1, -2});
    // vector<int> arr({2, -5, -2, -4, 3});

    Solution s;
    cout << s.maxProduct(arr) << endl;

    return 0;
}
