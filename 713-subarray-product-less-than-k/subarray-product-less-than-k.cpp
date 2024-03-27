class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int n=nums.size(), l=0, r=0,ans=0;
        int prod=1;
        while(r<n && l<=r){
            cout<<l<<r<<" ";
            if(l==r){
                if(nums[r]<k) prod=nums[r++],ans+=1;
                else r++,l++;
            }
            else{
                if(nums[r]*prod < k) prod*=nums[r++], ans+=(r-l);
                else prod/=nums[l++];
            }
        }
        return ans;
    }
};
