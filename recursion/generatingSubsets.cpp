#include <bits/stdc++.h>
using namespace std;

// Recursive function to print all possible sub-arrays for given array
// time complexity : O(n^2)
void generatingSubsets(int arr[], int n, int start, int end){
    // return if we have reached the end
    if(end == n){
        return ;
    }

    // increment the end point and start from 0
    else if(start > end){
        generatingSubsets(arr, n, 0, end+1);
    }

    // print the sub-array and increment the starting point
    else{
        cout << "[";
        for(int i = start; i < end; i++)
            cout << arr[i] << ", ";
        cout << arr[end] <<"]\n";

        generatingSubsets(arr, n, start+1, end);
    }
}


// Driver function
int main(){
    int arr[] = {1, 2};
    int n = sizeof(arr)/sizeof(arr[0]);

    generatingSubsets(arr, n, 0, 0);

    return 0;
}
