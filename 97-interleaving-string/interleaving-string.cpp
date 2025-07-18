class Solution {
public:
    bool rec(int i, int j,int k, int n, int m, string s1, string s2, string s3,vector<vector<int>>& dp){
        if(i==n && j==m) return true;
        if(dp[i][j]!=-1) return dp[i][j];
        bool one = 0, two = 0;
        if(i<n && s1[i]==s3[k]) one|= rec(i+1,j,k+1,n,m,s1,s2,s3,dp);
        if(j<m && s2[j]==s3[k]) two|= rec(i,j+1,k+1,n,m,s1,s2,s3,dp);
        if(i<n && j<m && s1[i]!= s3[k] && s2[j]!=s3[k]) return 0;
        return dp[i][j] = one||two;
    }
    bool isInterleave(string s1, string s2, string s3) {
        int n = s1.size(), m=s2.size();
        if(n+m!= s3.size()) return 0;
        vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
        return rec(0,0,0,n,m,s1,s2,s3,dp);
    }
};