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
    bool isPalindrome(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode* curr=head,* slow=head,* fast=head, *past=NULL, *fut;
        while(fast && fast->next){
            fast=fast->next->next;
            fut=slow->next;
            slow->next=past;
            past=slow;
            slow=fut;
        }
        if(fast) slow=slow->next;
        while(slow){
            if(slow->val!=past->val) return false;
            slow=slow->next;
            past=past->next;
        }
        return true;
    }
};