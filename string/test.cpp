// next greater element
#include <bits/stdc++.h>
using namespace std;

void KMPSearch(string text, string str){
    int n = text.length();
    int m = str.length();

    vector<int> indexes(m);

    indexes[0] = 0;

    int i = 0, j = 1;
    while(i < n){
        if(str[i] == str[j]){
            indexes[j] = i;
            i++;
        }
        else{
            if(j >= n){
                i++;
                j = i+1;
            }
            else
                j++;
        }
    }
}

int main(){
    string text = "ABABABCABABABCABABABC";
    string pattern = "ABABAC";

    cout << KMPSearch(arr) << endl;

    return 0;
}
