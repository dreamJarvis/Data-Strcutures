// implementation of counting sort using hashmap
#include <bits/stdc++.h>
using namespace std;

// to sort the array using counting sort
void countingSort(vector<int> arr, int n){
    map<int, int> freqMap;
    for(auto i:arr)
        freqMap[i]++;


    // for every element of the map
    int i = 0;
    for(auto it:freqMap)
        for(int j = 0; j < it.second; j++)
            arr[i++] = it.first;

    for(auto it:arr)
        cout << it << " ";
    cout << endl;
}

// Driver function
int main(){
    vector<int> arr({1, 4, 3, 5, 1});

    countingSort(arr, arr.size());

    return 0;
}
