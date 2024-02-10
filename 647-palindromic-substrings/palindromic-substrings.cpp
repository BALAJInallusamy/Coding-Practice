class Solution {
public:
    int countSubstrings(string s) {
        int left=0;
        int n=s.size(),ans=0;
        int i,j;
        vector<vector<int>> dp(n,vector<int>(n,0));
        for(int i=0;i<n;i++) dp[i][i]=1;
        ans+=n;
        for(left=0;left<n;left++){
            i=left-1;j=left+1;
            while(i>-1 && j<n){
                if(dp[i+1][j-1] && s[i]==s[j]) ans++,dp[i][j]++,i--,j++;
                else break;
            }
            i=left;j=left+1;
            if(s[i]==s[j]){
                dp[i][j]++;
                ans++;
                i=left-1;j=left+2;
                while(i>-1 && j<n){
                    if(dp[i+1][j-1] && s[i]==s[j]) ans++,dp[i][j]++,i--,j++;
                    else break;
                }
            }
        }
        return ans;
    }
};
 //a a b b c c c c b b a  a
 //0 1 2 3 4 5 6 7 8 9 10 11
      


