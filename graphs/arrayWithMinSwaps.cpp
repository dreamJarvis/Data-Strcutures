// Minimum number of swaps required to sort an array
// gfg : https://www.geeksforgeeks.org/minimum-number-swaps-required-sort-array/
#include <bits/stdc++.h>
using namespace std;

int minimumSwaps(vector<int> arr, int n) {
    unordered_map<int, bool> visited;            // to detect cycle

    vector<int> temp(n+1, 0);
    for(int i=0; i < n; i++){
        temp[i+1] = arr[i];
    }

    int minSwaps = 0;
        for(int i = 1; i <= n; i++){
            int count = 0;
            if(temp[i] != i && !visited[i]){
                visited[i] = true;
                int j = i;
                // cout << i << "-->" << " ";
                while(j <= n && !visited[temp[j]]){
                    visited[temp[j]] = true;
                    count++;
                    // cout << " (" << temp[j] << ", " << count <<") -->";
                    j = temp[j];
                }

                // cout << "\n" << minSwaps << ", " << count << endl;
                minSwaps += count;
            }
            // cout << endl;
        }
    return minSwaps;
}


// Driver function
int main(){
    // vector<int> arr({0, 2, 3, 4, 1, 6, 5});
    // vector<int> arr({0, 2, 3, 4, 5, 6, 1});
    // vector<int> arr({1, 3, 5, 2, 4, 6, 7});
    vector<int> arr({4, 3, 1, 2});


    cout << minimumSwaps(arr, arr.size()) << endl;

    return 0;
}
/*
1 3 5 2 4 6 7
4 3 1 2
*/
