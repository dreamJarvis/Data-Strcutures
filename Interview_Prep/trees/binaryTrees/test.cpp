#include <bits/stdc++.h>
using namespace std;

int ArrayChallenge(int arr[], int arrLength) {
  // unordered_map<int, int> map;
  // unordered_map<int, bool> visited;
  // for(int i = 0; i < arrLength; i++){
  //   if(i+1 != arr[i]){
  //     map[i+1] = arr[i];
  //   }
  // }
  //
  // int swaps = 0;
  // for(int i = 0; i < arrLength; i++){
  //     int len=0;
  //     int val = arr[i]-1;
  //     int index = i;
  //     // cout << "v : " << val << endl;
  //     if(i+1  != arr[i]){
  //         while(!visited.count(val)){
  //             visited[val] = true;
  //           visited[index] = true;
  //           index = val;
  //           val = arr[arr[val]-1]-1;
  //           // cout << "val : " << val << endl;
  //           len++;
  //         }
  //         // cout << len << endl;
  //     }
  //
  //     if(len)
  //         swaps += len;
  // }
  //
  // return swaps;
  unordered_map<int, int> map;
  unordered_map<int, bool> visited;
  for(int i = 0; i < arrLength; i++){
    if(i+1 != arr[i]){
      map[i+1] = arr[i];
    }
  }

  int swaps = 0;
  for(int i = 0; i < arrLength; i++){
    int len = 0;
    int val = arr[i]-1;
    int index = i;

    if(i+1 != arr[i]){
      while(!visited.count(val)){
        visited[index] = true;
        visited[val] = true;

        index = val;
        val = arr[arr[val]-1]-1;
        len++;
      }
    }

    if(len) swaps += len;
  }

  return swaps;
}

int main(void) {
    // int A[] = {1, 3, 2};
    // int A[] = {3,1,2};
    int A[] = {1,3,4,2};
    int arrLength = sizeof(A) / sizeof(*A);
    cout << ArrayChallenge(A, arrLength);
    return 0;
}
