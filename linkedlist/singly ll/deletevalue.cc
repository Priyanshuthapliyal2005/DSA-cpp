#include<iostream>
using namespace std;
class Node{

    public:
        int data;
        Node* next;
        //constructor
        Node(int data){
            this->data=data;
            this->next=NULL;
        }
        //destructor
        ~Node(){
            int value=this->data;
            if(this->next!=NULL){
                delete next;
                this->next=NULL;
            }
            cout<<"memory is free for node with data: "<<value<<endl;
        }
};

void InsertAtHead(Node* &head,int d)
{
    //new node create
    Node* temp=new Node(d);
    temp->next=head;
    head=temp;
} 

void InsertAtTail(Node* &tail,int d){
    Node* temp=new Node(d);
    tail->next=temp;
    tail=temp;
}

void InserAtPosition(Node* &head,Node* &tail,int position,int d){
    //insert at start
    if(position==1){
        InsertAtHead(head,d);
        return;
    }
    Node* temp=head;
    int cnt=1;
    while(cnt<position-1){
        temp=temp->next;
        cnt++;
    }
    //inserta t last 
    if(temp->next==NULL){
        InsertAtTail(tail,d);
        return;
    }
    //creating a node for d
    Node* nodetoinsert=new Node(d);
    nodetoinsert->next=temp->next;
    temp->next=nodetoinsert;
}
void deleteNode(int position,Node* &head){
    if(position==1){
        Node* temp=head;
        //first
        head=head->next;
        temp->next=NULL;
        delete temp;
    }
    else{
        //middle&last
        Node* curr=head;
        Node* prev=NULL;

        int cnt=1;
        while(cnt<position)
        {
            prev=curr;
            curr=curr->next;
            cnt++;
        }
        prev->next=curr->next;
        curr->next=NULL;
        delete curr;
    }
}

void print(Node* &head){
    Node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}
int main()
{
    //created a new node
    Node* node1=new Node(10);
    //cout<<node1->data<<endl;
    //cout<<node1->next<<endl;

    //head pointed to node 1
    Node* head =node1;
    Node* tail=node1;
    print(head);

    InsertAtTail(tail,12);
    print(head);

    InsertAtTail(tail,15);
    print(head);
    
    InserAtPosition(head,tail,4,22);
    print(head);

    InserAtPosition(head,tail,1,2);
    print(head);

    cout<<"head:"<<head->data<<endl;
    cout<<"tail:"<<tail->data<<endl;

    deleteNode(5,head);
    print(head);

    cout<<"head:"<<head->data<<endl;
    cout<<"tail:"<<tail->data<<endl;

    return 0;
}