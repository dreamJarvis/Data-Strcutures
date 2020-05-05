// valid parenthesis string
#include <bits/stdc++.h>
using namespace std;

// bool validParenthesisString(string s){
//     int n = s.length();
//
//     if(n == 0)  return true;
//
//     // stack<char> sl;
//     // stack<char> sr;
//     int l=0, r=0, st=0;
//     for(auto item:s){
//         if(item=='('){
//             l++;
//         }else if(item == '*'){
//             st++;
//         }else if(item == ')'){
//             r++;
//         }
//     }
//
//     if(l == r)  return true;
//     else{
//         if(l > r){
//             if(l-st == r)   return true;
//         }else if(l < r){
//             if(l+st == r)   return true;
//         }
//     }
//
//     return false;
// }

bool validParenthesisString(string str){
    int n = str.length();

    if(n==0)            return 1;
    if(str[0]==')')     return 0;       // as instructed that string will start with '('

    int leftVal = 0, rightVal = 0, star = 0;

    int i = 0;
    for(i = 0; i < n; i++){
        if(str[i] == ')')   rightVal++;
        if(str[i] == '(')   leftVal++;
        if(str[i] == '*')   star++;
    }

    if(leftVal == rightVal) return true;
    else if(abs(leftVal - rightVal) <= star) return true;
    return false;
}

// Driver function
int main(){
    // string str = "()()";
    string str = "(*)";

    cout << validParenthesisString(str) << endl;

    return 0;
}
