// implementation of counting sort
#include <bits/stdc++.h>
using namespace std;

#define M 200          // define the maximum limit of the digit (can defer according to the question)

// soring using counting sort
// time complexity : O(n+k)
// space complexity : O(n+k)
vector<int> countSort(vector<int> &arr){
    vector<int> temp(M, 0);

    for(auto i:arr)
        temp[i]++;

    int prev = 0;
    for(int i = 0; i < M; i++){
        temp[i] += prev;
        prev = temp[i];
    }

    for(int i = M-1; i >=0; i--){
        temp[i] = temp[i-1];
    }

    vector<int> result(arr.size(), 0);
    for(auto i:arr){
        result[temp[i]] = i;
        temp[i] += 1;
    }

    return result;
}

// Driver function
int main(){
    vector<int> arr({1, 4, 1, 2, 7, 5, 2});

    for(auto i:countSort(arr))
        cout << i << "\t";
    cout << "\n\n";

    return 0;
}
