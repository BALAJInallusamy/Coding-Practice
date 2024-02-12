class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int ans=0,count=0;
        for(int i=0;i<nums.size();i++){
           if(!count) ans=nums[i],count++;
           else if(nums[i]==ans) count++;
           else count--;
        }
        return ans;
    }
};