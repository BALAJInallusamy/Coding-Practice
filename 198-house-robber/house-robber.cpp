class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n+2);
        for(int i = 2 ; i<= n+1 ; i++){
            dp[i] = max(dp[i-2]+ nums[i-2], dp[i-1] );
        }
        return dp.back();
    }
};