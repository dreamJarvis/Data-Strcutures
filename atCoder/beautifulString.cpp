#include <bits/stdc++.h>
using namespace std;

int beautifulString(string str){
    int count = 0, i = 0;

    while(i < str.length()-2){
        if(str[i] != '0')   i++;
        else{
            if(str[i]=='0' && str[i+1]=='1' && str[i+2]=='0'){
                count++;
                i+=3;
                continue;
            }
            i++;
        }
    }

    return count;
}

// Driver function
int main(){
    // string str = "0100101010";
    string str = "01100";

    cout << beautifulString(str) << endl;

    return 0;
}
