#include <bits/stdc++.h>
using namespace std;

vector<int> permutationEq(vector<int> &p){
    set<pair<int, int>> st;

    for(int i = 0; i < p.size(); i++){
        st.insert(make_pair( p[p[(p[i]-1)]-1], p[i] ) );
    }

    vector<int> result;
    for(auto value:st){
        result.push_back(value.second);
    }

    return result;
}

// Driver function
int main(){
    // vector<int> arr({2, 3, 1});
    vector<int> arr({4, 3, 5, 1, 2});

    for(auto value:permutationEq(arr))
        cout << value << " ";
    return 0;
}
