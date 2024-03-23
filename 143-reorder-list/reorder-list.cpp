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
    ListNode* mid(ListNode* head){
        ListNode* slow=head,* fast=head;
        while(fast && fast->next ){
            fast=fast->next->next;
            slow=slow->next;}
        return slow;
    }
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = NULL,*next=NULL;
        while(head != NULL){
            next= head->next;
            head->next = prev; 
            prev = head; 
            head = next;
        }
        return prev;
    }
    void reorderList(ListNode* head) {
        if(!(!head || !head->next || !head->next->next)){
            ListNode* m=mid(head);
            ListNode* second=m->next;
            m->next=NULL;
            second=reverseList(second);
            ListNode* first=head,*f1=head->next,*f2=second->next;
            while(second){
                first->next=second;
                second->next=f1;
                first=f1;
                second=f2;
                f1=f1->next;
                if(f2)
                    f2=f2->next;
                else break;
            }
        }
    }
};