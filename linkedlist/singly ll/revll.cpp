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
    curr->next = nullptr;  // Set the new node's next to nullptr

    if (*head == nullptr) {
        // If the list is empty, make the new node the head
        *head = curr;
    } else {
        // Find the last node and update its next pointer
        node* last = *head;
        while (last->next != nullptr) {
            last = last->next;
        }
        last->next = curr;
    }
}

int delete1(node** head){
    if(*head==NULL){
        cout<<"underflow"<<endl;
        return -1;
    }
    else{
        int t=(*head)->val;
        if((*head)->next==NULL){
            *head=NULL;
        }
        else{
            node* temp=(*head)->next;
            (*head)->next=NULL;
            *head=temp;
        }
        return t;
    }
}

void display(node* head) {
    node* curr = head;
    if (head == NULL) {
        cout << "underflow" << endl;
    } else {
        while (curr != NULL) {
            cout << curr->val;
            if (curr->next) {
                cout << "->";
            }
            curr = curr->next;
        }
        cout<<endl;
    }
}

int getlen(node* head) {
    int cnt = 0;
    while (head) {
        cnt++;
        head = head->next;
    }
    return cnt;
}
node* revll(node** head){
    node* prev=NULL;
    node* fwd=NULL;
    node* curr=*head;
    while(curr){
        fwd=curr->next;
        curr->next=prev;
        prev=curr;
        curr=fwd;
    }
    *head=prev;
    return *head;
}
int main() {
    node* head = NULL;
    insert(&head, 1);
    insert(&head, 2);
    insert(&head, 3);
    insert(&head, 4);
    insert(&head, 5);
    insert(&head, 6);
    insert(&head, 7);
    //delete1(&head);//delete the first element
    display(head);
    revll(&head);
    display(head);

    cout<<"\nlength of linked list:"<<getlen(head)<<endl;
    return 0;
}
