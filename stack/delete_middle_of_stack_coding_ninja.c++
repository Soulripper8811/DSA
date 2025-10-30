#include <bits/stdc++.h> 



void solve(stack<int>&st,int N,int count){
   if(count==N/2){
      st.pop();
      return;
   }

   int num=st.top();
   st.pop();
   solve(st,N,count+1);
   st.push(num);
}

void deleteMiddle(stack<int>&inputStack, int N){
	
   // Write your code here
   int count=0;
   solve(inputStack,N,count);

   
}