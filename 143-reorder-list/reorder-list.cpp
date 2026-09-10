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
  ListNode* reverseLL(ListNode*head){
    if(head==NULL || head->next==NULL){
        return head;
    }
    ListNode*last=reverseLL(head->next);
    head->next->next=head;
    head->next=NULL;
    return last; 
  }
    void reorderList(ListNode* head) {
        ListNode*slow=head;
        ListNode*fast=head;
        while(fast && fast->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode*rever=reverseLL(slow);
        ListNode*curr=head;
        while(rever->next!=NULL){
            ListNode*tempcurr=curr->next;
            curr->next=rever;
            ListNode*temprever=rever->next;
            rever->next=tempcurr;
            curr=tempcurr;
            rever=temprever;
        }
        
    }
};