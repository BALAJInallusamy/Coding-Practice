class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int> (2));
        for(int i = n-1 ; i>=0 ; i--){
            dp[i] = {i,0};
            for(int j= i+1; j<n ; j++){
                if(nums[j] % nums[i] == 0) {
                    vector<int> temp = { j, dp[j][1] };
                    dp[i] = dp[i][1] < dp[j][1] ? temp :  dp[i];
                }
            }
            dp[i][1]++;
        }
        vector<int> ans;
        int start=0;
        for(int i=0;i<n;i++){
            start = dp[start][1] < dp[i][1] ? i:start;
        }
        while(dp[start][0] != start){
            ans.push_back(nums[start]);
            start = dp[start][0];
        }
        ans.push_back(nums[start]);
        //for(auto it:dp) cout<<it[0]<<","<<it[1]<<"  ";
        return ans;
    }
};