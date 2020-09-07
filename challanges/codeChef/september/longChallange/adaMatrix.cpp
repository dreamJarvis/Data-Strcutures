#include <iostream>
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
        for(int i = 0; i < N; i++)  firstCol[i] = arr[i][0];


        int ptr1 = 1, ptr2 = 1;
        int num = 2;
        int count = 0;
        bool flag = true;
        while(num <= N){
            if(flag && arr[0][ptr1] != num){
                cout << arr[0][ptr1] << ", " << num << endl;
                flag = !flag;
                count++;
            }

            if(!flag && arr[ptr2][0] != num){
                cout << arr[ptr2][0] << ", " << num << endl;
                flag = !flag;
                count++;
            }

            ptr1++;
            ptr2++;
            num++;
        }

        if(!flag) count++;
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

1
4
1 2 3 4
5 6 7 8
9 10 11 12
13 14 15 16

1
4
1 2 9 4
5 6 7 8
3 10 11 12
13 14 15 16
*/
