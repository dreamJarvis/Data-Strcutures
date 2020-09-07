#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

// Driver function
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int tc;
    cin >> tc;

    while(tc--){
        int N;
        cin >> N;

        set<int> st;
        int temp;
        for(int i = 0; i < N; i++){
            cin >> temp;
            if(temp != 0)
                st.insert(temp);
        }

        cout << st.size() << endl;
    }

    return 0;
}
