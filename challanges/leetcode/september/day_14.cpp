/*
    39. Combination Sum
*/
#include <iostream>
#include <vector>
using namespace std;

// void combinationSum(vector<int>& candidates, int &index, int target, string ans, int sum) {
//     if(index >= candidates.size()-1){
//         return ;
//     }
//
//     if(sum == target){
//         cout << ans << endl;
//         // ans = "";
//         // sum = 0;
//         return ;
//     }
//
//     if(sum > target){
//         return ;
//     }
//
//     int first = candidates[index];
//     string temp = ans += to_string(first);
//     sum += first;
//     combinationSum(candidates, index, target, temp, sum);
//     index++;
//     combinationSum(candidates, index, target, temp, sum);
// }

void combinationSum(vector<int>& candidates, int target, int index, string ans, int sum) {
    if(index > candidates.size()-1)
        return ;

    if(sum == target){
        cout << ans << endl;
        return ;
    }

    cout << ans << endl;
    combinationSum(candidates, target, index, ans, sum);

    int num = candidates[index];
    ans += to_string(num);
    sum += num;

    cout << ans << endl;
    combinationSum(candidates, target, index+=1, ans, sum);
}

// Driver function
int main(){
    vector<int> arr({2, 3, 6, 7});
    int target = 7;

    int index = 0;
    combinationSum(arr, target, index, "", 0);

    return 0;
}
