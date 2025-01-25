class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return nums[0];
        vector<int> dp(n+2);
        
        for(int i = 2 ; i< n+1 ; i++){
            dp[i] = max(dp[i-2] + nums[i-2], dp[i-1]);
        }
        int ans = dp[n];
        dp=vector<int>(n+2,0);
        for(int i = 3; i< n+2; i++){
            dp[i] = max(dp[i-2] + nums[i-2], dp[i-1]);
        }
        return max(ans, dp.back());
    }
};