#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;

        string str;
        cin >> str;

        int arr[27]={0};

        for(auto i:str)
            arr[i-'a']++;

        for(int i= 0; i <27; i++)
            arr[i] %= 2;

        bool flag = true;
        for(int i = 0; i < 27; i++){
            if(arr[i]){
                flag = false;
                break;
            }
        }

        if(flag)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}
