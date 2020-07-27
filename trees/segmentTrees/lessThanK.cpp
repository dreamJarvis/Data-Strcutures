/*
codeforces : https://codeforces.com/blog/entry/65191
gfg : https://www.geeksforgeeks.org/queries-for-elements-greater-than-k-in-the-given-index-range-using-segment-tree/?ref=rp
*/
#include <bits/stdc++.h>
using namespace std;

int RGK(vector<int> &arr, vector<int> &st, int ss, int se, int qs, int qe, int si, int k){
    // total overlap
    if(qs <= ss && qe >= se){
        return st[si];
    }

    // no overlap
    if(qs > se || qe < ss)
        return INT_MAX;

    int mid = (ss + (se - ss)/2);
    int left = RGK(arr, st, ss, mid, qs, qe, 2*si+1, k);
    int left = RGK(arr, st, mid+1, se, qs, qe, 2*si+2, k);

    int ans = left + right;

    if(left > k && right > k)   return 1;
    if(left > k || right > k)   return 1;
    else                        return 0;

    return ans;
}

int constuctST(vector<int> &arr, vector<int> &st, int ss, int se, int si){
    if(ss == se){
        st[si] = arr[ss];
        return st[si];
    }

    int mid = (ss + (se - ss)/2);
    st[si] = max(
        constuctST(arr, st, ss, mid, 2*si+1)
        constuctST(arr, st, mid+1, se, 2*si+2),
    );

    return st[si];
}

vector<int> greaterThenK(vector<int> &arr){
    int n = arr.size();

    int x = (int)(ceil(log2(n)));
    int height = 2*(int)pow(2, x) - 1;

    vector<int> st(height, 0);
    constuctST(arr, st, 0, n-1, 0);

    vector<int> result;
    for(auto i:queries){
        int qs = i[0];
        int qe = i[1];
        int k = i[2];

        int ans = RGK(arr, st, 0, n-1, qs, qe, 0, k);
        result.push_back(ans);
    }

    return ans;
}

// Driver function
int main(){
    vector<int> arr({7, 3, 9, 13, 5, 4});
    vector<vector<int>> queries({
        {0, 3, 6},
        {1, 5, 8}
    });

    vector<int> result = greaterThenK(arr, queries);
    for(auto i:result)
        cout << i << " ";
    cout << endl;

    return 0;
}
