int dp[21][21][21][21];

class Solution {
public:
    int rec(int i, int j, int m, int n , vector<int>& hCut, vector<int>& vCut){
        if(m-i == 1 && n-j == 1) return 0;
        if(dp[i][j][m][n]!=-1) return dp[i][j][m][n];
        int ans=1e9;

        for(int x = i+1; x<m ; x++){
            int h = hCut[x-1];
            h+= rec(i,j,x,n,hCut,vCut) + rec(x,j,m,n,hCut,vCut); 
            ans = min(h,ans);
        }
        for(int y=j+1; y<n;y++){
            int v = vCut[y-1];
            v+= rec(i,j,m,y,hCut,vCut) + rec(i,y,m,n,hCut,vCut); 
            ans = min(v,ans);
        }
        return dp[i][j][m][n]=ans;
    }
    int minimumCost(int m, int n, vector<int>& hCut, vector<int>& vCut) {
        memset(dp,-1,sizeof(dp));
        int ans=0;
        ans = rec(0,0,m,n,hCut,vCut);
        return ans;
    }
};