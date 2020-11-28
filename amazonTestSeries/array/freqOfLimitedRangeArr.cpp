/*
    25. Frequencies of Limited Range Array Elements
    https://practice.geeksforgeeks.org/problems/frequency-of-array-elements-1587115620/0/?track=amazon-arrays&batchId=192#
*/
#include <bits/stdc++.h>
using namespace std;

void frequencycount(int *arr,int n){
    int freq[n+1];
    memset(freq, 0, sizeof(freq));

    for(int i = 0; i < n; i++)
        freq[arr[i]]++;

    for(int i = 1; i <= n; i++)
        arr[i-1] = freq[i];
}

// Driver function
int main(){
    int arr[] = {2, 3, 2, 3, 5};
    int n = sizeof(arr)/sizeof(arr[0]);

    frequencycount(arr, n);

    for(int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;

    return 0;
}
