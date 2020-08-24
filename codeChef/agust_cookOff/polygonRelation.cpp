#include <bits/stdc++.h>
using namespace std;

// Driver function
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int tc;
    cin >> tc;

    while(tc--){
        int N;
        cin >> N;

        int x, y;
        for(int i = 0; i < N; i++){
            cin >> x >> y;
        }

        int n = N;
        int count = n;

        int temp = n + (n/2);
        while(temp/3 >= 3){
            count += temp/3;
            temp /= 3;
            temp += (temp/2);
        }

        cout << count << endl;
    }

    return 0;
}
