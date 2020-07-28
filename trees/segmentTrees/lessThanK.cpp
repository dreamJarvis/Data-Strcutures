// Queries for elements greater than K in the given index range using Segment Tree
#include <bits/stdc++.h>
using namespace std;

// ======== performing queries ========== //
// performing queries on the qiven range
int query(vector<int> *tree, int index, int s, int e, int l, int r, int k){
    // out of bound
    if(r < s || l > e)
        return 0;

    // total overlap
    // query range completely lies in the segment Tree node
    if(s >= l && e <= r){
        // binary search to find the index of K
        int items = tree[index].size() - (lower_bound(tree[index].begin(), tree[index].end(), k) - tree[index].begin());

        return items;
    }

    // partially overlap
    // query range partially lies in the segment tree node
    int mid = (s + e)/2;
    return (
        query(tree, 2*index, s, mid, l, r, k) +
        query(tree, 2*index+1, mid+1, e, l, r, k)
    );
}

// function to perform queries : UTILITY function
void performQueries(vector<vector<int>> &q, vector<int> tree[], int n){
    for(auto i:q){
        cout << query(tree, 1, 0, n-1, i[0]-1, i[1]-1, i[2]) << endl;
    }
}

// ==========================  consturcting segment tree ======================== //
// merge 2 vectors , int an sorted way
vector<int> merge(vector<int> &v1, vector<int> &v2){
    // final vector to return
    vector<int> v;

    int i = 0, j = 0;
    while(i < v1.size() && j < v2.size()){
        if(v1[i] <= v2[j]){
            v.push_back(v1[i]);
            i++;
        }
        else {
            v.push_back(v2[j]);
            j++;
        }
    }

    // the remaining elements are added to the resultant vector
    while(i < v1.size()){
        v.push_back(v1[i++]);
    }

    while(j < v2.size()){
        v.push_back(v2[j++]);
    }

    return v;
}

// build segment tree : UTILITY function
void buildTree(vector<int> *tree, vector<int> &arr, int index, int s, int e){
    if(s == e){
        tree[index].push_back(arr[s]);
        return ;
    }

    int mid = (s+e)/2;
    buildTree(tree, arr, 2*index, s, mid);                  // we are given 1 bases indexing
    buildTree(tree, arr, 2*index+1, mid+1, e);

    // storing the final vector after merging the tow of its sorted child
    tree[index] = merge(tree[2*index], tree[2*index+1]);
}

// Driver function
int main(){
    vector<int> arr({7, 3, 9, 13, 5, 4});
    vector<vector<int>> query({
        {1, 4, 6},
        {2, 6, 8}
    });

    int n = arr.size();
    vector<int> tree[4*n+1];            // segment tree

    // consturct a segment Tree
    buildTree(tree, arr, 1, 0, n-1);

    // performing all the given queries
    performQueries(query, tree, n);

    return 0;
}
