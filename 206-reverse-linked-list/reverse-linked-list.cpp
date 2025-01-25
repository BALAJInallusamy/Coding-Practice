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
        ListNode* cur = head, *prev = NULL, *fut = NULL;
        if(head && head->next) fut =head->next;
        else return head;
        while(fut){
            cur->next = prev;
            prev= cur;
            cur = fut;
            fut = fut->next;
        }
        cur->next = prev;
        return cur;
    }
};