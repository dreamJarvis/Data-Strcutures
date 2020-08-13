#include <bits/stdc++.h>
using namespace std;

bool compare(vector<int> &a, vector<int> &b){
    if(a[1] == b[1])
        return (a[0] < b[0]);
    return (a[1] > b[1]);
}

vector<vector<int>> groupSort(vector<int> arr) {
    int n = arr.size();
    unordered_map<int, int> st;

    for(auto i:arr){
        if(st.count(i)){
            st[i]++;
        }
        else
            st[i] = 1;
    }

    vector<vector<int>> freq;

    for(auto i:st){
        freq.push_back(vector<int>({i.first, i.second}));
    }

    sort(freq.begin(), freq.end(), compare);

    return freq;
}

// Driver function
int main(){
    vector<int> arr({3, 3, 1, 2, 2, 2, 1, 4, 5, 5, 5});

    for(auto i:groupSort(arr))
        cout << i[0] << " -- >" << i[1] << endl;

    return 0;
}
