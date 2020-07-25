// given an array of intergers , and an array of queries, find the min in each of those queries
#include <bits/stdc++.h>
using namespace std;

// updation
// tc : O(log(n)
void updateValueUtil(   vector<int> arr, vector<int> &segmentTree,
                        int ss, int se, int si, int index, int value
){
    if(index < ss || index > se)
        return ;

    segmentTree[si] = min(value, segmentTree[si]);
    if(se != ss){
        int mid = (ss + (se - ss)/2);
        updateValueUtil(arr, segmentTree, ss, mid, 2*si+1, index, value);
        updateValueUtil(arr, segmentTree, mid+1, se, 2*si+2, index, value);
    }

    return ;
}

// update value in the tree
void updateValue(   vector<int> arr, vector<int> &segmentTree,
                    int index, int value
){
    int n = arr.size();

    index--;
    if(index < 0 || index > n-1){
        cout << "Invalid" << endl;
        return ;
    }

    // int minVal =
    arr[index] = value;
    updateValueUtil(arr, segmentTree, 0, n-1, 0, index, value);
}

// finding min in range
// tc : O(log(n))
int minRangeQueryUtil(  vector<int> arr, vector<int> segmentTree,
                        int ss, int se, int qs, int qe, int si
){
    // total overlap
    if(qs <= ss && qe >= se)
        return segmentTree[si];

    // no overlop
    if(qs > se || qe < ss)
        return INT_MAX;

    // partial overlap
    int mid = (ss + (se - ss)/2);
    return min(
        minRangeQueryUtil(arr, segmentTree, ss, mid, qs, qe, 2*si+1),
        minRangeQueryUtil(arr, segmentTree, mid+1, se, qs, qe, 2*si+2)
    );
}

int minRangeQuery(vector<int> arr, vector<int> segmentTree, int qs, int qe){
    qs--;
    qe--;

    int n = arr.size();
    if(qs < 0 || qe > n)
        return INT_MAX;

    return minRangeQueryUtil(arr, segmentTree, 0, n-1, qs, qe, 0);
}

// constructing segment tree
// tc : O(n), n -> size of segment tree
int constructionSTUtil(vector<int> arr, vector<int> &segmentTree, int ss, int se, int si){
    if(se == ss){
        segmentTree[si] = arr[ss];
        return arr[ss];
    }

    int mid = (ss + (se - ss)/2);   // to avoid overflow
    segmentTree[si] = min(
        constructionSTUtil(arr, segmentTree, ss, mid, 2*si+1),
        constructionSTUtil(arr, segmentTree, mid+1, se, 2*si+2)
    );

    return segmentTree[si];
}

void constructionST(vector<int> arr, vector<int> &segmentTree){
    int n = arr.size();

    // height of the tree
    int height = (int)(ceil(log2(n)));
    int sizeOfST = 2*(int)pow(2, height) - 1;

    vector<int> temp(sizeOfST, INT_MAX);
    segmentTree = temp;
    constructionSTUtil(arr, segmentTree, 0, n-1, 0);
    return ;
}

// Driver function
int main(){
    vector<int> arr({12, 3, 5, 7, 23, 11, 12, 6});
    vector<int> segmentTree;

    // constructing segment tree
    constructionST(arr, segmentTree);

    cout << minRangeQuery(arr, segmentTree, 3, 5) << endl;

    // to disply segment tree before upadtion
    // for(auto i:segmentTree)
    //     cout << i << ", ";
    // cout << endl;

    updateValue(arr, segmentTree, 2, 1);

    // to disply segment tree after upadtion
    // for(auto i:segmentTree)
    //     cout << i << ", ";
    // cout << endl;

    cout << minRangeQuery(arr, segmentTree, 1, 4) << endl;

    return 0;
}
