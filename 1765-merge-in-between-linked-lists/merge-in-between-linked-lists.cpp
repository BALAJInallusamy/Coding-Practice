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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode *cur=list1,*fut=list1,*end=list2;
        while(end->next) end=end->next;
        int n=0;
        while(n<=b){
            if(n+1<a) cur=cur->next;
            fut=fut->next;
            n++;
        }
        end->next=fut;
        cur->next=list2;
    return list1;
    }
};