// 239. Sliding Window Maximum
#include <bits/stdc++.h>
using namespace std;

// tc : O(n-k)
// sc : O(k)
// vector<int> maxSlidingWindow(vector<int>& nums, int k) {
//     int n = nums.size();
//
//     vector<int> result;
//     set<pair<int, int>, greater<pair<int,int>>> s;
//
//     for(int i = 0; i < k; i++){
//         s.insert(make_pair(nums[i], i));
//     }
//
//     auto i = s.begin();
//     result.push_back(i->first);
//
//     for(int i = 0, j = k; j < n; i++, j++){
//         s.erase(make_pair(nums[i], i));
//         s.insert(make_pair(nums[j], j));
//         result.push_back(s.begin()->first);
//     }
//
//     return result;
// }

// using deque
vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    int n = nums.size();

    vector<int> result;
    deque<int> Qi;
    int i;

    int maxElement = INT_MIN, index=0;
    for(i = 0; i < k; i++){
        while(!Qi.empty() && nums[i] >= nums[Qi.back()])
            Qi.pop_back();
        Qi.push_back(i);
    }

    for(; i < n; i++){
        result.push_back(nums[Qi.front()]);

        while(!Qi.empty() && Qi.front() <= i-k)
            Qi.pop_front();

        while(!Qi.empty() && nums[i] >= nums[Qi.back()])
            Qi.pop_back();

        Qi.push_back(i);
    }

    result.push_back(nums[Qi.front()]);

    return result;
}

// Driver function
int main(){
    vector<int> arr({1,3,-1,-3,5,3,6,7});
    int k = 3;
    // vector<int> arr({-7,-8,7,5,7,1,6,0});
    // int k = 4;
    // vector<int> arr({1, -1});
    // int k = 1;
    // vector<int> arr({9,10,9,-7,-4,-8,2,-6});
    // int k = 5;

    for(auto i:maxSlidingWindow(arr, k))
        cout << i << " ";
    cout << endl;

    return 0;
}
/*
[-7,-8,7,5,7,1,6,0]
4

[9,10,9,-7,-4,-8,2,-6], [10, 10, 9, 2]
5
*/
