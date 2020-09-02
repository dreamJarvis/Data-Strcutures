#include <bits/stdc++.h>
using namespace std;

// TLE
// int maxOccuredInteger(int L[], int R[], int n){
//     unordered_map<int, int> freq;
//     int maxOcc = -1;
//     for(int i = 0; i < n; i++){
//         freq[L[i]]++;
//         freq[R[i]]++;
//         maxOcc = max(maxOcc, max(freq[L[i]], freq[R[i]]));
//     }
//
//     for(int i = 0; i < n; i++){
//         int s = L[i];
//         int e = R[i];
//
//         for(int j = s+1; j < e; j++){
//             if(freq.count(j)){
//                 freq[j]++;
//                 maxOcc = max(maxOcc, freq[j]);
//             }
//         }
//     }
//
//     set<pair<int, int>> s;
//     for(auto i:freq){
//         if(i.second >= maxOcc){
//             s.insert({i.first, i.second});
//             maxOcc = i.second;
//         }
//     }
//
//     return (s.begin()->first);
// }



int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int tc;
    cin >> tc;

    while(tc--){
        int N;
        cin >> N;

        int L[N], R[N];
        for(int i = 0; i < N; i++){
            cin >> L[i];
        }

        for(int i = 0; i < N; i++){
            cin >> R[i];
        }

        cout << maxOccuredInteger(L, R, N) << endl;
    }

    return 0;
}
/*
2
4
1 4 3 1
15 8 5 4
5
1 5 9 13 21
15 8 12 20 30
*/
