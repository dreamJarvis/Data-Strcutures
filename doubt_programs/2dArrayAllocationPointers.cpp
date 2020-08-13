// https://stackoverflow.com/questions/936687/how-do-i-declare-a-2d-array-in-c-using-new
#include <bits/stdc++.h>
using namespace std;

int main() {
    // int** a = new int*[5];
    // for(int i = 0; i < 5; ++i)
    //     a[i] = new int[6];
    //
    // for(int i = 0; i < 5; i++){
    //     for(int j = 0; j < 6; j++)
    //         a[i][j] = (i+j+1);
    // }
    //
    // for(int i = 0; i < 5; i++){
    //     for(int j = 0; j < 6; j++)int
    //         cout << a[i][j] << " ";
    //     cout << endl;
    // }

    // int** a = new int*[5];
    // for(int i = 0; i < 5; ++i)
    //     a[i] = new int[i+1];
    //
    // for(int i = 0; i < 5; i++){
    //     for(int j = 0; j < i+1; j++)
    //         a[i][j] = (i+j+1);
    // }
    //
    // // doubt : kya sizeof() function dynamically allocated arrays ka size nhi bta skta ?
    // for(int i = 0; i < 5; i++){
    //     int s = sizeof(a[i])/sizeof(a[i][0]);
    //     for(int j = 0; j < s; j++)
    //         cout << a[i][j] << " ";
    //     cout << endl;
    // }

    vector<int> b[3];
    // vector<int> *a = b;

    for(int k = 0; k < 3; k++){
        for(int i = 0; i < 5; i++)
            b[k].push_back((k+1)*(i+1));
    }

    for(int i = 0; i < 3; i++){
        for(auto j:b[i])
            cout << j << " ";
        cout << endl;
    }

    return 0;
}
