int dp[1001][1001];
class Solution {
public:
    int rec(int i, int j, int n, int m, string &text1, string &text2){
        if(i >= n || j>= m ) return 0;
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int picki=0;
        for(int k=j;k<m;k++){
            if(text1[i]==text2[k]){ 
                picki=1+rec(i+1,k+1,n,m,text1,text2);
                break;
                }
        }
        int np=rec(i+1,j,n,m,text1,text2);
        return dp[i][j]=max(picki,np);
    }
    int longestCommonSubsequence(string &text1, string &text2) {
        memset(dp,-1,sizeof(dp));
        int m=text2.size(), n=text1.size();
        return rec(0,0,n,m,text1,text2);
    }
};
