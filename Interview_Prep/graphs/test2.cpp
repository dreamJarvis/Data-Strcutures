#include <bits/stdc++.h>
using namespace std;

void swap(int &a, int &b){
    int t = a;
    a = b;
    b = t;
    return;
}

// Driver function
int main(){
    vector<int> arr({1, 2, 3, 4, 5, 6, 7});
    for(int i = 0; i < arr.size()-2; i++){
        swap(arr[i], arr[i+1]);
    }

    for(auto i:arr)
        cout << i << ", " ;
    cout << endl;

    return 0;
}
