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
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL||head->next==nullptr){
            return head;
        }
        ListNode* tail=head;
        int length=1;
        while(tail->next!=NULL){
            tail=tail->next;
            length++;

        }
        tail->next=head;
        cout <<k%length;
        int steps=length-(k%length);
        while(steps!=0){
            tail=tail->next;
            steps--;
        }
        head=tail->next;
        tail->next=nullptr;
        return head;

    
    }
};