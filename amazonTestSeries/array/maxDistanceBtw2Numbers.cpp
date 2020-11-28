/*
*/
#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <unordered_map>
using namespace std;

int minDist(int a[], int n, int x, int y){
    int temp = INT_MAX;
    for(int i = 0; i < n; i++){
        if(a[i] == x){
            int j = i;
            while(j < n){
                if(a[j] == y){
                    if(temp > abs(j-i))
                        temp = abs(j-i);
                    break;
                }
                j++;
            }
        }
        else if(a[i] == y){
            int j = i;
            while(j < n){
                if(a[j] == x){
                    if(temp > abs(j-i))
                        temp = abs(j-i);
                    break;
                }
                j++;
            }
        }
    }

    return temp == INT_MAX ? -1 : temp;
}

// int minDist(int a[], int n, int x, int y){
//     unordered_map<int, vector<int>> indexes;
//
//     for(int i = 0; i < n; i++){
//         if(a[i] == x || a[i] == y)
//             indexes[a[i]].push_back(i);
//     }
//
//     int dist = INT_MAX;
//     if(indexes[x].size() > 0 && indexes[y].size() > 0){
//         int n = indexes[x].size();
//         int m = indexes[y].size();
//         int i = 0, j = 0;
//
//         while(i  < n && j < m){
//             int diff = abs(indexes[x][i] - indexes[y][j]);
//             if(indexes[x][i] < indexes[y][j]){
//                 dist = min(dist, diff);
//                 i++;
//             }
//             else{
//                 dist = min(dist, diff);
//                 j++;
//             }
//         }
//     }
//
//     return dist == INT_MAX ? -1 : dist;
// }

// Driver function
int main(){
    // int arr[] = {1, 2, 3, 3};
    // int arr[] = {86,39,90,67,84,66,62};
    // int arr[] = {6, 15, 82, 8, 74, 59, 75, 83, 86, 36, 20, 39, 34, 60};
    int arr[] = {96 ,82 ,48 ,76 ,34 ,19 ,7 ,80 ,36 ,57 ,77 ,34 ,19 ,35 ,5 ,57 ,16 ,66 ,42, 62 ,89 ,19 ,60 ,19 ,25 ,16 ,20 ,51 ,77 ,75 ,12 ,73 ,8 ,11 ,100 ,93 ,81 ,58 ,72 ,17 ,14 ,48 ,2 ,33 ,82 ,6 ,41 ,49 ,72 ,34 ,10 ,12 ,53 ,21 ,30 ,77 ,36, 49, 79, 13, 75, 42};
    int n = sizeof(arr)/sizeof(arr[0]);

    cout << minDist(arr, n, 36, 33) << endl;

    return 0;
}
/*
96 82 48 76 34 19 7 80 36 57 77 34 19 35 5 57 16 66 42 62 89 19 60 19 25 16 20 51 77 75 12 73 8 11 100 93 81 58 72 17 14 48 2 33 82 6 41 49 72 34 10 12 53 21 30 77 36 49 79 13 75 42
36 33
*/
