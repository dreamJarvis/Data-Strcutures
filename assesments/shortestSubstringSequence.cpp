#include <bits/stdc++.h>
using namespace std;

// // tc : O(nlog(n))
// string smallestString(vector<string> substring){
//     vector<string> result;
//
// }

bool comp(const string &a, const string &b){
    return (a+b < b+a);
}
string smallestString(vector<string> substring){
    string result;
    sort(substring.begin(), substring.end(), comp);
    for(auto i:substring)
        result += i;

    return result;
}

// Driver function
int main(){
    // vector<string> arr({"a", "bd", "ac", "cd"});
    vector<string> arr({"c", "cc", "cca", "cccb"});
    // vector<string> arr({"a", "bc", "ad"});

    cout << smallestString(arr) << endl;

    return 0;
}

/*
// auto comp = [](const string &a, const string &b){
//     return (a+b < b+a);
// };
*/
