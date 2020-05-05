#include <bits/stdc++.h>
using namespace std;

// Driver function
int main(){
    set<pair<int, int>> magic;

    int h, n, a, b;

    cin >> h >> n;

    int spell, mp;
    // pair<int, int> p;
    for(int i = 0; i < n; i++){
        cin >> spell >> mp;
        magic.insert(make_pair(mp, spell));
    }

    set<pair<int, int>>::iterator itr, itr2, itr3;
    pair<int, int> val1, val2;

    int minfinal = INT_MAX, sum = 0, minValue = 0, div = 0;

    for(itr = magic.begin(); itr != magic.end(); ++itr){
        val1 = *(itr);

        sum += val1.second;
        minValue += val1.first;
        div = (h/val1.second * val1.first) + (h%val1.second * val1.first);

        if(sum >= h){
            break;
        }

        cout << val1.first << " ";

        itr++;
        int tempSum = 0, minValueTemp = INT_MAX;
        for(itr2 = itr; itr2 != magic.end(); ++itr2){
            val2 = (*itr2);
            if(tempSum >= h){
                cout << minfinal << ", " << div << ", " << minValueTemp << endl;
                minfinal = min(div, min(minfinal, minValueTemp));
                break;
            }

            tempSum = sum + val2.second;
            minValueTemp = minValue + val2.first;
            cout << val2.first << " " << tempSum <<", mp : " << minValueTemp << endl ;
        }

        // minfinal = min(minfinal, minValueTemp);
        cout << minfinal << ", " << div << ", " << minValueTemp << endl;
        minfinal = min(div, min(minfinal, minValueTemp));

        cout << endl;
        itr--;
    }

    cout << "min: " << minfinal << endl;

    return 0;
}
