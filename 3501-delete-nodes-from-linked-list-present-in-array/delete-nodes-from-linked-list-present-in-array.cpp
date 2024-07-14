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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        int n = nums.size();
        unordered_map<int,int> mp;
        for(auto it:nums) mp[it]++;
        ListNode* dummy = new ListNode(0,head), * temp = head, * prev = dummy;
        while(temp){
            if(mp[temp->val]>0){
                temp=temp->next;
            }
            else {
                prev->next= temp;
                prev = temp;
                temp= temp->next;
                }

        }
        prev ->next = temp;
        return dummy->next;
    }
};