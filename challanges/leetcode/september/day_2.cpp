/*
    949. Largest Time for Given Digits
*/
#include <bits/stdc++.h>
using namespace std;

/*
tc : O(1), beacuse size of array is fixed
total permutation of N size array = N!
here the size of array is fixed i.e. 4 .'. we will have total of 4*3*2*1 loops whcih is constant
*/
class Solution {
public:
    string largestTimeFromDigits(vector<int>& A) {
        int maxTime = -1;

        sort(A.begin(), A.end());

        do{
            int hour = A[0]*10 + A[1];
            int minute = A[2]*10 + A[3];

            if(hour < 24 && minute < 60){
                int newTime = hour*60 + minute;     // converting the time to minute
                maxTime = max(maxTime, newTime);
            }
        }while(next_permutation(A.begin(), A.end()));       // c++ function gives all the permutation of the given array

        if(maxTime == -1)   return "";
        else {
            ostringstream strstream;
            strstream << setw(2) << setfill('0') << maxTime/60
               << ":" << setw(2) << setfill('0') << maxTime%60;
            return strstream.str();
        }
    }
};

int main(){
    // vector<int> arr({1, 2, 3, 4});
    // vector<int> arr({1, 9, 6, 0});
    // vector<int> arr({4, 2, 4, 4});
    // vector<int> arr({0, 4, 0, 0});
    vector<int> arr({2, 0, 6, 6});

    Solution s;
    cout << s.largestTimeFromDigits(arr) << endl;

    return 0;
}
