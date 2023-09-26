#include<iostream>
using namespace std;

struct Node {
    int val;
    struct Node* next;
};

typedef struct Node node;

void insert(node** head, int val) {
    node* curr = new node();
    curr->val = val;
    curr->next = nullptr;

    if (*head == nullptr) {
        *head = curr;
    } else {
        node* last = *head;
        while (last->next != nullptr) {
            last = last->next;
        }
        last->next = curr;
    }
}

int deleteFirstNode(node** head){
    if(*head == nullptr){
        cout << "underflow" << endl;
        return -1;
    } else {
        int val = (*head)->val;
        node* temp = (*head)->next;
        delete *head;
        *head = temp;
        return val;
    }
}

void display(node* head) {
    node* curr = head;
    if (head == nullptr) {
        cout << "underflow" << endl;
    } else {
        while (curr != nullptr) {
            cout << curr->val;
            if (curr->next) {
                cout << "->";
            }
            curr = curr->next;
        }
        cout << endl;
    }
}

int getLen(node* head) {
    int cnt = 0;
    while (head) {
        cnt++;
        head = head->next;
    }
    return cnt;
}

node* middle(node* head) {
    if (head == nullptr) {
        return nullptr;
    } else if (head->next == nullptr) {
        return head; // Return the single element as the middle
    } else {
        node* curr = head;
        int cnt = getLen(head);
        int middle = cnt / 2;
        for (int i = 0; i < middle; i++) {
            curr = curr->next;
        }
        return curr;
    }
}

int main() {
    node* head = nullptr;
    insert(&head, 1);
    insert(&head, 2);
    insert(&head, 3);
    insert(&head, 4);
    insert(&head, 5);
    display(head);

    node* middleNode = middle(head);
    if (middleNode != nullptr) {
        cout << "Middle Node: " << middleNode->val ;
        if(middleNode)cout<<"->";
        head = middleNode->next;
        display(head);
    } else {
        cout << "Empty list." << endl;
    }
    
    // Clean up: Delete all nodes
    while (head != nullptr) {
        deleteFirstNode(&head);
    }

    return 0;
}
