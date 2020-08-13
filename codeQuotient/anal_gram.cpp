// to check if 2 strings are anagram or not
#include <iostream>
using namespace std;

int isAnagram(string str1, string str2){
    int arr[174]={0};

    for(auto item:str1)
        arr[item]++;

    for(auto item:str2)
        arr[item]--;

    for(int i = 99; i < 174; i++)
        if(arr[i])
            return 0;

    return 1;
}

// Driver function
int main(){
    string  str1 = "Hi";
    string  str2 = "hI";

    // string str1 = "CodeQuotient";
    // string str2 = "QuotientCode";

    cout << isAnagram(str1, str2) << endl;

    return 0;
}
