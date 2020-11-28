/*
    https://practice.geeksforgeeks.org/problems/find-duplicates-in-an-array/0/?track=amazon-arrays&batchId=192
    10. Find duplicates in an array
*/
#include <bits/stdc++.h>
using namespace std;

vector<int> duplicates(int arr[], int n){
    int freq[n];
    memset(freq, 0, sizeof(freq));

    for(int i = 0; i < n; i++){
        freq[arr[i]]++;
    }

    vector<int> res;
    for(int i = 0; i < n; i++){
        if(freq[i] > 1)
            res.push_back(i);
    }

    return res.size() != 0 ? res : vector<int>({-1});
}

// Driver function
int main(){
    // int arr[] = {2,3,1,2,3};
    int arr[] = {0,3,1,2};
    int n = sizeof(arr)/sizeof(arr[0]);

    for(auto &i:duplicates(arr, n))
        cout << i << " ";
    cout << endl;

    return 0;
}
