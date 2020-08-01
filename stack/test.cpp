#include <bits/stdc++.h>
using namespace std;

int main(){
    set<int, greater<>> s;
    s.insert(1);
    s.insert(2);
    s.insert(3);

    cout << *(s.begin()) << endl;

    return 0;
}
/*
0,0,1,1,1,2,2,3,3,4
*/
