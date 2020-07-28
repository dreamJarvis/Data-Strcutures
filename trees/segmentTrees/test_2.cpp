#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n=3, k=1, m=0;
    vector<int> arr({4, 5, 6});

    int j = 0;
    int ans[n-k];
    for(int i =0; i < n; i++){
        ans[j++] = arr[i+k] ^ arr[i];
    }

    for(auto i:ans)
        cout << i <<" ";
    cout << endl;

    cout << ans[m] << endl;

    return 0;
}
