// given a ll with a loop, find the starting point of the loop
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int key;
    Node *next;
};

Node *newNode(int key){
    Node *temp = new Node();
    temp->key = key;
    temp->next = nullptr;
    return temp;
}

void printList(Node *head){
    while(head != nullptr){
        cout << head->key << " ";
        head = head->next;
    }
    cout << endl;
}

// function to detect and remove loop in a linked list that may contain loop
void detectAndRemoveLoop(Node *head){
    // if list is empty or has only one node without loop
    if(head == nullptr || head->next == nullptr)
        return ;

    Node *slow = head, *fast = head;

    // move slow and fast pointers move 1 and 2 steps ahead at a time
    slow = slow->next;
    fast = fast->next->next;

    // searching for loop using slow and fast pointers
    while(slow != fast){
        slow = slow->next;
        fast = fast->next->next;
    }

    // if loop does not exist
    if(slow != fast)    return ;

    // if loop exists, then have a ptr from head and a pointer from where the fast and slow ptr meets, then move both of these pointer ahead by one step, the point where they meet is the starting point of the loop
    Node *prev = nullptr;
    while(head != slow){
        prev = slow;
        head = head->next;
        slow = slow->next;
    }

    prev->next = nullptr;
}

// Driver function
int main(){
    Node* head = newNode(50);
    head->next = newNode(20);
    head->next->next = newNode(15);
    head->next->next->next = newNode(4);
    head->next->next->next->next = newNode(10);

    // Create a loop for testing
    head->next->next->next->next->next = head->next->next;

    detectAndRemoveLoop(head);

    printList(head);

    return 0;
}
