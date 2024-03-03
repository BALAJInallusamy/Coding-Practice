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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* fut=head, *pre=head;
        while(n-- && fut){
            fut=fut->next;
        }
        if(!fut) return head=head->next;
        while(fut) {
            fut=fut->next;
            if(!fut){
                fut=pre;
                pre=pre->next;
                fut->next=pre->next;
                return head;
                }
            pre=pre->next;
            }
        return head;
    }
};
//       p     f
// 1 2 3 4 5
// 1 2 f 4 5

//   s f
// 1 2
