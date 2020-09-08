#include <bits/stdc++.h>
using namespace std;

bool comp(const pair<int, int> &p1, const pair<int, int> &p2){
    // return (p1.first < p2.first);
    if(p1.first <= p2.first){
        if(p1.first == p2.first){
            if(p1.second > p2.second)   return true;
        }
        if(p1.first < p2.first) return true;
    }
    return false;
}

int main(){
    vector<pair<int,int>> range;
    range.push_back({1, 4});
    range.push_back({1, 2});
    range.push_back({1, 19});
    range.push_back({4, 7});

    // for(auto i:range)
    //     cout << i.first << "-" << i.second << endl;

    sort(range.begin(), range.end(), comp);

    return 0;
}
