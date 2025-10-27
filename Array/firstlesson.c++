#include<iostream>
using namespace std;

void print(int arr[],int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
int findMax(int arr[],int n){
    int max=arr[0];
    for(int i=0;i<n;i++){
        if(arr[i]>max){
            max=arr[i];
        }
    }
    return max;
}

int findMin(int arr[],int n){
    int min=arr[0];
    for(int i=0;i<n;i++){
        if(arr[i]<min){
            min=arr[i];
        }
    }
    return min;
}
int maxNumber(int arr[],int n){
    int maxi=arr[0];
    for(int i=0;i<n;i++){
        maxi=max(maxi,arr[i]);
    }
    return maxi;
}
int sumOfElements(int arr[],int n){
    int sum=0;
    for(int i=0;i<n;i++){
        sum+=arr[i];
    }
    return sum;
}

bool isPresent(int arr[],int n,int x){
    for(int i=0;i<n;i++){
        if(arr[i]==x){
            cout<<"Element "<<x<<" is present at index "<<i<<endl;
            return true;
            break;
        }
    }
    return false;
}
void  printArray(int arr[],int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

void reverArray(int arr[],int n){
    int start=0;
    int end=n-1;
    while(start<end){
        int temp=arr[start];
        arr[start]=arr[end];
        arr[end]=temp;
        start++;
        end--;
    }
    cout<<"Reversed array is: ";
    printArray(arr,n);

}

int main(){
    // int size;
    // cin>>size;
    // int arr[100];
    int arr[4]={1,3,5,6};
    // for(int i=0;i<size;i++){
    //     cout<<"Enter element "<<i+1<<": ";
    //     cin>>arr[i];
    // }
reverArray(arr,4);

    // int max=findMax(arr,size);
    // cout<<"Maximum element: "<<max<<endl;
    // cout<<"Minimum element: "<<findMin(arr,size)<<endl;
    // cout<<"Maximum number: "<<maxNumber(arr,size)<<endl;
    // cout<<"Sum of elements: "<<sumOfElements(arr,size)<<endl;
    // cout<<"Is present: "<<isPresent(arr,size,5)<<endl;

    return 0;
}