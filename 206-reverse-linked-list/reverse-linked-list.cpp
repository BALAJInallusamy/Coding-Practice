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
    ListNode* reverseList(ListNode* head) {
        ListNode* past = NULL,*fut=NULL,*cur=head;
        if(head) fut=head->next;

        while(cur){
                cur->next=past;
                past=cur;
                cur=fut;
                if(fut)
                fut=fut->next;
            }
        return past;
    }
};