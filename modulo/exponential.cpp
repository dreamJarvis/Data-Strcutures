// given 3 numbers x, y, and p, compute (x^y)%p
#include <bits/stdc++.h>
using namespace std;

// Iterative function to calculate (x^y)%p in O(logy)
int power(int x, unsigned int y, int p){

    if(x == 0)  return 0;

    long long int res = 1;

    x = x%p;    // update x if it is more than or == p

    while(y > 0){
        // if y is odd, multiply x with result
        if(y&1){
            res = (res*x)%p;
        }

        // y mmust be even now
        y = y>>1;   //  y = y/2
        x = (x*x)%p;
    }

    res = (res + p)%p;
    return res;
}

// Driver function
int main(){
    int x = 71045970;
    int y = 41535484;
    int p = 64735492;

    cout << "Power is " << power(x, y, p);

    return 0;
}
