// 84. Largest Rectangle in Histogram
#include <bits/stdc++.h>
using namespace std;

// O(n)
int largestRectangleArea(vector<int>& arr) {
    int n = arr.size();
    stack<int> s;
    int maxHistogramArea = 0;
    int i = 0;

    for(; i < n; i++){
        while(!s.empty() && arr[s.top()] > arr[i]){
            int tp = s.top();
            s.pop();

            int area = arr[tp] * (s.empty() ? i : (i - s.top() - 1));
            maxHistogramArea = max(maxHistogramArea, area);
        }

        s.push(i);
    }

    while(!s.empty()){
        int tp = s.top();
        s.pop();

        int area = arr[tp] * (s.empty() ? i : (i - s.top() - 1));
        maxHistogramArea = max(maxHistogramArea, area);
    }

    return maxHistogramArea;
}

// Driver function
int main(){
    // vector<int> arr({2, 1, 5, 6, 2, 3});
    // vector<int> arr({1, 1});
    // vector<int> arr({1});
    // vector<int> arr({9, 0});
    vector<int> arr({2, 4});

    cout << largestRectangleArea(arr) << endl;

    return 0;
}
