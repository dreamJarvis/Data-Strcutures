#include <bits/stdc++.h>
using namespace std;

int maxXor(int lo, int hi, int k){
    vector<int> arr(hi-lo, 0);
    for(int i=lo; i <= hi; i++) arr.push_back(i);

    int maxable = -1;
    for(int i = 0; i < arr.size()-1; i++){
        for(int j = i+1; j < arr.size(); j++){
            int val = arr[i]^arr[j];
            if(val <= k){
                cout << val << endl;
                maxable = max(maxable, val);
            }
        }
    }

    return maxable;
}

// Driver function
int main(){
    int lo = 11, hi = 61;
    int k = 32;

    cout << maxXor(lo, hi, k) << endl;

    return 0;
}
