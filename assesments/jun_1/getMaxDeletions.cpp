#include <bits/stdc++.h>
using namespace std;

int getMaxDeletions(string s){
    unordered_map<char, int> values;
    int sum = 0;
    for(auto i:s)   values[i]++;

    return (s.length() - (abs(values['U'] - values['D']) + abs(values['L'] - values['R'] )));
}

// Driver function
int main(){
    string str = "URDR";
    // string str = "LUDLL";

    cout << getMaxDeletions(str) << endl;

    return 0;
}
