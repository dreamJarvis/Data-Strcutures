#include <bits/stdc++.h>
using namespace std;

vector<int> findSubsequences(vector<int> arr){
    vector<int> result;
    result.push_back(-1);

    unordered_map<int, bool> visited;
    for(auto i:arr){
        if(visited.count(i)){
            if(i >= result.back())
                result.push_back(i);
            else{
                return vector<int>({-1});
            }
        }
        else visited[i] = true;
    }

    result.erase(result.begin());
    return result;
}

int main(){
    vector<int> arr({2, 1, 3, 1, 4, 1, 3});
    // vector<int> arr({1, 1, 1, 3});
    // vector<int> arr({3, 2, 2, 1, 1});
    // vector<int> arr({0, 0, 0, 1});

    for(auto i:findSubsequences(arr))
        cout << i << endl;
    cout << endl;

    return 0;
}
