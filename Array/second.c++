#include<iostream>
using namespace std;

void print(int arr[],int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

void swapAlternative(int arr[],int n){
    for(int i=0;i<n-1;i+=2){
        
       int temp=arr[i];
       arr[i]=arr[i+1];
       arr[i+1]=temp;
       if(i==n-1){
           break;
       }}
    print(arr,n);
}

bool unique(int arr[],int n){
    int count =0;
    for(int i=0;i<n;i++){
        if(arr[i]==arr[i+1]){
            count++;
        }
    }
    if(count>0){
        return false;
    }else{
        return true;
    }
}



int main(){
    int arr[6]={1,2,3,4,5,6};

    swapAlternative(arr,6);
    bool uniqueNumber=unique(arr,6);
    cout<<uniqueNumber;
    return 0;
}