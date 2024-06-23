class Solution {
public:
    long long maximumTotalCost(vector<int>& nums) {
        long long ans=0;
        int n=nums.size(), l=0,r=0;
        vector<vector<long long>> dp(n,vector<long long>(2));
        dp[0][0]=nums[0];
        dp[0][1]=nums[0];
        for(int i=1;i<n;i++){
            dp[i][0]=nums[i]+ max(dp[i-1][1], dp[i-1][0]);
            dp[i][1]=-nums[i] + dp[i-1][0];
        }
        return max(dp[n-1][0],dp[n-1][1]);
    }
};

// -1 -5 -3 -3 -9  1 -1 
//    -   +  -  +
//    -5 -3  3  9
//     5 -3 -3  9