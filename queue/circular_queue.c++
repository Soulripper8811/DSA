#include<iostream>
using namespace std;


class CircularQueue{
    public:
    int *arr;
    int front;
    int rear;
    int size;
    public:
    CircularQueue(int size){
        this->size=size;
        arr=new int[size];
        front=-1;
        rear=-1;
    }

    void push(int value){
        if((front==0 && rear==size-1)||(rear ==(front-1+size)%size)){
            cout<<"Queue is full"<<endl;
            return;
        }else if(front==-1){
            front=0;
            rear=0;
            arr[rear]=value;
        }else  if(rear==size-1 && front !=0){
            rear=0;
            arr[rear]=value;
        }else{
            rear++;
            arr[rear]=value;
        }
    }
    int pop(){
        if(front==-1){
            cout<<"Queue is empty"<<endl;
            return -1;
        }
        int value=arr[front];
        if(front ==rear){
            front=-1;
            rear=-1;
            return value;
        }else if(front==size-1){
            front=0;
            return value;
        }
        else{
            front++;
        }
        return value;
    }

    int getFront(){
        if(front==-1){
            cout<<"Queue is empty"<<endl;
            return -1;
        }
        return arr[front];
    }
};


int main(){
    CircularQueue q(5);
    q.push(1);
    q.push(2);
    q.push(3);
    cout<<q.getFront()<<endl;
    q.pop();
    q.pop();
    q.pop();
    cout<<q.getFront()<<endl;
    return 0;
}