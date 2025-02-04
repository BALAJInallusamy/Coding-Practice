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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(!list1) return list2;
        if(!list2) return list1;
        if(list1->val < list2->val){
            ListNode* fut = mergeTwoLists(list1->next,list2);
            list1->next = fut;
            return list1;
        }
        else{
            ListNode* fut = mergeTwoLists(list1,list2->next);
            list2->next = fut;
            return list2;
        }
        return NULL;
    }
};