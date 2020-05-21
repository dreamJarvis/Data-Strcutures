#include <bits/stdc++.h>
using namespace std;

// time complexity : O(n*m), m << n
// space complexity : O(1)
// void moveElement(int arr[], int n){
//     int i=0, j=1;
//     while(j != n && i != n){
//         if(arr[j] > 0){
//             int ptr_1 = i;
//             int ptr_2 = j;
//
//             while(ptr_1 != ptr_2){
//                 swap(arr[ptr_1], arr[ptr_2]);
//                 ptr_1++;
//             }
//             i++;
//             j++;
//         }
//         else if(arr[j] < 0)
//             j++;
//     }
//     // // print's array
//     // for(int i = 0; i < n; i++)
//     //     cout << arr[i] << endl;
// }

// time complexity : O(n+m)
// space complexity : O(m)
void moveElement(int arr[], int n){
    // int i=0, j=0;
    // vector<int> temp;
    // while(j != n){
    //     if(arr[j] < 0){
    //         temp.push_back(arr[j]);
    //         // cout << arr[j] << endl;
    //         j++;
    //     }
    //     else{
    //         swap(arr[i], arr[j]);
    //         i++;
    //         j++;
    //     }
    // }
    //
    // for(int k = i, j = 0; k < n, j < temp.size(); k++, j++)
    //     arr[k] = temp[j];


    int i=0, j=0;
    int temp[n];
  	int index = 0;
    while(j != n){
        if(arr[j] < 0){
          	temp[index] = arr[j];
          	index++;
            j++;
        }
        else{
            swap(arr[i], arr[j]);
            i++;
            j++;
        }
    }

    for(int k = i, j = 0; k < n, j <= index; k++, j++)
        arr[k] = temp[j];
}

// Driver function
int main(){
    int arr[] = {-6, 7, 13, 10, -8, 15, 5, -9, 2, -1};
    int n = sizeof(arr)/sizeof(arr[0]);

    moveElement(arr, n);

    return 0;
}
