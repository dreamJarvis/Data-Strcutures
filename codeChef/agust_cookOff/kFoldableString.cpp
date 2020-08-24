#include <bits/stdc++.h>
using namespace std;

bool isKFoldable(vector<int> str, int k){
    int pos = 2*k+1;
    int n = str.size();
    for(int i = 0; i < n; i++){
        if(str[i] != str[pos-i])
            return false;
    }

    return true;
}

void permuteUTIL(vector<int>& nums, string &result, int pos, bool &hoChuka, int k){
    if(pos == nums.size()){
        bool flag = isKFoldable(nums, k);
        if(flag){
            if(hoChuka)
                result = min(result, to_string(nums));
            else{
                result = to_string(nums);
                hoChuka = true;
            }
        }
    }

    for(int i = pos; i < nums.size(); i++){
        swap(nums[pos], nums[i]);
        permuteUTIL(nums, result, pos+1, hoChuka);
        swap(nums[pos], nums[i]);
    }
}

string permute(vector<int>& nums) {
    string res = "";
    permuteUTIL(nums, res, 0, false);
    return result;
}

// Driver function
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int tc;
    cin >> tc;

    while(tc--){
        int N, K;
        cin >> N >> K;

        int arr[N]={0};
        for(int i=0; i < N; i++)
            cin >> arr[i];

        string res = permute(arr, K);
        string ans = res.substr(n-K);

        cout << ans << endl;
    }

    return 0;
}
