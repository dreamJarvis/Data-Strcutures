// reverse the words of a string
#include <bits/stdc++.h>
using namespace std;

// time complexity : O(n*m)
// space complexity : O(n)
void revWordsString(string &s){
    int n = s.length();

    string result = "";
    int ptr_1 = 0, ptr_2 = 0;

    // O(n*m)
    while(ptr_1 != n && ptr_2 != n){
        if(ptr_1 == ptr_2){
            ptr_2++;
        }
        else if(s[ptr_2] == 32){
            int temp = ptr_2;

            while(temp != ptr_1){
                temp--;
                result += s[temp];
            }

            ptr_1 = ptr_2;
        }
        else if(s[ptr_1] == 32){
            result += " ";
            ptr_1++;
        }
        else
            ptr_2++;
    }

    ptr_1--;
    ptr_2--;
    if(s[ptr_2] != 32 && ptr_1 != ptr_2){
        while(ptr_2 != ptr_1){
            result += s[ptr_2];
            ptr_2--;
        }
    }

    s = result;
}

// Driver function
int main(){
    string str = "i am tarun Jha";

    cout << str << endl;
    revWordsString(str);
    cout << str << endl;

    // cout << str << endl;
    return 0;
}
