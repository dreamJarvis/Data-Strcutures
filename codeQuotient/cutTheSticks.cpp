#include <iostream>
using namespace std;

// // vector implemnetation
// #include <bits/stdc++.h>
// vector<int>& cutSticksI(vector<int> &arr, vector<int> &result){
//     int n = arr.size();
//     sort(arr.begin(), arr.end());
//
//     for(int i = 0; i < n; i++){
//         int count = 1;
//         for(int j = i+1; j < n; j++){
//             if(arr[i] != -1){
//                 if(arr[i] == arr[j]){
//                     count++;
//                     arr[j] = -1;
//                 }
//                 else if(arr[i] < arr[j]){
//                     count++;
//                 }
//             }
//         }
//
//         if(arr[i] != -1)
//             result.push_back(count);
//     }
//
//     return result;
// }


// *********************** CodeQuotient wala chutiyaap *******************//
void bubbleSort(int *arr, int lengths_size){
    if (lengths_size == 1)
        return;

    for (int i=0; i < lengths_size - 1; i++)
        if (arr[i] > arr[i+1]){
            int temp = arr[i];
            arr[i] = arr[i+1];
            arr[i+1] = temp;
        }

    bubbleSort(arr, lengths_size-1);
}

// pointer implemnetation
int *cutSticksII(int lengths_size, int *lengths, int *result_size){
    // sort(lengths, lengths+lengths_size);
    bubbleSort(lengths, lengths_size);

    // to find all the unique elements
    int uniqueElements = 1;
    for(int i = 1; i < lengths_size; i++){
        if(lengths[i] != lengths[i-1])
            uniqueElements++;
    }

    *result_size = uniqueElements;

    int index = 0;
    for(int i = 0; i < lengths_size; i++){
        int count = 1;
        for(int j = i+1; j < lengths_size; j++){
            if(lengths[i] != -1){
                if(lengths[i] == lengths[j]){
                    count++;
                    lengths[j] = -1;
                }
                else if(lengths[i] < lengths[j]){
                    count++;
                }
            }
        }

        if(lengths[i] != -1){
            lengths[index] = count;
            index++;
        }
    }

    return lengths;
}

// Driver function
int main(){


    int arr[] = {5, 4, 4, 2, 2, 8};
    int n = sizeof(arr)/sizeof(arr[0]);

    int result_size;
    int *a = cutSticksII(n, arr, &result_size);

    for(int i = 0; i < result_size; i++)
        cout << a[i] << endl;

    return 0;
}
