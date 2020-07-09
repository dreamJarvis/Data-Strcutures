// implementation of fractional knapsack
#include <bits/stdc++.h>
using namespace std;

// to find out max. profit using fractional knapsack
int maxProfit(const vector<int> &val, const vector<int> &wt, int capacity){
    int n =  val.size();
    float profitByWt[n];

    for(int i = 0; i < n; i++){
        profitByWt[i] = (float) val[i]/wt[i];
    }

    float profit=0;
    for(int i = 0; i < n; i++){
        int temp = 0, index = 0;
        for(int j = 0; j < n; j++){
            if(temp > profitByWt[j]){
                temp = profitByWt[j];
                index = j;
            }
        }

        if(temp > 0){
            if(wt[index] < capacity){
                profit += val[index];
                capacity -= wt[index];
            }
            else if(capacity > 0){
                profit += profitByWt[index] * (float)(wt[index] - capacity);
                capacity -= wt[index] - capacity;
            }
        }

        profitByWt[index] = -1;
    }

    return profit;
}

// Driver functions
int main(){
    vector<int> val({10, 5, 15, 7, 6, 18, 3});
    vector<int> wt ({2, 3, 5, 7, 1, 4, 1});
    int capacity = 15;

    cout << maxProfit(val, wt, capacity) << endl;

    return 0;
}
