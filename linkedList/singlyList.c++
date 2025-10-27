#include<iostream>
#include<map>
using namespace std;

class LinkedList{
    
    public:
    int data;
    LinkedList* next;
    LinkedList(int data){
        this->data=data;
        this->next=NULL;
    }
    ~LinkedList(){
        int value=this->data;
        if(this->next!=NULL){
            delete next;
            this->next=NULL;
        }
        cout<<"Memory is free for node with data "<<value<<endl;
    }
};


void insertAtHead(LinkedList*  &head,int data){
    LinkedList* temp=new LinkedList(data);
    if(head==NULL){
        head=temp;
        return;
    }
    else {
        temp->next=head;
        head=temp;
    }
}

void PrintList(LinkedList* head){
    LinkedList * temp=head;
    while(temp !=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

void InsertAtTail(LinkedList* &tail,int data){
    LinkedList* temp=new LinkedList(data);
    tail->next=temp;
    tail=temp;
}


void insertAtMiddleWithData(LinkedList* &head,LinkedList* &tail,int data,int value){
    if(head->data== value){
        insertAtHead(head,data);
        return;
    }
    LinkedList*temp=head;
    while(temp->next!=NULL && temp->data!=value){
        temp=temp->next;
    }
    if(temp->next==NULL){
        InsertAtTail(tail,data);
        return;
    }
    LinkedList* nodeToInsert=new LinkedList(data);
    nodeToInsert->next=temp->next;
    temp->next=nodeToInsert;
}



void insertAtMiddle(LinkedList* &head,LinkedList* &tail,int data,int position){
    if(position==1){
        insertAtHead(head,data);
        return;
    }
    LinkedList* temp=head;
    int count=1;
    while(count<position-1){
        temp=temp->next;
        count++;
    };
    if(temp->next==NULL){
        InsertAtTail(tail,data);
        return;
    }
    LinkedList* nodeToInsert=new LinkedList(data);
    nodeToInsert->next=temp->next;
    temp->next=nodeToInsert;
}


void ReverseList(LinkedList* head){
    LinkedList* temp=head;
    LinkedList* prev=NULL;
    LinkedList* next=NULL;
    while(temp!=NULL){
        next=temp->next;
        temp->next=prev;
        prev=temp;
        temp=next;
    }
    PrintList(prev);
}  
void DeleteNode(LinkedList* &head,LinkedList* &tail, int value){
    LinkedList* temp=head;
    if(temp->data==value){
        head=head->next;
        temp->next=NULL;
        delete temp;
    }
    else{
        LinkedList* prev=NULL;
        while(temp->next!=NULL && temp->data!=value){
            prev=temp;
            temp=temp->next;
        }
        if(temp->next==NULL && temp->data==value){
            tail=prev;
        }
        prev->next=temp->next;
        temp->next=NULL;
        delete temp;
    }
}


void DeleteDuplicate(LinkedList*& head) {
    LinkedList* curr = head;

    while (curr != NULL) {
        LinkedList* temp = curr;
        // Check all nodes after curr
        while (temp->next != NULL) {
            if (temp->next->data == curr->data) {
                // Duplicate found -> delete it
                LinkedList* nodeToDelete = temp->next;
                temp->next = temp->next->next; // unlink the duplicate
                delete nodeToDelete;           // free memory
            } else {
                temp = temp->next; // move forward
            }
        }
        curr = curr->next; // move to next unique node
    }

    PrintList(head);
}

int main(){
    LinkedList* node=new LinkedList(10);
    LinkedList* head=node;
    LinkedList* tail=node;
    // PrintList(head);
    // insertAtHead(head,20);
    // PrintList(head);
    // insertAtHead(tail,30);
    // PrintList(head);
    InsertAtTail(tail,2);
    InsertAtTail(tail,30);
    // PrintList(head);
    // insertAtMiddle(head,tail,25,2);
    // PrintList(head);
    // insertAtMiddle(head,tail,35,1);
    // PrintList(head);
    // insertAtMiddle(head,tail,40,6);
    // PrintList(head);
    
    // insertAtMiddleWithData(head,tail,45,40);
    // PrintList(head);
    // insertAtMiddleWithData(head,tail,1,35);
    // PrintList(head);
    // DeleteNode(head,tail,10);
    // PrintList(head);
    // DeleteNode(head,tail,1);
    // PrintList(head);
    // DeleteNode(head,tail,45);
    InsertAtTail(tail,5);
    InsertAtTail(tail,10);
    InsertAtTail(tail,5);
    PrintList(head);
    cout<<"Head: "<<head->data<<endl;
    cout<<"Tail: "<<tail->data<<endl;
    // DeleteDuplicate(head);
// PrintList(head);
    // ReverseList(head);   
    return 0;
}