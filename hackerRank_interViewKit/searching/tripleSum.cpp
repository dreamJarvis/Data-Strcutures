// hackerRank Triple Sum
#include <bits/stdc++.h>
using namespace std;

long triplets(vector<int> a, vector<int> b, vector<int> c) {
    int lenA = a.size();
    int lenB = b.size();
    int lenC = c.size();

    int totalTriplets = 0;
    for(int i = 0; i < lenB-1; i++){
        // if(b[i] != b[i+1]){
        for(int j = 0; j < lenA; j++){
            if(b[i] >= a[j]){
                for(int k = 0; k < lenC; k++){
                    if(b[i] >= c[k]){
                        cout << b[i] << ", "<< a[j] << ", " << c[k]<< endl;
                        cout << i << ", " << j << ", " << k << "\n\n";
                        totalTriplets ++;
                    }
                }
            }
        }
        // }
    }

    return totalTriplets;
}

// Driver function
int main(){
    // vector<int> a({1, 3, 5});
    // vector<int> b({2, 3});
    // vector<int> c({1, 2, 3});

    vector<int> a({1, 4, 5});
    vector<int> b({2, 3, 3});
    vector<int> c({1, 2, 3});

    cout << triplets(a, b, c) << endl;

    return 0;
}
/*
1 4 5
2 3 3
1 2 3
*/
