
class Solution {
public:
    int rec(int i, int j, int m, int n, vector<vector<int>>& grid){
        if(i>=m || j>=n || i<0 || j<0 || grid[i][j]==0) return 0;
        grid[i][j]=0;
        return 1+rec(i+1,j,m,n,grid)+rec(i-1,j,m,n,grid)+rec(i,j-1,m,n,grid)+rec(i,j+1,m,n,grid);
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m=grid.size(), n=grid[0].size();
        int ans=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1) ans=max(ans,rec(i,j,m,n,grid));  
            }
        }
        
        return ans;
    }
};

// 11000
// 11000
// 00011
// 00011