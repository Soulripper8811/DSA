class Solution {
  public:
    void reverseQueue(queue<int> &q) {
        if(q.empty()){
            return;
        }
        
        int element=q.front();
        q.pop();
        reverseQueue(q);
        q.push(element);
    }
};