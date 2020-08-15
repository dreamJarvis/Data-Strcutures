#include <bits/stdc++.h>
using namespace std;

void reverseStack(stack<int> a, multiset<int> &st){
    if(a.empty())   return;

    st.insert(a.top());
    a.pop();

    reverseStack(a, st);
}

int main(){
    stack<int> a;
    multiset<int> st;

    a.push(10);
    a.push(23);
    a.push(7);
    a.push(4);
    a.push(12);
    a.push(1);

    reverseStack(a, st);

    for(auto i:st)
        cout << i << " ";
    return 0;
}
