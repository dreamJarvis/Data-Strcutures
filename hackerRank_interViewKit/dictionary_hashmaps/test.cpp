#include <bits/stdc++.h>
using namespace std;

int lcs(string a, string b, int m, int n){
    if(n == 0 || m == 0)    return 0;

    if(a[m-1] == b[n-1])
        return (lcs(a, b, m-1, n-1) + 1);
    else
        return max(lcs(a, b, m-1, n), lcs(a, b, m, n-1));
}

int lcsUtil(string a, string b, int m, int n, unordered_map<string, int> &memo){
    string key = to_string(m) + '_' + to_string(n);

    if(n==0 || m==0)    return 0;

    if(memo.count(key))
        return memo[key];

    if(a[m-1] == b[n-1]){
        memo[key] = lcsUtil(a, b, n-1, m-1, memo) + 1;
        return memo[key];
    }

    memo[key] = max(lcsUtil(a, b, m-1, n, memo), lcsUtil(a, b, m, n-1, memo));
    return memo[key];
}

int lcsMemo(string a, string b, int m, int n){
    unordered_map<string, int> memo;
    return lcsUtil(a, b, m, n, memo);
}

int lcsDP(string a, string b, int m, int n){
    vector<vector<int>> dp(m+1, vector<int>(n+1, 0));

    for(int row = 0; row < m; row++)
        dp[row][0] = 0;

    for(int col = 0; col < n; col++)
        dp[0][col] = 0;

    for(int row = 1; row <= m; row++){
        for(int col = 1; col <= n; col++){
            if(a[row-1] == b[col-1]){
                dp[row][col] = 1 + dp[row-1][col-1];
            }
            else
                dp[row][col] = max(dp[row-1][col], dp[row][col-1]);
        }
    }

    return dp[n][n];
}

// Driver function
int main(){
    string s1 = "ABCD";
    string s2 = "ABDC";
    // string s1 = "HARRY";
    // string s2 = "SALLY";
    // string s1 = "ABCDEF";
    // string s2 = "FBDAMN";
    // string s1 = "AA";
    // string s2 = "BB";

    int n = s1.size();
    int m = s2.size();
    // cout << lcs(s1, s2, n, m) << endl;
    cout << lcsMemo(s1, s2, n, m) << endl;
    cout << lcsDP(s1, s2, n, m) << endl;

    return 0;
}
