/*
    60. Permutation Sequence
    https://leetcode.com/problems/permutation-sequence/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void helper(string str, int n, int pos, set<string> &result){
        if(pos == n)
            return;

        result.insert(str);

        for(int i = pos; i < n; i++){
            for(int j = n+pos-1; j < 2*n-1; j++){
                swap(str[i], str[j]);
                helper(str, n, pos+1, result);
                swap(str[i], str[j]);
            }
        }
    }

    vector<string> generateParenthesis(int n) {
        set<string> st;
        vector<string> result;
        string str = "";

        for(int i = 0; i < n; i++)  str += '(';
        for(int i = 0; i < n; i++)  str += ')';

        st.insert(str);

        if(n > 2)
            helper(str, n, 1, st);
        else if(n == 2){
            st.insert("()()");
        }

        for(auto i:st)
            result.push_back(i);
        return result;
    }
};

// Driver function
int main(){
    int n = 3;

    Solution s;
    for(auto i:s.generateParenthesis(n))
        cout << i << endl;

    return 0;
}
