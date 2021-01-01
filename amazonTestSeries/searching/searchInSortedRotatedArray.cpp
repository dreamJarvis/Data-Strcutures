/*
    9. Search in a Sorted and Rotated Array
    https://practice.geeksforgeeks.org/problems/search-in-a-rotated-array0959/0/?track=amazon-searching&batchId=192
*/
#include <bits/stdc++.h>
using namespace std;

// O(log(n))
int binarySearch(vector<int> &arr, int low, int high, int key){
    if(high < low)  return -1;

    int mid = (high+low)/2;

    if(key == arr[mid])
        return mid;

    if(key > arr[mid])
        return binarySearch(arr, mid+1, high, key);
    return binarySearch(arr, low, mid-1, key);
}

// finding pivot
int findPivot(vector<int> &arr, int low, int high){
    if(high < low)  return -1;
    if(high == low) return low;

    int mid = (high+low)/2;

    if(mid < high && arr[mid] > arr[mid+1])
        return mid;

    if(mid > low && arr[mid] < arr[mid-1])
        return (mid-1);

    if(arr[low] >= arr[mid])
        return findPivot(arr, low, mid-1);

    return findPivot(arr, mid+1, high);
}

int search(vector<int>& arr, int key) {
    int n = arr.size();
    int pivot = findPivot(arr, 0, n-1);

    // if there's no pivot, then simple binary search will do the work
    if (pivot == -1)
        return binarySearch(arr, 0, n - 1, key);

    // if the pivot is the key index
    if (arr[pivot] == key)
        return pivot;

    // else search on both side of the pivot
    // because arr[0] < arr[pivot+1]
    if (key >= arr[0])
        return binarySearch(arr, 0, pivot - 1, key);

    return binarySearch(arr, pivot + 1, n - 1, key);
}

// Driver function
int main(){
    vector<int> arr({5,6,7,8,9,10,1,2,3});
    int K = 2;
    // vector<int> arr({3, 1, 2});
    // int K = 1;
    // vector<int> arr({4,5,6,7,0,1,2});
    // int K = 0;
    // vector<int> arr({1});
    // int K = 0;
    // vector<int> arr({1, 3});
    // int K = 4;

    cout << search(arr, K) << endl;

    return 0;
}
