class Solution {
public:

    bool canJump(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return true;
        //vector<int> dp(n,-1);
        int i=0;
        for(int reach=0;i<n && i<=reach;i++){
            reach=max(nums[i]+i,reach);
        }
        return i==n;
    }
};
