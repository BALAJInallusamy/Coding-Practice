class Solution {
public:
    int rec(int start, int n, vector<int>& split, vector<vector<int>>& dp, int k){

        if(start>=n ) return -1e9;
        if(k==0) return start>0 ? split[n-1] - split[start-1]: split[n-1] ;

        if(dp[start][k]!=-1) return dp[start][k];

        int ans=INT_MAX;
        for(int i=start; i<n; i++){
            int pre= split[i];
            if(start>0) pre-= split[start-1];
            int next= rec(i+1,n,split,dp,k-1);
            int cur= max( pre, next );
            ans = min(ans , cur);
        }
        return dp[start][k]=ans;
    }
    int splitArray(vector<int>& nums, int k) {
        int n= nums.size();
        vector<int> split(n,nums[0]);

        for(int i=1;i<n;i++){
            split[i]=nums[i]+split[i-1];
            
        }
        vector<vector<int>> dp(n,vector<int>(k,-1));  
       int ans = rec(0,n,split,dp,k-1);
        return ans;
        
    }
};