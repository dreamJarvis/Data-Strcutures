/*
    459. Repeated Substring Pattern
*/
#include <bits/stdc++.h>
using namespace std;

// brute force : O(n^2)
class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int n = s.length();
        string str;
        bool isTrue = false;
        for(int i = 1; i < n; i++){
            if(n%i==0){
                string str = s.substr(0, i);
                bool flag = true;

                for(int j = 0; j <= n-i; j+=i){
                    if(str != s.substr(j, i))
                        flag = false;
                }
                if(flag)    return flag;
            }
        }
        return isTrue;
    }
};

/* efficient Solution
tc : O(N)

go to --> https://leetcode.com/problems/repeated-substring-pattern/discuss/826135/C%2B%2B-O(N)-time-or-One-liner-without-KMP-Explained-or-Beats-99

or

Explanation
The key here is to double the string, that is, append the string to itself. In this way, the pattern would be duplicated.
On removing the first and the last characters, if there exists some pattern, we would still be able to find the original string somewhere in the middle, taking some characters from the first half and some from the second half.

For example,

Example 1.

s = "abab"
s+s = "abababab"

On removing the first and the last characters, we get:
(s+s).substr(1, 2*s.size()-2) = "bababa"

This new string, "bababa" still contains the original string, "abab".
Thus there exists some repeated pattern in the original string itself.


Example 2.

s = "aba"
s+s = "abaaba"

On removing the first and the last characters, we get:
(s+s).substr(1, 2*s.size()-2) = "baab"

This new string, "baab" does not contain the original string, "aba".
This implies that there does not exist any pattern in the original string itself.
*/
class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        return (
            (s+s).substr(1, 2*s.size()-2).find(s) != -1
        );
    }
};

// Driver function
int main(){
    // string str = "abab";
    string str = "aba";
    // string str = "abcabcabcabc";
    // string str = "abaababaab";
    // string str = "abac";

    Solution s;
    cout << s.repeatedSubstringPattern(str) << endl;

    return 0;
}
/*
"abaababaab"
*/
