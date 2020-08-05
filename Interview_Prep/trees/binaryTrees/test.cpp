#include <bits/stdc++.h>
using namespace std;

struct Node{
    int key;
    Node *left, *right;

    Node(int x){
        key = x;
        left = right = nullptr;
    }
};

// insert
void insert(Node *root, int key){
    queue<Node *> q;
    q.push(root);

    Node *temp = nullptr;
    while(!q.empty()){
        temp = q.front();
        q.pop();

        if(!temp->left){
            temp->left = new Node(key);
            return ;
        }
        else
            q.push(temp->left);

        if(!temp->right){
            temp->right = new Node(key);
            return ;
        }
        else
            q.push(temp->right);
    }
}

// deletion of nodes
void deleteLastNode(Node *root, Node *lastNode){
    queue<Node *> q;
    q.push(root);

    Node *temp;
    while(!q.empty()){
        temp = q.front();
        q.pop();

        if(temp == lastNode){
            temp = nullptr;
            delete lastNode;
            return ;
        }

        if(temp->left){
            if(temp->left == lastNode){
                temp->left = nullptr;
                delete lastNode;
                return ;
            }
            else
                q.push(temp->left);
        }

        if(temp->right){
            if(temp->right == lastNode){
                temp->right = nullptr;
                delete lastNode;
                return ;
            }
            else
                q.push(temp->right);
        }
    }
}

Node *deletion(Node *root, int key){
    if(!root)   return nullptr;

    if(root->left == nullptr && root->right == nullptr){
        // if the tree has only one node,
        if(root->key == key)                // and we have to delete that node
            return nullptr;
        else
            return root;                    // and we don't have to delete that node
    }

    queue<Node *> q;
    q.push(root);

    Node *temp = nullptr;
    Node *keyNode = nullptr;
    while(!q.empty()){
        temp = q.front();
        q.pop();

        if(temp->key == key){
            keyNode = temp;
        }

        if(temp->left)
            q.push(temp->left);

        if(temp->right)
            q.push(temp->right);
    }

    if(keyNode){
        int val = temp->key;
        deleteLastNode(root, temp);
        keyNode->key = val;
    }

    return root;
}

/* Inorder traversal of a binary tree*/
void inorder(Node* temp){
	if (!temp) return;

	inorder(temp->left);
	cout << temp->key << " ";
	inorder(temp->right);
}

// Driver function
int main(){
    Node* root = new Node(10);                      // initializing the root
    vector<int> arr({11, 9, 7, 12, 15, 8});

    // inserting elements in tree
    for(auto i:arr)
        insert(root, i);


    inorder(root);
    cout << "\n\n";

    deletion(root, 12);
    inorder(root);
    cout << "\n\n";

    deletion(root, 11);
    inorder(root);
    cout << "\n\n";

    return 0;
}
