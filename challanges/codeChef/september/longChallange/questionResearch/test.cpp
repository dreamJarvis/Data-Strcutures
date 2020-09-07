#include <iostream>
#include <algorithm>
#include <vector>
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

        vector<vector<int>> arr(N, vector<int>(N, 0));
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                cin >> arr[i][j];
            }
        }

        vector<int> firstRow = arr[0];
        vector<int> firstCol(N);
        for(int i = 0; i < N; i++)
            firstCol[i] = arr[i][0];


        vector<int> res;
        res.insert(res.end(), firstRow.begin(), firstRow.end());
        res.insert(res.end(), firstCol.begin()+1, firstCol.end());

        vector<int> temp = res;
        sort(temp.begin(), temp.end());

        for(auto i:res)
            cout << i << " ";
        cout << endl;

        for(auto i:temp)
            cout << i << " ";
        cout << endl;

        int count = 0;
        for(int i = 0; i < 2*N; i++){
            if(res[i] != temp[i])
                count++;
        }

        cout << count << endl;
    }

    return 0;
}
/*
1
4
1 2 9 13
5 6 10 14
3 7 11 15
4 8 12 16
*/
