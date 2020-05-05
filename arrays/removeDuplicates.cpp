// remove duplicates from an array in O(1) space
#include <bits/stdc++.h>
using namespace std;

// t : O(n)
// s : O(1)
int removeDuplicates(vector<int> &nums){
    if(nums.empty())   return 0;

    int n = nums.size()-1;

    int temp = nums[0], uniqueLength = 1;
    int prevIndex = 0, currIndex = 1;
    bool flag = false, endReached = false;

    // removing the duplicates
    while(currIndex <= n){
        while(nums[prevIndex] == nums[currIndex]){

            currIndex++;
            if(currIndex > n){
                endReached = true;
                break;
            }
        }

        if(endReached)  break;

        prevIndex++;
        nums[prevIndex] = nums[currIndex];
        uniqueLength++;
    }

    return uniqueLength;
}

// light-weight solution
// t : O(n)
// s : O(1)
int removeDuplicates_2(vector<int> &arr){
    int index = 0;

    // hm yaha pr hr value pr iterate kra rhe h
    for(auto value:arr){
        // 2 conditions lagyenge
        // 1st : 0th index ki value ussi ki place pr save kr denge
        /* 2nd : kyuki given array sorted h, agar hm ith index pr h, aor isski repeateed values h toh ye toh pkka h ki wo continuity me rhenge
        mtlb, hm array ko traverse krte jayenge aor jb hme ith value se bdi value milegi, toh hm usse ith ki next index pr insert kr denge, kyuki agr ith ki values repeating h, toh woh obviously next index pr he hongi( continuity me )
        hm yhi technique hr value ke liye lgayenge
        */
        if(index < 1 || arr[index - 1] < num){
            arr[index] = num;
            index++;
        }
    }
}

// Driver function
int main(){
    vector<int> arr({1});
    cout << "\n" << removeDuplicates(arr) << endl;
    return 0;
}
