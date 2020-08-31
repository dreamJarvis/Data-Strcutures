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

        // cin.flush();

        bool neo = true;
        for(int i = 0; i < N; i++){
            int count = 0;
            cout << i << " ";
            while(i < N && !arr[i]){
                count++;
                i++;
            }
            // i--;

            // cout << count << endl;

            if(count%2==0){
                neo = false;
            }
            // cout << arr[i] << " ";
        }

        // if(neo)
        //     cout << "Yes" << endl;
        // else
        //     cout << "No" << endl;

        // for(int i = 0; i < N; i++)
        //     cout << arr[i] << " ";
        // cout << endl;
    }

    return 0;
}
