// fractionl knapsack
#include <bits/stdc++.h>
using namespace std;

// Driver function
int main(){
    vector<int> arr({10, 30, 20, 40, 50});
    sort(arr.begin(), arr.begin()+3);

    for(auto i:arr)
        cout << i << "\t";
    cout << endl;
    // cout << arr[arr.size()/2] << endl;

    return 0;
}
