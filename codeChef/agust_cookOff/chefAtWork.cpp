#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int tc;
    cin >> tc;

    while(tc--){
        int N, K;
        cin >> N >> K;

        int arr[N]={0};
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }

        int count = 1;
        int sum = 0;
        bool flag = true;
        for(int i = 0; i < N; i++){
            if(arr[i] > K){
                flag = false;
                break;
            }
            sum += arr[i];
            if(sum > K){
                count++;
                sum = arr[i];
            }
        }

        if(flag)
            cout << count << endl;
        else
            cout << -1 << endl;
    }

    return 0;
}
