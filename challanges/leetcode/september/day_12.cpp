/*
    299. Bulls and Cows
    https://leetcode.com/problems/bulls-and-cows/
*/
#include <iostream>
#include <vector>
#include <climits>
#include <utility>
#include <algorithm>
#include <unordered_map>
using namespace std;

// O(N)
class Solution {
public:
    string getHint(string secret, string guess) {
        int n = secret.length();

        int A=0, B=0;
        int arr[10] = {0};
        for(int i = 0; i < n; i++)
            arr[secret[i]-'0']++;

        string left = "";
        for(int i = 0; i < n; i++){
            if(secret[i] == guess[i]){
                A++;
                arr[secret[i]-'0']--;
            }
            else
                left+=guess[i];
        }

        for(int i = 0; i < left.length(); i++){
            if(arr[left[i]-'0'] > 0){
                B++;
                arr[left[i]-'0']--;
            }
        }

        string ans = to_string(A) + "A" + to_string(B) + "B";
        return ans;
    }
};

// Driver function
int main(){

    return 0;
}
