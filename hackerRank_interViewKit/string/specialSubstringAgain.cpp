// hackerRank special substring again
// solution reference : https://www.youtube.com/watch?v=SJ_C9mclZJo
#include <bits/stdc++.h>
using namespace std;

/*
    method used :


*/
long substrCount(int n, string str) {
    // cause we will include all the single charecters
    long totalCount = n;

    // this loop will count all the substring with same charecters and all the substring with different middle element
    for(int i = 0; i < n; i++){

        // to find the substring with all the same charecters
        int result=0;
        while(i+1 < n && str[i] == str[i+1]){
            result++;
            i++;
        }
        totalCount += (result * (result+1)/2) ;

        // to find all the substring whose middle element is different
        int ptr = 1;
        while(i - ptr >= 0 && i + ptr < n
                && str[i+ptr] == str[i-1]
                && str[i-ptr] == str[i+1]
        ){
            totalCount++;
            ptr++;
        }
    }

    return totalCount;
}

// Driver function
int main(){
    string str = "abcbaba";
    cout << substrCount(str.size(), str) << endl;
    return 0;
}
/*
asasd, 7
abcbaba, 10
aaaa, 10
*/
