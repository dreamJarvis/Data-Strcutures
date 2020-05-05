#include <bits/stdc++.h>
using namespace std;

// error: double free or corruption(out) ??
int minimumCost(vector<int> heights, vector<int> cost, int si, int n){
    // base condition ??
    if(si > n)    return 0;

    // if(flag) return 0;

    if(si >= 0 || si <= n){
        heights[si] += 1;
    }

    int left = 0, right = 0;
    for(int i = 0; i < n; i++){
        if(heights[i] == heights[i+1]){
            left = minimumCost(heights, cost, i, n) + cost[i];
            right = minimumCost(heights, cost, i+1, n) + cost[i+1];
        }
    }

    // flag = true;

    return min(left, right);
}

// Driver function
int main(){
    vector<int> heights({2, 1, 1, 3, 4, 4});
    vector<int> cost({3, 3, 5, 3, 10, 7});

    cout << minimumCost(heights, cost, -1, heights.size()) << endl;

    return 0;
}
