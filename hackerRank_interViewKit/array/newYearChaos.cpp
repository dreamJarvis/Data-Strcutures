#include <bits/stdc++.h>
using namespace std;

// void minimumBribes(vector<int> q) {
    // int n = q.size();
    // int totalNoOfBribes = 0;
//
//     int freq[n+1] = {0};
//     for(int i = 0; i < n; i++){
//         int j = 0;
//         while(j < n-1){
//             if(q[j] > q[j+1]){
//                 freq[q[j]]++;
//
//                 // cout << q[j] << " --> " << freq[j] << endl;
//
//                 if(freq[q[j]] > 2){
//                     cout << "Too chaotic" << endl;
//                     return;
//                 }
//
//                 swap(q[j+1], q[j]);
//             }
//             j++;
//         }
//
//         // for(auto i:q)
//         //     cout << i << "  ";
//         // cout << endl;
//     }
//
//     // for(int i = 1; i <= n; i++)
//     //     cout << i << " --> " << freq[i] << endl;
//
//     int sum = 0;
//     for(auto i:freq){
//         if(i > 2){
//             cout << "Too chaotic" << endl;
//             return;
//         }
//         sum += i;
//     }
//
//     cout << sum << endl;
//     return ;
// }
/*
if(q[j+1] < q[j]){
    freq[j]++;

    if(freq[j] > 2){
        cout << "Too chaotic" << endl;
        return;
    }

    swap(q[j+1], q[j]);
}
*/

void minimumBribes(vector<int> q){
    int n = q.size();
    int totalNoOfBribes = 0;

    
}

int main(){
    // vector<int> arr({2, 1, 5, 3, 4});
    // vector<int> arr({2, 5, 1, 3, 4});
    // vector<int> arr({1, 2, 5, 3, 7, 8, 6, 4});
    // vector<int> arr({5, 1, 2, 3, 7, 8, 6, 4});

    minimumBribes(arr);

    return 0;
}
/*
5 1 2 3 7 8 6 4
1 2 5 3 7 8 6 4
2 5 1 3 4
1 2 5 3 4 7 8 6
*/
