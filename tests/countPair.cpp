// Given an integer and a list of integers, count the no. of distinct valid pairs of integers (a,b) in the list for which a+k = b.
// ex : Two pairs of integers (a,b) and (c,d) are considered distinct if at least one element (a,b) does not belong to (c,d)

#include <bits/stdc++.h>
using namespace std;

int countPairs(vector<int> &arr, int k){
    int count = 0;
    unordered_map<int, bool> storage;

    for(auto val:arr)
        storage[val] = false;

    for(auto val:storage){
        if(storage.count(val.first + k) && storage[val.first + k] == false){
            count++;
            storage[val.first + k] = false;
        }
    }

    return count;
}

// Driver function
int main(){
    vector<int> arr({1,1,1,2,2,3});
    int k = 1;

    cout << countPairs(arr, k) << endl;

    return 0;
}
