#include "../cbALGO/trees/binarySearch_Trees/BST.h"

// to print the Preorder successor of the given node
BstNode *preorderSuccessor(BstNode *root, int a, int &prev){
    if(root == nullptr) 
        return root;

    if(prev == a){
        cout << root->data << " ";
        prev = root->data;
        return root;
    }

    BstNode *leftBST = preorderSuccessor(root->left, a, prev=root->data);
    BstNode *rightBST = preorderSuccessor(root->right, a, prev);

    if(leftBST == nullptr and rightBST == nullptr)
        return root;

    return leftBST != nullptr ? leftBST : rightBST;
}

// Driver function
int main(){
    BstNode *root = nullptr;
    int tree[] = {15, 8, 5, 11, 10, 12, 20, 19, 25};

    for(auto val:tree){
        root = Insert(root, val);
    }


    int minVal = -1;
    BstNode *result = preorderSuccessor(root, 20, minVal);
    cout << endl;
    
    return 0;
}