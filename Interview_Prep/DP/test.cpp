/*
    10. Regular Expression Matching
    https://leetcode.com/problems/regular-expression-matching/
*/
#include <bits/stdc++.h>
using namespace std;



// Driver function
int main(){
    // string str = "aasdfasdfasdfasdfas";
    // string p = "aasdf.*asdf.*asdf.*asdf.*s";

    // string str = "a";
    // string p = "ab*a";

    // string str = "aa";
    // string p = "a";

    string str = "aa";
    string p = "a*";

    // string str = "ab";
    // string p = ".*";

    // string str = "aab";
    // string p = "c*a*b";

    // string str = "mississippi";
    // string p = "mis*is*p*.";

    // string str = "mississippi";
    // string p = "mis*is*ip*.";

    // string str = "aaa";
    // string p = "ab*a*c*a";

    cout << isMatch(str, p) << endl;

    return 0;
}
/*
"mississippi"
"mis*is*ip*."

"a"
"ab*a"

"aaa"
"ab*a*c*a"

"aasdfasdfasdfasdfas"
"aasdf.*asdf.*asdf.*asdf.*s"
*/
