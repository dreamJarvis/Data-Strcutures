// to count all the palindromic substrings in the given strings
/*
    resources used :

    brute force O(n^3) : https://www.geeksforgeeks.org/generating-subarrays-using-recursion/

    memoisation O(n^2) : https://rusyasoft.github.io/algorithms,%20leetcode/2019/05/29/algorithms-longest-substring-palindrome/

    DP tabulation O(n^2) : https://www.geeksforgeeks.org/longest-palindrome-substring-set-1/

*/
#include <bits/stdc++.h>
using namespace std;

// bool isPalindrome(string str){
//     int l = 0;
//     int r = str.size()-1;
//
//     while(l <= r){
//         if(str[l] != str[r])
//             return false;
//
//         l++;
//         r--;
//     }
//
//     return true;
// }
//
// void substrCountUtil(string s, int start, int end){
//     if(end == s.size()){
//         return ;
//     }
//     else if(start > end){
//         substrCountUtil(s, 0, end+1);
//     }
//     else {
//         string str="";
//         for(int i = start; i <= end; i++)
//             str += s[i];
//
//         if(isPalindrome(str)){
//             cout << str << endl;
//             totalCount++;
//         }
//
//         substrCountUtil(s, start+1, end);
//     }
//
//     return ;
// }
//
// long substrCount(string s) {
//     substrCountUtil(s, 0, 0);
//     return totalCount;
// }

// // wrong result
// // memoisation technique
// // global variables
// unordered_map<string, bool> palindromeTable;
//
// bool isPalindrome(int si, int ei, string str){
//     string key = to_string(si) + to_string(ei);
//
//     if(palindromeTable[key]){
//         // cout << str.substr(si, ei) << endl;
//         // totalPalindromeCount++;
//         return true;
//     }
//
//     if(si == ei){
//         // totalPalindromeCount++;
//         // cout << str.substr(si, ei) << endl;
//         palindromeTable[key] = true;
//         return palindromeTable[key];
//     }
//
//     // the first charecters
//     char ch1 = str[si];
//     char ch2 = str[ei];
//
//     // if the charecters are adjacent
//     if(si == ei - 1){
//         return (ch1 == ch2 ? palindromeTable[key] : false);
//     }
//
//     if(ch1 == ch2 && isPalindrome(si+1, ei-1, str)){
//         // totalPalindromeCount++;
//         // cout << str.substr(si, ei) << endl;
//         palindromeTable[key] = true;
//         return palindromeTable[key];
//     }
//     else
//         return false;
// }
//
// long substrCount(string str){
//     if(str.size() <= 1)   return str.size();
//
//     int len = str.size();
//
//     for(int i = 0; i < len-1; i++)
//         for(int j = i; i < len; i++)
//             isPalindrome(i, j, str);
//
//     // to count all the palindromes
//     long totalPalindromeCount = 0;
//     for(auto i:palindromeTable)
//         if(i.second)
//             totalPalindromeCount++;
//
//
//     return totalPalindromeCount;
// }

// tabulation : O(n^2)
long substrCountDP(string str){
    int n = str.size();
    bool dp[n][n] = {false};
    long totalPalindromeCount = n;

    // all substrings of length 1 are palindrome
    for(int i = 0; i < n; i++)
        dp[i][i] = true;

    // checking palindromes for substrings of length 2
    for(int i = 0; i < n-1; i++){
        if(str[i] == str[i+1]){
            dp[i][i+1] = true;
            totalPalindromeCount++;
        }
    }


    for(int len = 3; len <= n; len++){
        for(int row = 0; row < n - len + 1; row++){
            int endIndex = row + len - 1;

            if(dp[row + 1][endIndex - 1] && str[row] == str[endIndex]){
                dp[row][endIndex] = true;
                totalPalindromeCount++;
            }
            else{
                dp[row][endIndex] = false;
            }
        }
    }

    return totalPalindromeCount;
}

// Driver function
int main(){
    // string str = "aaaa";
    string str = "abcbaba";

    cout << substrCountDP(str) << endl;

    return 0;
}
