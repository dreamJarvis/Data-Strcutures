// chef price control
#include <bits/stdc++.h>
using namespace std;

// Driver function
int main(){
    int t;
    cin >> t;

    while(t--){
        int n, k;
        cin >> n >> k;

        int temp=0, totalSum=0, resultantSum=0;
        for(int i = 0; i < n; i++){
            cin >> temp;
            if(temp > k)
                resultantSum += (temp-k);
        }
        cout << resultantSum << endl;
    }
    return 0;
}
