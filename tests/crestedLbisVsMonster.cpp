// https://atcoder.jp/contests/abc153/tasks/abc153_e
#include <bits/stdc++.h>
using namespace std;

// find the least magic spent to kill the monster
int minTotalMagicPoints(int health, set<pair<int, int>> &totalCost, int minMagic, int sumAttact, int cost) {
    // base condition
    if(sumAttact >= health){
        return cost;
    }

    for(auto value:totalCost){
        // cout << value.first << endl;
        int temp = minTotalMagicPoints(health, totalCost, minMagic, sumAttact + value.first, cost + value.second);
        minMagic = min(temp, minMagic);
    }

    return minMagic;
}

// Driver function
int main(){
    int health, n;

    cin >> health >> n;

    set<pair<int, int>> totalCost;

    // unordered_map<int, int> storage;    // stores is the

    int magicPoints, attack;
    for(int i = 0; i < n; i++){
        cin >> attack >> magicPoints;
        totalCost.insert(make_pair(attack, magicPoints));
    }

    int minMagic = INT_MAX;
    int minMagicPoints = minTotalMagicPoints(health, totalCost, minMagic, 0, 0);

    cout << minMagicPoints << endl;

    return 0;
}
