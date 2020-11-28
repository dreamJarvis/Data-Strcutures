/*
    7. Remove duplicates in small prime array
    https://practice.geeksforgeeks.org/problems/remove-duplicates-in-small-prime-array/0/?track=amazon-arrays&batchId=192#
*/
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

vector<int> removeDuplicate(vector<int>& arr, int n){
    unordered_map<int, bool> visited;
    vector<int> res;

    for(int i = 0; i < n; i++){
        if(!visited[arr[i]]){
            res.push_back(arr[i]);
            visited[arr[i]] = true;
        }
    }

    return res;
}

// Driver function
int main(){
    vector<int> arr({2,2,3,3,7,5});

    for(auto &i:removeDuplicate(arr, arr.size()))
        cout << i << " ";
    cout << endl;

    return 0;
}
