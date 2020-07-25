// https://leetcode.com/problems/largest-rectangle-in-histogram/
#include <bits/stdc++.h>
using namespace std;

// utility function to get minimum of 2 numbers in hist[]
int minVal(int *hist, int i, int j){
    if(i == -1) return j;
    if(j == -1) return i;
    return (hist[i] < hist[j] ? i:j);
}

// a utility function to get the middle index from corner indexes
int getMid(int s, int e){
    return (s + (e - s)/2);
}

/*
    a recursive function to get index of minimum value in given range of indexes.The following 
*/

// Driver function
int main(){

    return 0;
}
