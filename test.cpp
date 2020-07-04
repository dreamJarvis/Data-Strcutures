#include <bits/stdc++.h>
using namespace std;


// Driver function
int main(){
    multiset<pair<int, int>> freq;

    freq.insert(make_pair(1, 0));
    freq.insert(make_pair(1, 3));
    freq.insert(make_pair(2, 1));
    freq.insert(make_pair(3, 2));

    // auto i = freq.begin();
    // cout << i->first << " --> " << i->second << endl;
    for(auto i:freq)
        cout << i.first << " --> " << i.second << endl;
    cout << endl;

    return 0;
}
