/*
    983. Minimum Cost For Tickets
    https://leetcode.com/problems/minimum-cost-for-tickets/
*/
#include <bits/stdc++.h>
using namespace std;

#define MAX 999999

int helper(vector<int>& days, vector<int>& costs, unordered_map<int, int> &range,
    int n, int m, int noOfDays){
    if(noOfDays >= days[days.size()-1]){
        return MAX;
    }

    if(m == costs.size()){
        return MAX;
        // return helper(days, costs, range, n, 0, noOfDays);
    }

    cout << noOfDays << endl;

    if(noOfDays > days[n]){
        return (days, costs, range, n+1, m, noOfDays);
    }
    else{
        int inc = costs[m] + helper(days, costs, range, n, m, noOfDays+range[m]);
        int exc = helper(days, costs, range, n, m+1, noOfDays);

        cout << "inc : " << inc << ", exc : " << exc << endl;

        return min(inc, exc);
    }
}

int mincostTickets(vector<int>& days, vector<int>& costs) {
    int n = days.size(), m = costs.size();
    unordered_map<int, int> range;

    range[0] = 1;
    range[1] = 7;
    range[2] = 30;

    return helper(days, costs, range, 0, 0, days[0]);
}

// Driver function
int main(){
    vector<int> days({1, 4, 6, 7, 8, 20});
    vector<int> costs({2, 7, 15});

    cout << mincostTickets(days, costs) << endl;

    return 0;
}
