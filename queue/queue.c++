// #include<iostream>
// #include<queue>

// using namespace std;


// int main(){
//     queue<int> q;
//     q.push(1);
//     q.push(2);
//     q.push(3);

//     while(!q.empty()){
//         cout<<q.front()<<endl;
//         q.pop();
//     }
    
//     return 0;
// }
#include<iostream>
using namespace std;



class  Queue{
    public:

    int* arr;
    int front;
    int rear;
    int size;
    public:
    Queue(int size){
        this->size=size;
        arr=new int[size];
        front=0;
        rear=0;
    }

    void push(int value){
        if(rear==size){
            cout<<"Queue is full"<<endl;
            return;
        }
        else{
            arr[rear]=value;
            rear++;
        }
    }
    void pop(){
        if(front==rear){
            cout<<"Queue is empty"<<endl;
            return;
        }else{
            front++;
            return;
        }
    }
    int getFront(){
        if(front==rear){
            cout<<"Queue is empty"<<endl;
            return -1;
        }else{
            return arr[front];
        }
    }
    int getRear(){
        if(front==rear){
            cout<<"Queue is empty"<<endl;
            return -1;
        }
        else {
            return arr[rear-1];
        }
    }
};

int main(){
    Queue q(5);
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    cout<<q.getFront();
    cout<<q.getRear();
    return 0;
}