#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int tc;
    cin >> tc;

    while(tc--){
        int n;
        cin >> n;

        int arr[n] = {0};
        for(int i = 0; i < n; i++){
            cin >> arr[i];
        }

        int totalCount = 0;
        for(int i = 0; i < n; i++){
            int pairs = 0;
            for(int j = i+1; j < n; j++){
                if(arr[i] == (arr[i] and arr[j]))
                    pairs++;
            }

            totalCount += ((pairs)*(pairs-1))/2;
        }
        cout << totalCount << endl;
    }
}
