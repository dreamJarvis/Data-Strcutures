/*
    https://leetcode.com/problems/partition-labels/
    763. Partition Labels
*/
#include <bits/stdc++.h>
using namespace std;

// tc : O(n)
class Solution {
public:
    vector<int> partitionLabels(string S) {
        unordered_map<char, int> range;
        for(int i = 0; i < S.length(); i++){
            range[S[i]] = i;
        }

        vector<int> part;
        part.push_back(abs(range[S[0]] - 0)+1);

        int si = 0;
        int ei = range[S[0]];

        for(int i = 0; i < S.length(); i++){
            // partially overlapping
            if(i < ei && range[S[i]] > ei){
                ei = range[S[i]];
                part[part.size()-1] = abs(ei - si)+1;
            }
            // not overlapping
            else if(i > ei){
                si = i;
                ei = range[S[i]];
                part.push_back(abs(ei - si)+1);
            }
        }

        return part;
    }
};

// Driver function
int main(){
    // string str = "ababcbacadefegdehijhklij";
    string str = "qiejxqfnqceocmy";

    Solution s;
    for(auto i:s.partitionLabels(str))
        cout << i << "  ";

    return 0;
}
/*
"qiejxqfnqceocmy"
*/
