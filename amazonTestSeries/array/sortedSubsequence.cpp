/*
    9. Sorted subsequence of size 3
    https://practice.geeksforgeeks.org/problems/sorted-subsequence-of-size-3/0/?track=amazon-arrays&batchId=192#
*/
#include <bits/stdc++.h>
using namespace std;

// tc : O(N)
// sc : O(N)
vector<int> find3Numbers(vector<int> arr, int N){
    /*
        a.t.q. left < i'th < right i.e. left should contain the smaller elements
        while right contain lerger elements
    */
    // storing all the smllest elements from left side
    vector<int> smaller(N, INT_MAX);
    smaller[0] = arr[0];
    for(int i = 1; i < N; i++){
        smaller[i] = min(arr[i], smaller[i-1]);
    }

    // storing all the greatest elements from the right side
    vector<int> larger(N, INT_MIN);
    larger[N-1] = arr[N-1];
    for(int i = N-2; i >= 0; i--){
        larger[i] = max(arr[i], larger[i+1]);
    }

    for(int i = 1; i < N-1; i++){
        if(arr[i] > smaller[i] && arr[i] < larger[i])
            return vector<int>({smaller[i], arr[i], larger[i]});
    }

    return vector<int>({});
}

// Driver function
int main(){
    // vector<int> arr({1,2,1,1,3});
    // vector<int> arr({1, 1, 3});
    vector<int> arr({58, 15, 44, 54, 36, 33, 93, 7, 18, 69, 30, 39, 60, 51});
    // vector<int> arr({33, 24, 92, 74, 100, 72, 72, 97, 54, 77, 95, 52, 11, 95, 29});

    // for(auto &i:find3Numbers(arr, arr.size()))
    //     cout << i << " ";
    // cout << endl;

    for(auto &i:find3NumbersII(arr, arr.size()))
        cout << i << " ";
    cout << endl;

    return 0;
}
