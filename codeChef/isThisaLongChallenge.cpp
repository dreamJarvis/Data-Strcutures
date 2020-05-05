#include <bits/stdc++.h>
using namespace std;

#define MOD 100000007
#define ll long long int

// type 1
void queryType1(string &str, ll l, ll r, char c){
    l--;
    r--;
    for(int i = 0; i < str.length(); i++){
        if(i >= l && i <= r){
            str[i] = c;
        }
    }
}

// type 2
void queryType2(string str, ll l, ll r, ll p, ll q){

    // cout << l << r << p << q << endl;

    l -= 1;
    r -= 1;
    for(int i = 0; i < str.length(); i++){
        if(i >= l && i <= r){
            ll temp1 = p, temp2 = q;
            if(str[i] == 'A'){
                temp1 = (p-q+MOD)%MOD;
                temp2 = (p+q)%MOD;
                p = temp1;
                q = temp2;

                // cout << "A : " << p << "\t" << q << endl;
            }
            else if(str[i] == 'B'){
                temp1 = (p+q)%MOD;
                temp2 = (q-p+MOD)%MOD;

                p = temp1;
                q = temp2;

                // cout << "B : " << p << "\t" << q << endl;
            }
        }
    }
    cout << p << "\n" << q << endl;
}

// Driver function
int main(){
    int t = 0;
    cin >> t;

    for(int i = 0; i < t; i++){
        string str;
        int strLen = 0;
        cin >> strLen;

        cin >> str;


        ll queries, type=0, l, r, p, q;
        char c;

        cin >> queries;
        for(ll j = 0; j < queries; j++){
            cin >> type;

            if(type == 1){
                cin >> l >> r >> c;
                queryType1(str, l, r, c);
            }
            else if(type == 2){
                cin >> l >> r >> p >> q;
                queryType2(str, l, r, p, q);
            }
        }
    }
    return 0;
}
