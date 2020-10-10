/*
    322. Coin Change
    https://leetcode.com/problems/coin-change/
*/
#include <bits/stdc++.h>
using namespace std;

// // =============================== Memo ============================ //
// unordered_map<string, int> dp;
// int util(vector<int> &arr, int amount, int n){
//     string key = to_string(amount+999999) + '_' + to_string(n);
//
//     if(amount == 0){
//         return 0;
//     }
//
//     if(n < 0){
//         if(amount == 0){
//             return 0;
//         }
//         return 999999;
//     }
//
//     if(arr[n] > amount)
//         return util(arr, amount, n-1);
//     else{
//         if(!dp.count(key)){
//             dp[key]  = min(
//                         (util(arr, amount-arr[n], n) + 1),
//                         util(arr, amount, n-1)
//                     );
//         }
//     }
//
//     return dp[key];
// }
//
// int coinChange(vector<int>& coins, int amount) {
//     int ans = util(coins, amount, coins.size()-1);
//     return ans == 999999 ? -1 : ans;
// }
//
// int coinChangeDP(vector<int>& coins, int amount) {
//     int n = coins.size();
//     vector<vector<int>> dp(n+1, vector<int>(amount+1, 999999));
//
//     for(int i = 0; i <= n; i++)
//         dp[i][0] = 0;
//
//     for(int i = 1; i <= n; i++){
//         for(int j = 1; j <= amount; j++){
//             if(coins[i-1] <= j){
//                 if((j == coins[i-1]) || (dp[i][j-coins[i-1]] > 0)){
//                     dp[i][j] = min(
//                         1 + dp[i][j-coins[i-1]],
//                         dp[i-1][j]
//                     );
//                 }
//                 else{
//                     dp[i][j] = min(
//                         dp[i][j-coins[i-1]],
//                         dp[i-1][j]
//                     );
//                 }
//             }
//             else
//                 dp[i][j] = dp[i-1][j];
//         }
//     }
//
//     return dp[n][amount] == 999999 ? -1 : dp[n][amount];
// }

// ========================= bottom up approach ============================ //
int coinChangeDPII(vector<int>& coins, int amount) {
    int dp[amount+1];
    for(int i = 0; i <= amount; i++)
        dp[i] = amount+1;

    dp[0] = 0;
    for(int i = 1; i <=amount; i++){
        for(auto &coin:coins)
            if(i-coin >= 0)
                dp[i] = min(dp[i], dp[i-coin]+1);
    }

    return (dp[amount] > amount ? -1 : dp[amount]);
}

// Driver function
int main(){
    vector<int> arr({1, 2, 5});
    int amount = 11;

    // vector<int> arr({2});
    // int amount = 3;

    // vector<int> arr({1});
    // int amount = 1;

    // vector<int> arr({1});
    // int amount = 0;

    cout << coinChange(arr, amount) << endl;
    // cout << coinChangeDP(arr, amount) << endl;
    // cout << coinChangeDPII(arr, amount) << endl;

    return 0;
}
