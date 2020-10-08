#include <bits/stdc++.h>
using namespace std;

bool isUgly(int num) {
    bool flag = true;
    while(num){
        if(num == 1)    return true;
        if(num%2 == 0 || num%3 ==0 || num%5 == 0){
            if(num%2 == 0){
                num = num/2;
            }
            else if(num%3 == 0){
                num = num/3;
            }
            else if(num%5 == 0){
                num = num/5;
            }

            cout << num << endl;
        }
        else
            return false;
    }

    return true;
}

// Driver function
int main(){
    int n = 6;
    cout << isUgly(n) << endl;
    return 0;
}
