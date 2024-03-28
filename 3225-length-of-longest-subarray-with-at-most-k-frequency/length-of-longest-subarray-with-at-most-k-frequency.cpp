class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        int l=0,r=0,n=nums.size(),ans=0,count=0, maxi=0;
        while(r<n && l<=r){
           
        maxi=++mp[nums[r]];
        
        while(maxi>k && l<=r && l<n){
            if(nums[l]==nums[r]){ maxi=--mp[nums[l++]];}
            else --mp[nums[l++]];
        }
        //l++;
        if(l>r) l=r;
        
        
        if(maxi<=k) {
            count=r-l+1;
            ans=max(count,ans);
            r++;
            }
        }
            return ans;
    }
};