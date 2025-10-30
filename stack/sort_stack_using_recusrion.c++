#include <bits/stdc++.h> 
using namespace std;

void sortedInsert(stack<int> &s, int num) {
    // Insert in sorted order
    if (s.empty() || s.top() < num) {
        s.push(num);
        return;
    }
    
    int n = s.top();
    s.pop();
    
    sortedInsert(s, num);
    
    s.push(n);
}

stack<int> sortStack(stack<int> &s) {
    // Base condition
    if (s.empty()) {
        return s;
    }
    
    int num = s.top();
    s.pop();
    
    // Recursive call to sort remaining stack
    sortStack(s);
    
    // Insert current element in sorted order
    sortedInsert(s, num);
    
    return s;
}
