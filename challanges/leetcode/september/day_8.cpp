/*
    290. Word Pattern
*/
#include <bits/stdc++.h>
using namespace std;

// 2 hashmaps approach
// tc : O(N)
// sc : O(M)
class Solution {
public:
    bool wordPattern(string pattern, string str) {
        // we are just seperating the strings with delimeter as space
        vector<string> arr;
        string res="";
        string deli = " ";
        for(auto i:str){
            char ch = 32;       // acsii code for space
            if(i != ch)
                res += i;
            else{
                arr.push_back(res);
                res = "";
            }
        }
        arr.push_back(res);

        if(arr.size() != pattern.length())   return false;

        unordered_map<char, string> map;
        unordered_map<string, bool> visited;
        for(int i = 0; i < arr.size(); i++){
            if(!map.count(pattern[i]) && !visited[arr[i]]){
                map[pattern[i]] = arr[i];
                visited[arr[i]] = true;
            }
            else if(map.count(pattern[i]) && !visited[arr[i]]){
                return false;
            }
        }

        for(int i = 0; i < arr.size(); i++){
            if(map[pattern[i]] != arr[i])
                return false;
        }

        return true;
    }
};

// Driver function
int main(){
    string pattern = "abba";
    string str = "dog cat cat dog";

    // string pattern = "abba";
    // string str = "dog cat cat fish";

    // string pattern = "jquery";
    // string str = "jquery";

    Solution s;
    cout << s.wordPattern(pattern, str) << endl;

    return 0;
}
