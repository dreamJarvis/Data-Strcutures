/*
    Boolean Parenthesization
    https://practice.geeksforgeeks.org/problems/boolean-parenthesization/0
*/
#include <iostream>
#include <unordered_map>
using namespace std;

int util(string str, int i, int j, bool isTrue, unordered_map<string, int> &dp){
    string key = to_string(i) + to_string(j) + to_string(isTrue);

    if(i > j)
        return 0;

    if(i == j){
        if(isTrue)  return (str[i] == 'T');
        else        return (str[i] == 'F');
    }

    if(dp.count(key))
        return dp[key];

    int count = 0;
    for(int k = i+1; k <= j-1; k+=2){
        int lt = util(str, i, k-1, true, dp);
        int rt = util(str, k+1, j, true, dp);
        int lf = util(str, i, k-1, false, dp);
        int rf = util(str, k+1, j, false, dp);

        if(str[k] == '&'){
            if(isTrue)
                count += lt*rt;
            else
                count += lt*rf + lf*rt + lf*rf;
        }
        else if(str[k] == '|'){
            if(isTrue)
                count += lt*rf + lf*rt + rt*lt;
            else
                count += lf*rf;
        }
        else if(str[k] == '^'){
            if(isTrue)
                count += lf*rt + lt*rf;
            else
                count += lf*rf + lt*rt;
        }
    }

    dp[key] = count%1003;
    return dp[key];
}

int ways(string exp){
    unordered_map<string, int> dp;
    int n = exp.length();
    return util(exp, 0, n-1, true, dp);
}

// Driver function
int main(){
    string exp = "T^T^T^F|F";

    cout << ways(exp) << endl;

    return 0;
}
