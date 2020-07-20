#include <bits/stdc++.h>
using namespace std;

// void printSubArrays(vector<int> arr, int start, int end, vector<int> ans){
//     if(end == arr.size()){
//         for(auto i:ans)
//             cout << i << ", ";
//         cout <<"\n\n";
//
//         ans.clear();
//
//         return;
//     }
//
//     if(start > end)
//         printSubArrays(arr, 0, end+1, ans);
//
//     for(int i = start; i <= end; i++)
//         ans.push_back(arr[i]);
//
//     printSubArrays(arr, start+1, end, ans);
// }

// C++ code to print all possible subarrays
// for given array using recursion

#include <iostream>
# include <vector>
using namespace std;

// Recursive function to print all possible subarrays
// for given array
vector<int> ans;
void printSubArrays(vector<int> arr, int start, int end){
	if (end == arr.size())
		return;

	else if (start > end)
		printSubArrays(arr, 0, end + 1);

	else {
        int x=0;
		for (int i = start; i <= end; i++){
            x |= arr[i];
		}
        ans.push_back(x);

		printSubArrays(arr, start + 1, end);
	}

	return;
}

int main(){
    vector<int> arr = {1, 2, 7};
    printSubArrays(arr, 0, 0);

    for(auto i:ans)
        cout << i << ", ";
    cout << endl;


    return 0;
}
