/*
    12. Median of 2 Sorted Arrays of Different Sizes
    https://practice.geeksforgeeks.org/problems/median-of-2-sorted-arrays-of-different-sizes/0/?track=amazon-searching&batchId=192

    leetcode : 4. Median of Two Sorted Arrays
    https://leetcode.com/problems/median-of-two-sorted-arrays/
*/
#include <bits/stdc++.h>
using namespace std;

// double util(vector<int> &a, vector<int> &b, int mIndex){
//     int n = a.size();
//     int m = b.size();
//
//     int i = 0, j = 0, k=0;
//     while(i < n && j < m){
//         if(a[i] < b[j]){
//             if(k == mIndex)
//                 return a[i];
//             k++;
//             i++;
//         }
//         else if(a[i] >= b[j]){
//             if(k == mIndex)
//                 return b[j];
//             k++;
//             j++;
//         }
//     }
//
//     while(i < n){
//         if(k == mIndex)
//             return a[i];
//         k++;
//         i++;
//     }
//
//     while(j < m){
//         if(k == mIndex)
//             return b[j];
//         k++;
//         j++;
//     }
//
//     return -1;
// }
//
// // O(n)
// // O(1)
// double MedianOfArrays(vector<int>& a, vector<int>& b){
//     int n = a.size();
//     int m = b.size();
//     int size = n+m;
//
//     bool isEven = true;
//     if(size%2){
//         isEven = false;
//     }
//
//     if(!isEven){
//         int pos = (n+m)/2;
//         return util(a, b, pos);
//     }
//     else{
//         int pos1 = (n+m)/2;
//         int pos2 = (n+m)/2-1;
//
//         int t1 = util(a, b, pos1);
//         int t2 = util(a, b, pos2);
//
//         double res = (float)(t1+t2)/2;
//         return res;
//     }
// }

// O(log(m+n)))
// O(1)
double MedianOfArrays(vector<int>& nums1, vector<int>& nums2) {

}

// Driver function
int main(){
    // vector<int> a({1, 5, 9});
    // vector<int> b({2, 3, 6, 7});

    vector<int> a({4, 6});
    vector<int> b({1, 2, 3, 5});

    double ans = MedianOfArrays(a, b);
    cout << ans << endl;

    return 0;
}
