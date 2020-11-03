/*
    887. Super Egg Drop
    https://leetcode.com/problems/super-egg-drop/

    sol : https://leetcode.com/problems/super-egg-drop/discuss/792736/CPP-Explained-Recursive-greatermemoization-greateroptimization-greaterDP-oror-Well-Explained-oror-Easy-to-unserstand
*/
#include <iostream>
#include <climits>
using namespace std;


// Driver function
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // int tc;
    // cin >> tc;
    //
    // while(tc--){
    //     int N,K;
    //     cin >> N >> K;
    //     cout << superEggDrop(N, K) << endl;
    // }

    // int K = 1, N = 2;
    // int K = 2, N = 6;
    int K = 3, N = 14;

    cout << superEggDrop(K, N) << endl;

    return 0;
}
