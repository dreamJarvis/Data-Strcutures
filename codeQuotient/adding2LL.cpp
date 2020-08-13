// add 2 ilnked list
#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* next;
};

Node *createNode(int k){
    Node *newNode = new Node();
    newNode->data = k;
    newNode->next = NULL;
    return newNode;
}

void displayList(Node *head){
    while(head){
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

// O(n)
struct Node* addListNumbers(struct Node* head1, struct Node* head2) {
	int sum = 0;

  	int carry = 0;
    Node *result = head1;
    Node *prev = NULL;
  	while(head1 != NULL && head2 != NULL){
    	int a1 = head1->data;
        int a2 = head2->data;

      	int temp = a1 + a2 + carry;
        head1->data = temp%10;
        carry = temp/10;

        prev = head1;
      	head1 = head1->next;
      	head2 = head2->next;
    }

  	while(head1){
      int temp = head1->data + carry;
      head1->data = temp%10;
      carry = temp/10;
      prev = head1;
      head1 = head1->next;
    }

  	while(head2){
    	int temp = head2->data + carry;
        prev->next = createNode(temp%10);
        prev = prev->next;
        carry = temp/10;
        head2 = head2->next;
    }

    if(carry)
      prev->next = createNode(carry);

  	return result;
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

// O(n)
Node *reverseLL(Node *node, Node *&root){
    if (node == NULL)
        return NULL;

    if (node->next == NULL) {
        root = node;
        return node;
    }

    Node* node1 = reverseLL(node->next, root);
    node1->next = node;
    node->next = NULL;
    return node;
}

int main(){
    int n ;
    cin >> n;

    while(n--){
        int s1, s2;

        Node *head1 = NULL;
        Node *head2 = NULL;

        Node *tail1 = NULL;
        Node *tail2 = NULL;

        cin >> s1;
        int data;
        while(s1--){
            cin >> data;
            tail1 = insertAtFront(tail1, data);

            if(head1 == NULL)
                head1 = tail1;
        }

        cin >> s2;
        while(s2--){
            cin >> data;
            tail2 = insertAtFront(tail2, data);

            if(head2 == NULL)
                head2 = tail2;
        }

        head1 = addListNumbers(head1, head2);
        reverseLL(head1, head1);

        displayList(head1);
    }

    return 0;
}
