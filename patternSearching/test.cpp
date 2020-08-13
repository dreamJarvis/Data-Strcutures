#include <bits/stdc++.h>
using namespace std;

void computeLPSArray(string, vector<int> &);

bool KMPSearch(string text, string pattern){
    int textLen = text.length();
    int patternLen = pattern.length();

    vector<int> longestPrefixLength(patternLen, 0);       // stores the length of prefixes in the array
    computeLPSArray(pattern, longestPrefixLength);

    int i = 0;
    int j = 0;
    while(i < textLen){
        if(text[i] == pattern[j]){
            i++;
            j++;
        }

        if(j == patternLen){
            // cout << "pattern found at : " << i-j << endl;
            j = longestPrefixLength[j-1];
            return true;
        }
        else if(i < textLen && text[i] != pattern[j]){
            if(j != 0){
                j = longestPrefixLength[j-1];
            }
            else{
                i++;
            }
        }
    }

    return false;
}

void computeLPSArray(string pattern, vector<int> &longestPrefixLength){
    int n = pattern.length();


    int i = 1;
    int j = 0;
    while(i < n){
        if(pattern[i] == pattern[j]){
            j++;
            longestPrefixLength[i] = j;
            i++;
        }

        else {
            if(j != 0){
                j = longestPrefixLength[j-1];
            }
            else{
                longestPrefixLength[i] = 0;
                i++;
            }
        }
    }
}

// Driver function
int main(){
    string txt = "ABABDABACDABABCABAB";
    string pat = "ABABCABAB";

    cout << KMPSearch(txt, pat) << endl;

    return 0;
}
