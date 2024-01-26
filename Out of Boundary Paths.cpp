class Solution {
public:
    int mod=1e9+7;
    int rec(int moves,int i, int j, int m, int n, int maxmove, vector<vector<vector<int>>>& dp){
        if(moves<=maxmove ){
            if(i==m || j==n || i==-1 || j==-1) return 1;
        }
        if(moves> maxmove) return 0;
        if(dp[i][j][moves]!=-1) return dp[i][j][moves];
        long long up  =rec(moves+1,i-1,j,m,n,maxmove,dp);
        long long down=rec(moves+1,i+1,j,m,n,maxmove,dp);
        long long left=rec(moves+1,i,j-1,m,n,maxmove,dp);
        long long right=rec(moves+1,i,j+1,m,n,maxmove,dp);
        return dp[i][j][moves]=((up+down)%mod+(left+right)%mod)%mod;


    }
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        vector<vector<vector<int>>> dp(m,vector<vector<int>>(n,vector<int>(maxMove+1,-1)));
        return rec(0,startRow,startColumn,m,n,maxMove,dp);
    }
};
