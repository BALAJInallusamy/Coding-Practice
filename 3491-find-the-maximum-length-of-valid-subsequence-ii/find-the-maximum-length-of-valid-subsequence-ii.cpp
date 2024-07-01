class Solution {
public:
    int maximumLength(vector<int>& nums, int k) {
        int ans=2;
        int n=nums.size();
        vector<vector<int>> dp(k,vector<int>(k,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<k;j++){
                int r= nums[i]%k;
                dp[j][r]= dp[r][j]+1;
                ans=max(ans,dp[j][r]);
            }
        }
        return ans;
    }
};

// 1 4 2 3 1 4
// i j        