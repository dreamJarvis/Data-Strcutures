/*
    gfg :
        https://leetcode.com/problems/maximum-subarray/
        53. Maximum Subarray
*/
#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll arrange(ll arr[], int n){
    for(int i = 0; i < n; i++){
        arr[i] += (arr[arr[i]]%n)*n;
    }

    for(int i = 0; i < n; i++)
        arr[i] /= n;
}

int main(){
    ll arr[] = {1, 0};
    // ll arr[] = {4, 0, 2, 1, 3};
    int n = sizeof(arr)/sizeof(arr[0]);

    arrange(arr, n);

    for(int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;

    return 0;
}
