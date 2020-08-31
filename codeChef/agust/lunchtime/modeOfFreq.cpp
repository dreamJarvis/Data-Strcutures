#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int tc;
    cin >> tc;

    while(tc--){
        int N;
        cin >> N;

        int arr[N];
        for(int i = 0;i < N; i++)
            cin >> arr[i];

        unordered_map<int, int> mp;
        unordered_map<int, int> mp2;

        for(int i = 0; i < N; i++){
            mp[arr[i]]++;
        }

        int maxFreq = INT_MIN;
        for(auto i:mp){
            mp2[i.second]++;
            maxFreq = max(maxFreq, mp2[i.second]);
        }


        // for(auto i:mp2)
        //     cout << i.first << " -- " << i.second << endl;

        // // int freq = INT_MAX;
        // set<int> freq;
        // int maxFreq = INT_MIN;
        // for(auto i:mp2){
        //     if(maxFreq <= i.second){
        //         freq.insert(i.first);
        //         maxFreq = i.second;
        //     }
        // }

        set<int> st;
        for(auto i:mp2)
            if(i.second == maxFreq){
                // cout << "l : " << i.first << " -- " << i.second << endl;
                st.insert(i.first);
            }

        auto it = st.begin();
        cout << (*it) << endl;
    }
}
