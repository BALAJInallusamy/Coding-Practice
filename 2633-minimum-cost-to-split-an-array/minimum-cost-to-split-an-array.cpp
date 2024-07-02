class Solution {
public:
    int minCost(vector<int>& nums, int k) {
        int n = nums.size();
        vector<vector<int>> prefix(n + 1, vector<int>(n, 0));
        for (int i = 1; i <= n; i += 1) {
            for (int j = 0; j < n; j += 1) {
                prefix[i][j] = prefix[i - 1][j];
            }
            prefix[i][nums[i - 1]] += 1;
        }
        // for(auto it:prefix){
        //     for(auto x:it) cout<<x<<" ";cout<<endl;
        // }
        vector<int> dp(n + 1, 0);

        for (int i = 1; i <= n; i += 1) {
            // printf("i: %d\n", i);
            vector<int> cnts = prefix[i];
            int once = 0; 
            for (int c: cnts) {
                if (c == 1) once += 1;
            }
            dp[i] = INT_MAX;
            for (int j = 0; j < i; j += 1) {
                dp[i] = min(dp[i], dp[j] + (i - j) - once + k);
                cnts[nums[j]] -= 1;
                if (cnts[nums[j]] == 1) once += 1;
                else if (cnts[nums[j]] == 0) once -= 1;
            }
        }
        return dp[n];
    }
};