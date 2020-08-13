// 0/1 knapsack problem using recursion
#include <bits/stdc++.h>
using namespace std;

// naive approach : recursive approach
int knapSack(int value[], int weight[], int capacity, int si, int n){
    // base case
    if(si == n || capacity < 0)    return 0;

    int ekBaariLena = INT_MIN;
    int ekBaariNhiLena = INT_MIN;

    if(weight[si] <= capacity)
        ekBaariLena = value[si] + knapSack(value, weight, capacity - weight[si], si+1, n);

    ekBaariNhiLena = knapSack(value, weight, capacity, si+1, n);

    return max(ekBaariLena, ekBaariNhiLena);
}

// ----------------------------------------------------------------------------------------------- //

// memoisation : top-down approach
int knapSackMemo(int value[], int weight[], int si, int capacity, int n, int dp[][9]){
    // base case: storing the values for all the base cases
    if(si == n){
        dp[si][capacity] = 0;
        return 0;
    }

    // if the value for that capacity at si'th index already exists in the dp, then return
    if(dp[si][capacity] != -1)  return dp[si][capacity];

    int ekBaariLena = INT_MIN;
    int ekBaariNhiLena = INT_MIN;

    // ek baari weight ko consider krenge , aor ek baari ni krenage
    if(weight[si] <= capacity)
        ekBaariLena = value[si] + knapSackMemo(value, weight, si+1, capacity - weight[si], n, dp);
    ekBaariNhiLena = knapSackMemo(value, weight, si+1, capacity, n, dp);

    // total values store kr denge dp[][] me
    dp[si][capacity] = max(ekBaariLena, ekBaariNhiLena);

    // ******** ab tk ka jo table fill hua ha dp ka ussko print kr dega ******** //
    // for(int i = 0; i < 5; i++){
    //     for(int j = 0; j < 9; j++)
    //         cout << dp[i][j] << "  ";
    //     cout << endl;
    // }
    //
    // cout << "**************************************************************" << endl;

    // return total value , ab tk ki weight ke liye
    return dp[si][capacity];
}

// ----------------------------------------------------------------------------------------------- //

// Tabulation method : bottom up
int knapSackTabulation(int value[], int weight[], int n, int capacity){
    int dp[n+1][capacity+1];

    // when the weight is 0, then none of the repective weights will be considered from the array
    for(int i = 0; i <= n; i++)
        dp[i][0] = 0;

    // when there are no weights in the array, then the total values will be zero for every weight
    for(int i = 0; i <= capacity; i++)
        dp[0][i] = 0;

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= capacity; j++){
            // jb tk capacity choti h ith index weight se, tb tk same column ke uper wale row ki value chepte rho
            if(weight[i-1] > j)     dp[i][j] = dp[i-1][j];

            // jb capacity jaya ya == h capacity ke , tb ith index weight ki value + remaining weight ki value ka total, aor same column ki upr wali ki value ka comparison
            // hm bs ye chk kr rhe h ki, abhi hme jo iss current weight ko consideration me leke total value mil raha h, kya wo , hme jo total value same capacity ke liye iss i'th index ko bina consideration me lete hua il raha tha , usse bda h ya nhi, jo bhi value bdi hogi whi total value hogi

            else                    dp[i][j] = max(dp[i-1][j], dp[i-1][j - weight[i-1]] + value[i-1]);
        }
    }

    return dp[n][capacity];
}

// Driver code
int main(){
    int val[] = {50,40,70,40};
	int wt[]= {5, 4, 6, 3};
	int W = 8;

	int n = sizeof(val)/sizeof(val[0]);

    // recursion
    cout<< "recursion :\t" << knapSack(val, wt, W, 0, n) << endl;

    // memoisation
    int dp[5][9];
    memset(dp, -1, sizeof(dp));
    cout << "Memoisation : \t" << knapSackMemo(val, wt, 0, W, n, dp) << endl;

    // tablulation
    cout << "Tabulation : \t" << knapSackTabulation(val, wt, n, W) << endl;

	return 0;
}
