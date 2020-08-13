#include <bits/stdc++.h>
using namespace std;

#define ll long long

void subArrays(ll arr[], int start, int end, int n, vector<int> &ans){
	if (end == n)
		return;

	else if (start > end)
		subArrays(arr, 0, end + 1, n, ans);

	else {
        int x=0;
		for (int i = start; i <= end; i++)
            x |= arr[i];
        ans.push_back(x);

		subArrays(arr, start + 1, end, n, ans);
	}

	return;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;

        ll arr[n];
        for(int i = 0; i < n; i++)
            cin >> arr[i];

        vector<int> ans;
        subArrays(arr, 0, 0, n, ans);

        unordered_map<ll, int> freq;
        for(auto i:ans)
            freq[i]++;

        bool flag = true;
        for(auto i:freq){
            if(i.second > 1){
                flag = false;
                break;
            }
        }

        if(flag)    cout << "YES" << endl;
        else        cout << "NO" << endl;
    }

    return 0;
}
