// implementation of fractional knapsack
#include <bits/stdc++.h>
using namespace std;

// to find out max. profit using fractional knapsack
// tc : O(n^2)
double maxProfit(const vector<int> &val, const vector<int> &wt, int capacity){
    int n =  val.size();
    double profitByWt[n];

    for(int i = 0; i < n; i++){
        profitByWt[i] = (float) val[i]/wt[i];
    }

    // // shows the profit/weight ratio
    // for(int i = 0; i < n; i++)
    //     cout << profitByWt[i] << "  ";
    // cout << endl;

    float profit=0;
    for(int i = 0; i < n; i++){
        int temp = -1, index = 0;

        // this loop take out the largest ratio at every loop
        for(int j = 0; j < n; j++){
            if(temp < profitByWt[j]){
                temp = profitByWt[j];
                index = j;
            }
        }

        if(wt[index] < capacity){
            profit += val[index];
            capacity -= wt[index];
        }
        else if(wt[index] > capacity){
            profit += profitByWt[index] * (float)capacity;
            break;
        }

        profitByWt[index] = -1;
    }

    return profit;
}

// -------  gfg : https://www.geeksforgeeks.org/fractional-knapsack-problem/ ---- //
// tc : O(nlog(n))
struct Item{
    int value, weight;
    Item(int value, int weight) : value(value), weight(weight){}
};

// comparator function to sort item according to val/weight ratio
bool cmp(Item a, Item b){
    double r1 = (double)a.value / a.weight;
    double r2 = (double)b.value / b.weight;

    return r1 > r2;
}

// main greedy function to solve problems
double fractionalKnapsack(int W, Item arr[], int n){
    // sorting item on basis of ratio
    sort(arr, arr+n, cmp);

    int currWeight = 0;
    double finalValue = 0.0;

    for(int i = 0; i < n; i++){
        // if adding item won't overflow, add it completely
        if(currWeight + arr[i].weight <= W){
            currWeight += arr[i].weight;
            finalValue += arr[i].value;
        }
        else {
            int remain = W - currWeight;
            finalValue += arr[i].value * ((double)remain / arr[i].weight);
            break;
        }
    }

    return finalValue;
}

// Driver functions
int main(){
    // vector<int> val({10, 5, 15, 7, 6, 18, 3});
    // vector<int> wt ({2, 3, 5, 7, 1, 4, 1});
    // int capacity = 15;
    vector<int> val({60, 100, 120});
    vector<int> wt ({10, 20, 30});
    int capacity = 50;

    cout << maxProfit(val, wt, capacity) << endl;

    int W = 50;   //    Weight of knapsack
    Item arr[] = {{60, 10}, {100, 20}, {120, 30}};

    int n = sizeof(arr) / sizeof(arr[0]);

    cout << fractionalKnapsack(W, arr, n) << endl;

    return 0;
}
