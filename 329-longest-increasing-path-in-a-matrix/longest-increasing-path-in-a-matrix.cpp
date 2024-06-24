vector<int> xy={-1,0,1,0,-1};
class Solution {
public:
    int rec(int i, int j, int parent, int n, int m, vector<vector<int>>& matrix, vector<vector<int>>& dp){
        if(i==n || j==m || i<0 || j<0 || matrix[i][j]<=parent){
            return 0;
        }
        if(dp[i][j]>0) return dp[i][j];
        for(int k=0;k<4;k++){
            int x=i+xy[k], y= j+xy[k+1];
            int temp= 1+rec(x,y,matrix[i][j],n,m,matrix,dp);
            dp[i][j]=max(temp,dp[i][j]);
        }
        return dp[i][j];
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n=matrix.size(), m=matrix[0].size();
        vector<vector<int>> dp(n,vector<int>(m,0));
        int ans=1;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(dp[i][j]==0){
                    dp[i][j]=rec(i,j,-1,n,m,matrix,dp);
                }
                ans=max(dp[i][j],ans);
            }
        }
        for(auto it:dp){
            for(auto x:it) cout<<x<<" ";cout<<endl;
        }
        return ans;
    }
};