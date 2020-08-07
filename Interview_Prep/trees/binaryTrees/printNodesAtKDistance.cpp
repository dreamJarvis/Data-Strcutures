// print Nodes at K distance
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

// O(n)
// values at the distance
void printkdistanceNode(map<int, list<Node *>> &nodesLvl, int targetLvl, int distance){
    if(targetLvl+distance < nodesLvl.size()){
        auto a = nodesLvl.find(targetLvl+distance);

        cout << "dist : " << targetLvl+distance << endl;
        for(auto i:a->second)
            cout << i->key << " ";
    }

    if(abs(distance-targetLvl)  < nodesLvl.size()){
        cout << "dist : " << targetLvl+distance << endl;

        auto b = nodesLvl.find(abs(distance-targetLvl));
        for(auto i:b->second)
            cout << i->key << " ";
    }

    return ;
}

// O(n)
// pushing value accoring to their level using oreorder traversal
void nodesAtLevel(Node *root, map<int, list<Node *>> &nodesLvl, Node *target, int &targetLvl){
    static int lvl = -1;

    if(!root)   return ;

    lvl++;
    nodesAtLevel(root->left, nodesLvl, target, targetLvl);

    // if it's not root, then push it
    if(root != target){
        if(nodesLvl.count(lvl)){
            auto f = nodesLvl.find(lvl);
            f->second.push_back(root);
        }
        else{
            list<Node *> lst;
            lst.push_back(root);
            nodesLvl.insert(make_pair(lvl, lst));
        }
    }
    else if(root == target){
        targetLvl = lvl;
    }

    nodesAtLevel(root->right, nodesLvl, target, targetLvl);
    lvl--;
}

void inorderTraversal(Node *root){
    if(!root)   return;

    inorderTraversal(root->left);
    cout << root->key << " ";
    inorderTraversal(root->right);
}

// Driver function
int main(){
    // Node * root = new Node(20);
    // root->left = new Node(8);
    // root->right = new Node(22);
    // root->left->left = new Node(4);
    // root->left->right = new Node(12);
    // root->left->right->left = new Node(10);
    // root->left->right->right = new Node(14);

    Node *root = new Node(0);
    root->left = new Node(1);
    root->right = new Node(3);
    root->left->right = new Node(2);
    // root->right->right->left = new Node(4);

    inorderTraversal(root);
    cout << "\n\n";

    // Node * target = root->left->right;
    Node * target = root->left;
    int distance = 2;


    map<int, list<Node *>> nodesLvl;
    int targetLvl = -1;

    nodesAtLevel(root, nodesLvl, target, targetLvl);

    for(auto i:nodesLvl){
        cout << i.first << " : ";
        for(auto j:i.second)
            cout << j->key << ", ";
        cout << endl;
    }

    cout << "nodes : ";
    printkdistanceNode(nodesLvl, targetLvl, distance);

    return 0;
}
