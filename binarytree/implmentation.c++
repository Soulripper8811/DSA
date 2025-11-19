#include<iostream>
#include<queue>
#include<stack>
using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;
    Node(int data){
        this ->data=data;
        this->left=NULL;
        this->right=nullptr;
    }

};


void display(Node* root){
    if(root==NULL){
        return;
    }
    display(root->left);
    cout<<root->data<<" ";
    display(root->right);
}


void levelOrder (Node* root){
    queue<Node*> q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        Node* temp=q.front();
        q.pop();
        if(temp==NULL){
            cout<<endl;
            if(!q.empty()){
                q.push(NULL);
            }
        }else{
            cout<<temp->data<<" ";
        if(temp->left!=NULL){
            q.push(temp->left);
        }
        if(temp->right!=NULL){
            q.push(temp->right);
        }
        }
        
    }
}


void buildFromLevelOrder(Node* &root){
    queue<Node*>q;
    int data;
    cout<<"Enter data "<<endl;
    cin>>data;
    root=new Node(data);
    q.push(root);
    while(!q.empty()){
        Node* temp=q.front();
        q.pop();
        cout<<"Enter data to insert at left of "<<temp->data<<endl;
        int leftData;
        cin>>leftData;
        if(leftData!=-1){
            temp->left=new Node(leftData);
            q.push(temp->left);
        }
        cout<<"Enter data to insert at right of "<<temp->data<<endl;
        int rightData;
        cin>>rightData;
        if(rightData!=-1){
            temp->right=new Node(rightData);
            q.push(temp->right);
        }
    }
}

void reverseLevelOrder(Node* root){
    if(root == NULL) return;
    queue<Node*> q;
    stack<int>s;
    q.push(root);
    while(!q.empty()){
        Node* temp=q.front();
        q.pop();
        s.push(temp->data);

        if(temp->right!=NULL){
            q.push(temp->right);
        }
        if(temp->left!=NULL){
            q.push(temp->left);
        }
    }
    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }
}



Node* CreateTree(Node* root){
    int data;
    cout<<"Enter data "<<endl;
    cin>>data;
    root=new Node(data);

    if(data==-1){
        return NULL;
    }
    
    cout<<"Enter the elements  of the left subtrea   "<<data<<endl;
    root->left=CreateTree(root->left);
    cout<<"Enter the elements  of the right subtrea   "<<data<<endl;
    root->right=CreateTree(root->right);
    return root;

}

void InOrder(Node* root){
    ///left, node ,right (sequence, node  means print)
    //whenever node then print
    if(root==nullptr){
        return;
    }
    InOrder(root->left);
    cout<<root->data<<" ";
    InOrder(root->right);
}

void preOrder(Node* root){
    ///node,left,right (sequence, node  means print)
    if (root==nullptr){
        return;
    }
    cout<<root->data<<" ";
    preOrder(root->left);
    preOrder(root->right);

}

void postOrder(Node* root){
    if(root==NULL){
        return;
    }
    postOrder(root->left);
    postOrder(root->right);
    cout<<root->data<<" ";
}
int main(){
    Node* root=NULL;
    // root=CreateTree(root);
    buildFromLevelOrder(root);
    //1 2 4 -1 -1 5 -1 -1 3 6 -1 -1 7 -1 -1
    
    // display(root);
    levelOrder(root);
    // reverseLevelOrder(root);
    // InOrder(root);
    // preOrder(root);
    // postOrder(root);//4526731
    return 0;
}