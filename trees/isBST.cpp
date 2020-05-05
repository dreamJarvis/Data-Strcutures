#include <bits/stdc++.h>
using namespace std;

struct Node{
	int data;
	Node *left, *right;
};

Node *newNode(int data){
	Node *node = new Node();
	node->data = data;
    node->left = nullptr;
	node->right = nullptr;
	return node;
}

bool isBST(Node *root, int leftRange = INT_MIN, int rightRange = INT_MAX){
    if(root == nullptr)
        return true;

    bool leftBST = isBST(root->left, leftRange, root->data);
    bool rightBST = isBST(root->right, root->data, rightRange);

    if(
        leftBST and
        rightBST and
        root->data > leftRange and root->data < rightRange
    ){
        return true;
    }
    else    return false;
}

// Driver function
int main(){
    Node *root = nullptr;
	root = newNode(20);
	root->left = newNode(15);
	root->right = newNode(22);
	root->left->left = newNode(13);
	root->left->right = newNode(17);
	root->left->left->left = newNode(12);
	root->right->left = newNode(21);
	root->right->right = newNode(25);
	root->right->right->left = newNode(23);

    cout << isBST(root) << endl;

    return 0;
}
