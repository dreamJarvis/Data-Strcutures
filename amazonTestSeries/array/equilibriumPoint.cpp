/*
    13. Equilibrium Point
    https://practice.geeksforgeeks.org/problems/equilibrium-point-1587115620/0/?track=amazon-arrays&batchId=192
*/
#include <bits/stdc++.h>
using namespace std;

int equilibriumPoint(long long a[], int n) {
    long long leftSum[n] = {0};
    // memset(leftSum, 0, sizeof(leftSum));
    leftSum[0] = a[0];
    for(int i = 1; i < n; i++)
        leftSum[i] += (leftSum[i-1] + a[i]);

    long long rightSum[n] = {0};
    // memset(rightSum, 0, sizeof(rightSum));
    rightSum[n-1] = a[n-1];
    for(int i = n-2; i >= 0; i--)
        rightSum[i] += (rightSum[i+1]+a[i]);

    // for(int i = 0; i < n; i++)
    //     cout << leftSum[i] << " ";
    // cout << endl;
    //
    // for(int i = 0; i < n; i++)
    //     cout << rightSum[i] << " ";
    // cout << endl;

    for(int i = 0; i < n; i++)
        if(leftSum[i] == rightSum[i])
            return (i+1);

    return -1;
}

// Driver function
int main(){
    long long arr[] = {1, 3, 5, 2, 2};
    int n = sizeof(arr)/sizeof(arr[0]);

    // long long arr[] = {1};
    // int n = sizeof(arr)/sizeof(arr[0]);

    cout << equilibriumPoint(arr, n) << endl;

    return 0;
}
