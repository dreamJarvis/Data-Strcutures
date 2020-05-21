#include <iostream>
using namespace std;

int countWords(char str[]){
    int count = 0;
    int size = 0;
    // str++;
    while(*str){
        if( (*str == 32) && ( *(str-1) != 32)){
            count++;
        }
        str++;
        size++;
    }

    // cout << count << ", " << size << endl;
    if((*(str - 1) != 32) && size)
        count++;

    return count;
}

// Driver function
int main(){
    char ch[] = "i am tarun jha";
    // char ch[] = "";

    cout << countWords(ch) << endl;

    return 0;
}
