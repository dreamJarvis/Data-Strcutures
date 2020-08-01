// 84. Largest Rectangle in Histogram
#include <bits/stdc++.h>
using namespace std;

int largestRectangleArea(vector<int>& arr) {
    int n = arr.size();

    stack<int> s;
    int largestArea = 0;

    for(int i = 0; i < n; i++){

        while(!s.empty() && arr[i] <= arr[s.top()] ){

            cout << s.top() << "__" << arr[s.top()] << " __ " << i << endl;

            int tp = s.top();
            s.pop();

            int area = 0;
            if(s.empty()){
                area = arr[i]*(i+1);
                // cout << area << endl;
            }
            else{
                area = arr[s.top()] * (i - tp + 1);
            }

            cout << area << endl;
            // cout << i << " -- " << s.top() << endl;

            largestArea = max(largestArea, area);
        }

        // cout << i << endl;
        s.push(i);
    }

    largestArea = max(largestArea, arr[s.top()]);
    int i = s.top();
    while(!s.empty()){
        
    }

    return largestArea;
}

// Driver function
int main(){
    // vector<int> arr({2, 1, 5, 6, 2, 3});
    // vector<int> arr({1, 1});
    vector<int> arr({2, 4});

    cout << largestRectangleArea(arr) << endl;

    return 0;
}
