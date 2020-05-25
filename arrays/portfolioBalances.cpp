#include <bits/stdc++.h>
using namespace std;

long maxValue(int n, vector<vector<int>> rounds){
    vector<long> result(n, 0);
    int maxProfix;

    for(int i = 0; i < rounds.size(); i++){
        int s = rounds[i][0];
        int e = rounds[i][1];
        long pr = rounds[i][2];

        for(int i = s; i <= e; i++){
            result[i] += pr;
        }
    }

    long maxProfit = 0;
    for(auto i:result)
        maxProfit = max(maxProfit, i);

    return maxProfit;
}

// Drvier function
int main(){
    int n = 5;
    vector<vector<int>> arr({
        {1, 2, 100},
        {2, 5, 100},
        {3, 4, 100}
    });

    cout << maxValue(n, arr) << endl;

    return 0;
}
