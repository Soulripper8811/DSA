#include<iostream>
using namespace std;


int binarySearch(int arr[],int n,int target){
    int start=0;
    int end=n-1;
    while(start<=end){
        int mid=(start+(end-start)/2);
        if(arr[mid]==target){
            return mid;
        }else if(arr[mid]<target){
            start=mid+1;
        }else{
            end=mid-1;
        }
    }
    return -1;
}

int main(){
    int arr[5]={1,2,3,4,5};
    int n=5;
    int target=4;
    int ans=binarySearch(arr,n,target);
    cout<<ans<<endl;
    return 0;
}