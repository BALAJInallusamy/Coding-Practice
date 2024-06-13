vector<int> moves= { -2, -1,1,2};
int dp[4][3][5000];
int mod=1e9+7;
class Solution {
public:
    int rec(int i , int j, int n){
        if(i<0 || j<0 || i>=4 || j>=3) return 0;
        if(i==3 && (j==0 || j==2)) return 0;
        if(n==0) return 1;
        if(dp[i][j][n]!=-1) return dp[i][j][n];
        int ans=0;

        for(int a=0;a<4;a++){
            for(int b=0;b<4;b++){
                if(abs(moves[a]) != abs(moves[b])){

                    ans=( ans + rec(i+moves[a], j+moves[b], n-1) )%mod;
                }
            }
        }
        return dp[i][j][n]=ans;

    }
    int knightDialer(int n) {
        int ans=0;
        memset(dp,-1,sizeof(dp));
        for(int i=0;i<4;i++){
            for(int j=0;j<3;j++){
                ans=(ans+rec(i,j,n-1))%mod;
            }
        }
        return ans;
    }
};