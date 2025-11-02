#include <bits/stdc++.h> 
/*
	This is signature of helper function 'knows'.
	You should not implement it, or speculate about its implementation.

	bool knows(int A, int B); 
	Function 'knows(A, B)' will returns "true" if the person having
	id 'A' know the person having id 'B' in the party, "false" otherwise.
*/

int findCelebrity(int n) {
 	// Write your code here.
	stack<int> s;
	for(int i =0;i<n;i++){
		s.push(i);
	}
	bool isCelebrity=false;
	while(s.size()>1){
		int a=s.top();
		s.pop();
		int b =s.top();
		s.pop();
		if(knows(a,b)){
			s.push(b);
		}else{
			s.push(a);
		}

	}
	int canidiate=s.top();
	for(int i=0;i<n;i++){
		if(i!=canidiate){//the both number should not be checked condition.
		if(knows(canidiate,i)|| !knows(i,canidiate)){
			return -1;
		}
		}
	}
	return canidiate;
}