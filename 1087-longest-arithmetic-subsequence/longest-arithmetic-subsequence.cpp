int dp[1001][2001];
class Solution {
public:
    int dp[1001][2001];
    int longestArithSeqLength(vector<int>& nums) {
        int n=nums.size();
        int diff,ans=0;
        memset(dp,0,sizeof(dp));
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                diff=nums[j]-nums[i]+1000;

                dp[j][diff] = max( dp[i][diff]+1,2 ); 

                ans=max(dp[j][diff],ans);
            }
        }
        return ans;
    }
};

//      20 1 15 3 10 5 8
// 20       
// 1   
// 15
// 3
// 10
// 5
// 8