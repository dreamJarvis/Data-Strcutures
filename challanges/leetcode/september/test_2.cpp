#include <bits/stdc++.h>
using namespace std;

int main(){
    string str1, str2;
    cin >> str1 >> str2;

    int cost1, cost2;
    cin >> cost1 >> cost2;

    unordered_map<char, bool> freq1, freq2;

    for(auto i:str1){
        freq1[i]++;
    }

    for(auto i:str2){
        freq2[i]++;
    }

    int totalCost = 0;
    for(auto i:freq1){
        if(!freq2.count(i.first)){
            totalCost += cost1;
        }
    }

    for(auto i:freq2){
        if(!freq1.count(i.first)){
            totalCost += cost2;
        }
    }

    cout << totalCost << endl;

    return 0;
}
/*
    adghk adjhkl
    10 20
    50
*/
