#include<iostream>
#include<stack>
using namespace std;

class Stack{
    private:
    int top;
    int size;
    int *arr;

    public:
    Stack(int size){
        this->size=size;
        arr=new int[size];
        top=-1;
    }

    void Push(int value){
        if(top==size-1){
            cout<<"Stack Overflow"<<endl;
        }
        else{
            top++;
            arr[top]=value;
        }
    }
    void Pop(){
        if(top==-1){
            cout<<"Stack Underflow"<<endl;
        }else{
            top--;
        }
    }
    int Top(){
        if(top>=0){
            return arr[top];
        }else{
            cout<<"Stack is empty"<<endl;
            return -1; // Indicating stack is empty
        }
    }
    bool isEmpty(){
        if(top==-1){
            return true;
        }
        else{
            return false;
        }
    }

};

class Node{
    public:
    int data;
    Node* next;
    public:
    Node(int value){
        this->data=value;
        this->next=nullptr;
    }

    ~Node(){
        int value=this->data;
        if(this->next!=nullptr){
            delete next;
            this->next=nullptr;
        }
        cout<<"Memory freed for node with value "<<value<<endl;
    }
};


void print(Node* head){
    if(head==nullptr){
        return;
    }
    cout<<head->data<<" ";
    print(head->next);
}

void Push(Node* &head,Node* &tail,int value){
    Node* temp=new Node(value);
    if(head==nullptr){
        head=temp;
        tail=temp;
        return;
    }
    tail->next=temp;
    tail=temp;
}

void Pop(Node* &head,Node* &tail){
    if(head==nullptr){
        cout<<"Stack Underflow"<<endl;
        return;
    }
    else if(head->next==nullptr){
        Node*temp=head;
        head=nullptr;
        delete temp;
        return;
    }
    else{
        Node* temp=head;
        while(temp->next->next!=nullptr){
            temp=temp->next;
            cout<<temp->data<<" ";
        }
        Node* nodeToDelete=tail;
        tail=temp;
        tail->next=nullptr;
        delete nodeToDelete;
    }
}

void Top(Node* &head,Node* &tail){
    if(head==nullptr){
        cout<<"Stack is empty"<<endl;
        return;
    }
    else{
        cout<<tail->data<<endl;
        return;
    }
}


bool isEmpty(Node* head){
    if(head==nullptr){
        return true;
    }
    else{
        return false;
    }
}



int main(){

    // stack<int>s;
    // s.push(1);
    // s.emplace(10);
    // s.push(2);
    // s.push(4);

    // while(!s.empty()){
    //     cout<<s.top()<<endl;
    //     s.pop();
    // }
    // Stack s(3);
    // s.Push(1);
    // s.Push(2);
    // s.Push(3);
    // // s.Push(4);
    // s.Pop();
    // cout<<s.Top()<<endl;
    // s.Pop();
    // cout<<s.Top()<<endl;

    // s.Pop();
    // if(s.isEmpty()){
    //     cout<<"Stack is empty"<<endl;
    // }
    // else{
    //     cout<<"Stack is not empty"<<endl;
    // }


    Node* head=new Node(1);
    Node* tail=head;
    Push(head,tail,2);
    Push(head,tail,3);
    Push(head,tail,4);
    Pop(head,tail);
    print(head);
    cout<<endl;
    cout<<"head: "<<head->data<<endl;
    cout<<"Tail: "<<tail->data<<endl;
    Pop(head,tail);
    Pop(head,tail);
    Pop(head,tail);
    
    
    Top(head,tail);
    if(isEmpty(head)){
        cout<<"Stack is empty"<<endl;
    }
    else{
        cout<<"Stack is not empty"<<endl;
    }
    return 0;
}