#include "../cbALGO/trees/binarySearch_Trees/BST.h"

// find node
BstNode *find(BstNode *root, int val){
    if(root == nullptr) return nullptr;
    else if(root->data == val)  return root;
    else if(val < root->data)   return find(root->left, val);
    else    return find(root->right, val);
}

// to find the minimum in a bst
BstNode *findMin(BstNode *root){
    if(root == nullptr) return nullptr;

    if(root->left == nullptr and root->right == nullptr)
        return root;
    return findMin(root->left);
}

// function to find the inprder successor in a bst
// for balanced bst : (h = log(n)) .'. O(log(n))
BstNode *InorderSuccssor(BstNode *root, int value){
    BstNode *current = find(root, value);     // -----------  O(h)

    if(current == nullptr)  return nullptr;

    // case 1 : if right tree exists
    if(current->right != nullptr){
        return findMin(current->right);     // -------------- O(h)
    }
    else{
        // case 2 : right subtree doesn't exist : ---- O(h) ------------
        BstNode *successor = nullptr;
        BstNode *ancestor = root;
        while(ancestor != current){
            if(current->data < ancestor->data){
                successor = ancestor;
                ancestor = ancestor->left;
            }
            else
                ancestor = ancestor->right;
        }

        return successor;
    }
}

// Driver function
int main(){
    BstNode *root = nullptr;
    int tree[] = {15, 8, 5, 11, 10, 12, 20, 19, 25};

    for(auto val:tree){
        root = Insert(root, val);
    }

    // traversal
    PreOrder(root);
    cout << endl;

    cout << InorderSuccssor(root, 8)->data << endl;

    return 0;
}