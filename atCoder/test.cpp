#include <bits/stdc++.h>
using namespace std;

vector<int> scores(vector<int> &alice, vector<int> &bob){
    int n = alice.size();

    int aliceCount = 0, bobCount = 0;
    for(int i = 0; i < n; i++){
        if(alice[i] > bob[i])   aliceCount++;
        else if(alice[i] < bob[i])  bobCount++;
        else    continue;
    }

    return ( vector<int>({aliceCount, bobCount}) );
}

// Driver function
int main(){
    vector<int> alice({17, 28, 30});
    vector<int> bob({19, 16, 8});

    for(auto value:scores(alice, bob))
        cout << value << " ";

    cout <<endl;
    return 0;
}
