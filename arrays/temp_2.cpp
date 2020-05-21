#include <bits/stdc++.h>
using namespace std;

void trap(vector<int> &arr){
    int n = arr.size();
    int sum = 0;

    vector<int> leftWalaMax(n, 0);
    vector<int> rightWalaMax(n, 0);

    // hr value ke left me jo max h ussko uss value ke index pr save krna
    int leftMax = 0;
    for(int i = 0; i < n; i++){
        if(leftMax < arr[i])
            leftWalaMax[i] = 0;
        else
            leftWalaMax[i] = leftMax;


        if(arr[i] > leftMax)
            leftMax = arr[i];
    }

    // hr value ke right me jo max h uss index pr save krna
    int rightMax = 0;
    for(int i = n-1; i >=0; i--){
        if(rightMax < arr[i])
            rightWalaMax[i] = 0;
        else
            rightWalaMax[i] = rightMax;

        if(arr[i] > rightMax)
            rightMax = arr[i];
    }

    for(int i = 0; i < n; i++){
        cout << leftWalaMax[i] << "\t";
    }

    cout << "\n\n";
    for(int i = 0; i < n; i++){
        cout << rightWalaMax[i] << "\t";
    }

    // display the left and right array
    // for(int i = 0; i < n; i++){
    //     cout << leftWalaMax[i] << " <-- " << arr[i] << " --> " << rightWalaMax[i] << endl;
    // }
}

// Driver function
int main(){
    vector<int> arr({3, 2, 5, 1, 4, 6, 10, 4, 2, 5});

    trap(arr);

    return 0;
}
