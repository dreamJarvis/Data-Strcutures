// To merge 2 bsts : O(1)
#include <bits/stdc++.h>
using namespace std;

// binary tree node structure
struct Node{
    int data;
    Node *left;
    Node *right;
};

Node *newNode(int data){
    Node *nNode = new Node();
    nNode->data = data;
    nNode->left = nNode->right = nullptr;
    return nNode;
}

void display(vector<int>&);

void inorder(Node *root, vector<int> &arr){
    if(root == nullptr)
        return ;

    inorder(root->left, arr);
    arr.push_back(root->data);
    inorder(root->right, arr);
}

void merge(vector<int> &arr1, vector<int> &arr2){
    int ptr_1=0, ptr_2=0, k=0;
    int n1 = arr1.size();
    int n2 = arr2.size();
    
    vector<int> result;
    while(ptr_1 < n1 or ptr_2 < n2){
        if(arr1[ptr_1] < arr2[ptr_2]){
            result.push_back(arr1[ptr_1]);
            ptr_1++;
        }
        else if(arr1[ptr_1] > arr2[ptr_2]){
            result.push_back(arr2[ptr_2]);
            ptr_2++;
        }
        k++;
    }

    while(ptr_1 < n1){
        result.push_back(arr1[ptr_1]);
        ptr_1++;
        k++;
    }

    while(ptr_2 < n2){
        result.push_back(arr1[ptr_2]);
        ptr_2++;
        k++;
    }    

    display(result);
}

void display(vector<int> &arr){
    for(auto value : arr)
        cout << value << " ";
    cout << endl;
}

// Driver function
int main(){
    Node *tree1 = nullptr;


    tree1 = newNode(10);
    tree1->left = newNode(5);
    tree1->right = newNode(20);
    tree1->left->left = newNode(3);
    tree1->left->right = newNode(6);
    tree1->right->left = newNode(12);

    Node *tree2 = nullptr;

    tree2 = newNode(25);
    tree2->left = newNode(15);
    tree2->right = newNode(45);
    tree2->left->right = newNode(22);
    tree2->right->left = newNode(36);
    tree2->right->left->left = newNode(32);
    tree2->right->left->right = newNode(39);

    vector<int> inorder_1, inorder_2;
    inorder(tree1, inorder_1);
    inorder(tree1, inorder_2);

    merge(inorder_1, inorder_2);

    return 0;
}