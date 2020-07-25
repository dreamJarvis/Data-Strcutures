#include <bits/stdc++.h>
using namespace std;

// utility function to get the middle index from the corner indexes
int getMid(int s, int e) { return s + (e - s)/2; }

/*
    recursive function to update the nodes which have the given index in their range
    i --> index of the element to be updated
    diff --> value to be added to all the nodes which have i in range
*/
void updateValueUtil(int *st, int ss, int se, int i, int diff, int si){
    // base case : if input index lies outside the range of this segment
    if(i < ss || i > se)
        return ;

    /* if the input index is in range of this node,
    then update the value of the node and its childern */
    st[si] = st[si] + diff;

    // issme ye as a base condition, ki jb hm segment trees ke leaf nodes pr poch jayenge , tb aage recursion nhi krenge
    if(se != ss){
        int mid = getMid(ss, se);
        updateValueUtil(st, ss, mid, i, diff, 2*si+1);
        updateValueUtil(st, mid+1, se, i, diff, 2*si+2);
    }
}

// update a value in input array and segment treee
void updateValue(int arr[], int *st, int n, int i, int new_val){
    // check for erroneous input index
    if(i < 0 || i > n-1){
        cout << "Invalid Input";
        return ;
    }

    // get the difference between new value and old value
    int diff = new_val - arr[i];

    // update the value in array
    arr[i] = new_val;

    // update the values of the nodes in the segment tree
    updateValueUtil(st, 0, n-1, i, diff, 0);
}

/*
A recursive function to get the sum of values in the given range of the array. The following are parameters for this function

    st --> Pointer to segment tree
    si --> Index of current node in the segment tree.
        Initially 0 is pass as root is always at 0
    ss & se --> starting and ending indexes of the segment
        represented by current node, i.e. st[si]
    qs & qe --> starting and ending indexes of query range
*/
int getSumUtil(int *st, int ss, int se, int qs, int qe, int si){
    // if the given range fully overlaps the current range, then we add sum upto this range
    if(qs <= ss && qe >= se)
        return st[si];

    // no overlaps btw the current range and given range
    if(se < qs || ss > qe)
        return 0;

    // partial overlapping btw the given range and the current range
    int mid = getMid(ss, se);
    return (getSumUtil(st, ss, mid, qs, qe, 2*si+1) + getSumUtil(st, mid+1, se, qs, qe, 2*si+2));
}

//return sum of elements in range from index qs (query start) to qe (query end)
int getSum(int *st, int n, int qs, int qe){
    // check for erroneous input values
    if(qs < 0 || qe > n-1){
        cout << "Invalid Input";
        return -1;
    }

    return getSumUtil(st, 0, n-1, qs, qe, 0);
}

// a recursive function that constructs segment Tree for array[ss...se].
// si -- index of current node in segment tree
// st -- pointer to segment tree
int constructionSTUtil(int arr[], int ss, int se, int *st, int si){
    // if there is one element in array, store it in the current node of segment tree and return
    if(ss == se){
        st[si] = arr[ss];
        return arr[ss];
    }

    int mid = getMid(ss, se);
    st[si] =    constructionSTUtil(arr, ss, mid, st, si*2+1) +
                constructionSTUtil(arr, mid+1, se, st, si*2+2);

    return st[si];
}

/*
To construct segment tree from given array,
This function allocates memory for segment tree
and calls constructionsUTIL() to fill the allocated memory
*/
int  *constructionST(int arr[], int n){
    //** allocate memory for the segment tree

    // height of the segment tree
    int x = (int)(ceil(log2(n)));

    // maximize size of segment tree
    int maxSize = 2*(int)pow(2, x) - 1;

    // allocate memory
    int *st = new int[maxSize];

    // fill the allocated memory st
    constructionSTUtil(arr, 0, n-1, st, 0);

    // return the constructed segment tree
    return st;
}

// Driver function
int main(){
    int arr[] = {1, 3, 5, 7, 9, 11};
    int n = sizeof(arr)/sizeof(arr[0]);

    // build segment tree from the given array
    int *st = constructionST(arr, n);

    // print the sum of values in array in the given range
    cout << "Sum of values in the given range = " << getSum(st, n, 1, 3) << endl;

    // update : set arr[i] = value, and update corresponding segment tree
    updateValue(arr, st, n, 1, 10);

    // find sum after the value is updated
    cout << "Updated sum of values in given range = " << getSum(st, n, 1, 3) << endl;

    return 0;
}
