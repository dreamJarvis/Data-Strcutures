// sum of given range
#include <bits/stdc++.h>
using namespace std;

// ------------------------------------ using Brute Force ---------------------------
// query sum: O(Q*N), (Q - number of queries)
// update : O(1)
class SumOfGivenRangeI{
    vector<int> arr;
    int n;
public:
    SumOfGivenRangeI(const vector<int> arr){
        this->arr = arr;
        this->n = arr.size();
    }

    // range sum
    int querySum(int l, int r);
    void update(int index, int value);
    void display();
};

// returning sum of the query
int SumOfGivenRangeI::querySum(int l, int r){
    int sum=0;
    for(int i=l-1; i <=r-1; i++)
        sum += arr[i];
    return sum;
}

// updating of query
// tc : O(1)
void SumOfGivenRangeI::update(int index, int value){
    if(index-1 >= 0 && index-1 < n)
        arr[index-1] = value;
    else
        cout << "Invalid index" << endl;
}

void SumOfGivenRangeI::display(){
    for(auto i:arr)
        cout << i << ", ";
    cout << endl;
}


//------------------------------- Using Efficient Method ------------------------------
// query sum : O(N)
// update : O(N*Q), (Q - number of queries)
class SumOfGivenRangeII{
    vector<int> originalArr;
    vector<int> rangeQueryArr;
    int n;
public:
    SumOfGivenRangeII(vector<int> arr){
        this->originalArr = arr;
        this->n = arr.size();

        vector<int> temp(n, 0);
        temp[0] = originalArr[0];
        for(int i = 1; i < n; i++)
            temp[i] += (temp[i-1] + originalArr[i]);

        this->rangeQueryArr = temp;
    }

    int querySum(int l, int r);
    void update(int index, int value);
    void display();
};

int SumOfGivenRangeII::querySum(int l, int r){
    if(l>=0 && r < n)
        return (l-2 >= 0 ? (rangeQueryArr[r-1] - rangeQueryArr[l-2]) : rangeQueryArr[r-1] );
    return -1;
}

void SumOfGivenRangeII::update(int index, int value){
    int diff = value - originalArr[index-1];
    originalArr[index-1] = value;

    if(diff >= 0){
        for(int i = index-1; i < n; i++){
            rangeQueryArr[i] += diff;
        }
    }
    else{
        for(int i = index-1; i < n; i++){
            rangeQueryArr[i] -= diff;
        }
    }
}

void SumOfGivenRangeII::display(){
    for(auto i:originalArr)
        cout << i << ", ";
    cout << endl;
}

// Segment Tree aprroach
class SumOfGivenRangeIII{
    vector<int> originalArr;
    vector<int> segmentTree;

public:
    // contruction of segment tree
    SumOfGivenRangeIII(vector<int> arr){
        
    }
};

// Driver function
int main(){
    // vector<int> arr({1,  3, 5, 7, 9, 11});
    // SumOfGivenRangeI obj(arr);
    //
    // cout << obj.querySum(1, 3) << endl;
    // obj.update(2, 10);
    // obj.display();
    // cout << obj.querySum(1, 3) << endl;

    // vector<int> arr({1,  3, 5, 7, 9, 11});
    // SumOfGivenRangeII obj(arr);
    //
    // cout << obj.querySum(1, 3) << endl;
    // obj.update(2, 10);
    // obj.display();
    // cout << obj.querySum(1, 3) << endl;

    return 0;
}
