// C++ Program to find inorder successor. 
#include "../cbALGO/trees/binarySearch_Trees/BST.h"

// target node : jiska inorder successor print krna h
// next : inorder successor

// time complexity : ---- O(n) ----
void inorderSuccessor(BstNode *root, int target_node, int &next){ 
	// if root is null then return 
	if(!root)   return; 

	inorderSuccessor(root->right, target_node, next); 
	
	// if target node found then enter this condition 
	if(root->data == target_node) { 
		// this will be true to the last node in inorder traversal i.e., rightmost node. 
		if(next == -1) 
			cout << "inorder successor of " << root->data << " is: null" << endl; 
		else
			cout << "inorder successor of " << root->data << " is: " << next << endl; 
	} 
	next = root->data; 

	inorderSuccessor(root->left, target_node, next); 
} 

// Driver function
int main(){
    BstNode *root = nullptr;
    int tree[] = {15, 8, 5, 11, 10, 12, 20, 19, 25};

    for(auto val:tree){
        root = Insert(root, val);
    }

    int next = -1;
    inorderSuccessor(root, 8, next);

    return 0;
}
