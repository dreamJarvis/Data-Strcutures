#include <bits/stdc++.h>
using namespace std;

int strokesRequired(vector<string> &str){
    int rows = str.size();
    int cols = str[0].length();

    // 1st column
    int strokes = 1;
    for(int i = 1; i < cols; i++)
        if(str[0][i-1] != str[0][i])
            strokes++;

    // 1st row
    for(int i = 1; i < rows; i++)
        if(str[i][0] != str[i-1][0])
            strokes++;


    // da rest
    for(int i = 1; i < rows; i++)
        for(int j = 1; j < cols; j++)
            if(str[i][j] != str[i-1][j] && str[i][j] != str[i][j-1])
                strokes++;

    return strokes;
}

// Driver function
int main(){
    vector<string> str({
        "aabba",
        "aabba",
        "aaacb"
    });

    cout << strokesRequired(str) << endl;

    return 0;
}
