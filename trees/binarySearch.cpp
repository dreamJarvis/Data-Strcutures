// Binary serach
#include <bits/stdc++.h>
using namespace std;

int binarySearch(vector<int> &arr, int start, int end, int k){
    if(start == end){
        return -1;
    }    

    int mid = start + (end - start)/2;

    if(arr[mid] == k)
        return mid;

    if(arr[mid] < k)
        return binarySearch(arr, mid+1, end, k);
    return binarySearch(arr, start, mid, k);
}

// Driver function
int main(){
    vector<int> arr({1, 2, 4, 5, 6, 7, 9, 10, 12});

    int k = 9;
    cout << binarySearch(arr, 0, arr.size(), k) << endl;

    return 0;
}