/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
private:
    ListNode* getMiddleElement(ListNode* head){
        if (head==NULL){
            return nullptr;
        }
        if (head->next==NULL){
            return nullptr;
        }
        ListNode* fast=head;
        ListNode* slow=head;
        ListNode*curr=NULL;
    while (fast != nullptr && fast->next != nullptr) {
    fast = fast->next->next;
    curr=slow;
    slow = slow->next;
    
}
        return curr;
    }
public:
    ListNode* deleteMiddle(ListNode* head) {
        ListNode*temp=head;
        if(head==NULL){
            return NULL;
        }
        if(head->next==nullptr){
            return nullptr;
        }
        temp=getMiddleElement(temp);
        ListNode* deleteNode=temp->next;
        temp->next=temp ->next->next;
        deleteNode->next=NULL;

        
        
        return head;


    
    }
};