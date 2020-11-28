/*
    https://practice.geeksforgeeks.org/problems/third-largest-element/0/?track=amazon-arrays&batchId=192#
*/
#include <iostream>
#include <climits>
using namespace std;

int thirdLargest(int arr[], int N){
    int a = INT_MIN, b = INT_MIN, c = INT_MIN;

    for(int i = 0; i < N; i++){
        if(a < arr[i]){
            c = b;
            b = a;
            a = arr[i];
        }
        else if(b < arr[i]){
            c = b;
            b = arr[i];
        }
        else if(c < arr[i]){
            c = arr[i];
        }
    }

    return c == INT_MIN ? -1 : c;
}

// Driver function
int main(){
    int arr[] = {2,4,1,3,5};
    int n = sizeof(arr)/sizeof(arr[0]);

    cout << thirdLargest(arr, n) << endl;

    return 0;
}
