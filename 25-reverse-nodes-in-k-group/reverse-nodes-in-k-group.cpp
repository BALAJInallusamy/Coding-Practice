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
    vector<ListNode*> reverse(ListNode* head,int k){
        ListNode* cur=head,*fut=head,*pre=NULL;
        while( k--){
            fut=fut->next;
            cur->next=pre;
            pre=cur;
            cur=fut;
        }
        return {pre,head};
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (k<=1) return head;
        ListNode* counter=head,*ns=head;
        int count=0,m=0;
        while(counter){ count++; counter=counter->next;
            if(count==k-1) ns=counter;}
            m=count;
        count/=k;
        ListNode* input=head,*end=head,*start=head;
        vector<vector<ListNode*>> store;
        while(count--){
            input=start;
            for(int i=0;i<k;i++){
                start=start->next;
            }
            vector<ListNode*> ans=reverse(input,k);
            store.push_back(ans);

        }
        for(int i=0;i<store.size()-1;i++){
            store[i][1]->next=store[i+1][0];
        }
        if(m%k==0) start=NULL;
        store.back()[1]->next=start;
    return ns;

    }
};
// 1->2->null
// 3->4->null