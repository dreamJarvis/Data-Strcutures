#include <bits/stdc++.h>
using namespace std;

void reverseStack(stack<int> &a, stack<int> &b){
    if(a.empty())   return;
    b.push(a.top());
    a.pop();
    reverseStack(a, b);
}

int main(){
    stack<int> a, b;

    a.push(1);
    a.push(2);
    a.push(3);
    a.push(4);
    a.push(5);

    reverseStack(a, b);

    while(!b.empty()){
        cout << b.top() << " ";
        b.pop();
    }
}
