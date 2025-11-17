// #include<iostream>
// #include<deque>
// using namespace std;

// int main(){
//     deque<int>q;
//     q.push_back(1);
//     q.push_front(2);

//     cout <<q.front()<<endl;
//     cout<<q.back()<<endl;
//     q.pop_front();
    
//     cout <<q.front()<<endl;
//     cout<<q.back()<<endl;
//     return 0;
// }
#include <bits/stdc++.h> 
class Deque
{
public:
    int* arr;
    int size;
    int front;
    int rear;

    // Initialize your data structure.
    Deque(int n)
    {
        // Write your code here.
        this->size=n;
        arr=new int[size];
        front=-1;
        rear=-1;
    }

    // Pushes 'X' in the front of the deque. Returns true if it gets pushed into the deque, and false otherwise.
    bool pushFront(int x)
    {
        // Write your code here.
        if (isFull()){
            return false;
        }
        if(front==-1){
            front=0;
            rear=0;
        }else if(front==0 && rear!=size-1){
            front=size-1;
        }
        else{
            front--;
        }
        arr[front]=x;
        return true;
    }

    // Pushes 'X' in the back of the deque. Returns true if it gets pushed into the deque, and false otherwise.
    bool pushRear(int x)
    {
        // Write your code here.
        if(isFull()){
            return false;
        }
        if(front==-1){
            front=0;
            rear=0;
        }else if(rear==size-1 &&front!=0){
            rear =0;
        }else {
            rear++;
        }
        arr[rear]=x;
        return true;
        
    }

    // Pops an element from the front of the deque. Returns -1 if the deque is empty, otherwise returns the popped element.
    int popFront()
    {
        // Write your code here.
        if(isEmpty()){
            return -1;
        }
        int value=arr[front];
        arr[front]=-1;
        if(front==rear){
            front=-1;
            rear=-1;
        }else if(front==size-1){
            front=0;
        }else{
            front++;
        }
        return value;
    }

    // Pops an element from the back of the deque. Returns -1 if the deque is empty, otherwise returns the popped element.
    int popRear()
    {
        // Write your code here.
        if(isEmpty()){
            return -1;
        }
        int value=arr[rear];
        arr[rear]=-1;
        if(front==rear){
            front=rear=-1;
        }
        else if(rear==0){
            rear=size-1;
        }else{
            rear--;
        }
        return value;

    }

    // Returns the first element of the deque. If the deque is empty, it returns -1.
    int getFront()
    {
        // Write your code here.
        if(isEmpty()){
            return -1;
        }else{
            return arr[front];
        }
    }

    // Returns the last element of the deque. If the deque is empty, it returns -1.
    int getRear()
    {
        // Write your code here.
        if(isEmpty()){
            return -1;
        }else{
            return arr[rear];
        }
    }

    // Returns true if the deque is empty. Otherwise returns false.
    bool isEmpty()
    {
        // Write your code here.
        if(front==-1){
            return true;
        }else{
        return false;
        }
    }

    // Returns true if the deque is full. Otherwise returns false.
    bool isFull()
    {
        // Write your code here.
        if((front==0 && rear==size-1)||(rear ==(front-1+size)%size)){
            return true;
        }else{
            return false;
        }
    }
};