class Solution {
public:
    int maxRepeating(string s, string word) {
        int m = word.size();
        int n = s.size();
        vector<int> nums;
        for(int i = 0 ; i < n-m +1; i++){

            string x = s.substr(i,m);
            if(x==word) nums.push_back(i);

        }
        int a = nums.size();
        if(!a) return 0;
        vector<int> dp(a,1);
        dp[0] = 1;
        int k = 1;
        for(int i = 1 ; i < a ; i++){
            for(int j = 0 ; j< i ; j++){
                if(nums[j]+m == nums[i])
                    dp[i] = max(dp[i], 1+dp[j]);
            }
            k = max(k,dp[i]);
        }
        // for(auto it: nums) cout<<it<<" ";
        // cout<<endl;
        // for(auto it: dp) cout<<it<<" ";

        return k;
    }
};