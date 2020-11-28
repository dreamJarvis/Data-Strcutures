/*
    15. Product array puzzle
    https://practice.geeksforgeeks.org/problems/product-array-puzzle4525/0/?track=amazon-arrays&batchId=192#
*/
#include <bits/stdc++.h>
using namespace std;

#define lli long long int

vector<long long int> productExceptSelf(vector<long long int>& nums, int n) {
    if(n == 1)
        return 1;

    vector<lli> res(n);
    lli pr = nums[0];
    res[0] = pr;
    for(int i = 1; i < n; i++){
        res[i] = pr*nums[i];
        pr *= nums[i];
    }

    pr = nums[n-1];
    res[n-1] = res[n-2];
    for(int i = n-2; i > 0; i--){
        res[i] = res[i-1]*pr;
        pr *= nums[i];
    }
    res[0] = pr;

    return res;
}

int main(){
    // vector<long long> arr({10, 3, 5, 6, 2});
    vector<long long> arr({12, 0});

    for(auto &i:productExceptSelf(arr, arr.size()))
        cout << i << " ";
    cout << endl;

    return 0;
}
