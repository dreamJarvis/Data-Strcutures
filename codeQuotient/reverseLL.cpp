// reverse a linked list recursive approach
#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* next;
};

Node *head;

Node *createNode(int k){
    Node *newNode = new Node();
    newNode->data = k;
    newNode->next = NULL;
    return newNode;
}

Node *insertAtFront(Node *tail, int data){
    Node *newNode = createNode(data);
    if(tail == NULL){
        return newNode;
    }

    while(tail->next != NULL){
        tail = tail->next;
    }
    tail->next = newNode;
    return newNode;
}

void displayList(Node *head){
    while(head){
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

Node *reverseLL(Node *node){
    if (node == NULL)
        return NULL;

    if (node->next == NULL) {
        head = node;
        return node;
    }

    Node* node1 = reverseLL(node->next);
    node1->next = node;
    node->next = NULL;
    return node;
}

int main(){
    int t=0;
    cin >> t;

    while(t--){
        int n;
        cin >> n;

//         Node *head = NULL;

      	head = NULL;
        Node *tail = NULL;
        int data;
        while(n--){
            cin >> data;
            tail = insertAtFront(tail, data);

            if(head == NULL)
                head = tail;
        }
        reverseLL(head);
        displayList(head);
    }

    return 0;
}
