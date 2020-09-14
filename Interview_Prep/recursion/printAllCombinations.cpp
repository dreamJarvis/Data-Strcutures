/*
    Print all possible combinations of r elements in a given array of size n
    https://www.geeksforgeeks.org/print-all-possible-combinations-of-r-elements-in-a-given-array-of-size-n/#:~:text=using%20Priority%20Queue-,Print%20all%20possible%20combinations%20of%20r%20elements,given%20array%20of%20size%20n&text=Given%20an%20array%20of%20size,and%20%7B3%2C%204%7D.
*/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> combine(int n, int k) {

    }
};

// Driver function
int main(){
    int n = 4, k = 2;

    Solution s;
    for(auto i:s.combine(n, k)){
        cout << "[";
        for(auto j:i){
            cout << j << ", ";
        }
        cout << "]\n,";
    }

    return 0;
}
