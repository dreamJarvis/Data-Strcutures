// next greater element
#include <bits/stdc++.h>
using namespace std;

int NextGreaterElement(vector<int>& arr){
    int n = arr.size();
    int sum = 0;
    int i=0, j=0;

    if(n < 3)  return 0;

    // cout << "i" << endl;
    while(i < n){
        if(arr[i] !=0)
            break;
        i++;
        // cout << i << endl;
    }

    j = i;
    // cout << i << "\t" << n << endl;
    int abhiTkKaMax = 0;
    while(j < n){
        if(i == j){
            j++;
        }
        if(arr[j] >= arr[i]){
            // abhiTkKaMax = arr[j];
            cout << arr[i] << " -- " << arr[j] << "\t";

            int end = j-1;
            int start = i;

            cout << arr[start] << " -- " << arr[end] << "\t";
            while(end > start){
                int diff = abs(arr[start] - arr[end]);
                sum += diff;
                end--;
            }

            cout <<"s: "<< sum << endl;

            i = j;
        }
        j++;
    }

    cout << sum << endl;
    // cout << abhiTkKaMax << endl;
    // max dhundhna h
    // cout << i << "\t" << j << endl;
    if(i < n){
        i = i+1;
        j = i+1;

        cout << i << "\t" << j << endl;

        int maxValue = 0;
        int maxIndex = j;
        bool mila = false;
        while(i < n){
            if(mila)    break;
            if(j >= n && !mila){
                cout << arr[i] <<" : " << i << endl;
                i++;
                j = i+1;
                // maxValue = arr[i];
                // maxIndex = j;
                continue;
            }

            // cout << arr[i] <<" : " << i << endl;

            if(arr[j] >= arr[i]){
                maxValue = arr[j];
                maxIndex = j;
                mila = true;
            }

            j++;
        }

        // cout << "\n" << maxValue << "\t" << maxIndex << endl;

        // cout << i << endl;
        while(i < maxIndex && i < n){
            sum += abs(maxValue - arr[i]);
            i++;
            // cout << i << endl;
        }
    }


    // cout << sum << endl;
    return sum;
}

// Driver function
// 0,1,0,2,1,0,1,3,2,1,2,1
// [0,7,1,4,6]
int main(){
    // vector<int> arr({3, 2, 5, 1, 4, 6, 10, 4, 2, 5});
    // vector<int> arr({0,1,0,2,1,0,1,3,2,1,2,1});
    // vector<int> arr({5, 4, 1, 2});
    // vector<int> arr({1, 7, 5});
    vector<int> arr({0, 7, 1, 4, 6});


    cout << NextGreaterElement(arr) << endl;

    return 0;
}
