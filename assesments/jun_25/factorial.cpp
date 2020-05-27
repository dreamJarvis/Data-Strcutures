#include <bits/stdc++.h>
using namespace std;

void pthFactor(long n, long p) {
    // int count =0;

    vector<int> res;
    while(n != 1){
        // cout << n << endl;
        if(n%2 == 0){
            n /= 2;
            // cout << n << endl;
            res.push_back(2);
        }
        else if(n%3 == 0){
            n /= 3;
            res.push_back(3);
        }
        else if(n%5 == 0){
            n /= 5;
            res.push_back(5);
        }
    }

    for(auto i:res)
        cout << i << " ";
    cout << endl;

    vector<int> tmp;
    tmp.push_back(1);
    tmp.push_back(res[0]);

    int s = res.size();
    int i = 1, j = 1;
    while(i < s){
        while(res[i-1] )
    }

    for(auto i:tmp)
        cout << i << " ";
    cout << endl;
}

// Driver function
int main(){
    int n = 20;
    int p = 3;

    pthFactor(n, p);

    return 0;
}
