class Solution {
public:
    
    int rec(int n,vector<int> & dp){
        if(n==0) return 0;
        if(n==1 ) return 1;
        if(n<0) return 0;
        if(dp[n]!=0) return dp[n];

        int best=pow(n,0.5);
        int ans=1e9;
        for(int i=best;i>0;){
            ans=min(ans,1+rec(n-i*i,dp));
            i=pow(i*i-1,0.5);
        }
        return dp[n]=ans;
    }

    int numSquares(int n) {
        vector<int> dp(n+1,0);
        for(int i=1;i<=pow(n,0.5);){
            dp[i*i]=1;
            i=pow(i+1,2);
        }
        return rec(n,dp);
        
    }
};


