class Solution {
public:
    int rec(vector<vector<int>>& grid,int i, int j,int k,int rows,int cols,vector<vector<vector<int>>> &dp){
        if(j<0 || k<0 || j>cols-1 || k>cols-1) return -1e8;
        if(dp[i][j][k]!=-1) return dp[i][j][k];
        if(i==rows-1){
            if(j==k) return dp[i][j][k]= grid[i][j];
            else return dp[i][j][k]=grid[i][k]+grid[i][j];
        }
        int maxi=-1e8;
        for(int m=-1;m<=1;m++){
            for(int n=-1;n<=1;n++){
                int value=0;
                if(j==k) value= grid[i][j];
                else{
                    value=grid[i][k]+grid[i][j];
                }
                value+=rec(grid,i+1,j+m,k+n,rows,cols,dp);
                maxi=max(maxi,value);
            }
        }
        return dp[i][j][k]=maxi;
    }
    int cherryPickup(vector<vector<int>>& grid) {
        int row=grid.size();
        int col=grid[0].size();
        vector<vector<vector<int>>> dp(row,vector(col,vector(col,-1)));
        return rec(grid,0,0,col-1,row,col,dp);
    }
};