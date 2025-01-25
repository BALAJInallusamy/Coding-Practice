class Solution {
public:
    int longestCommonSubsequence(string s, string t) {
        int n = s.size() , m = t.size();
        vector<vector<int>> dp(n,vector<int>(m,0));
        for(int i =0 ; i<n ; i++){
            if(s[i] == t[0]) dp[i][0] = 1;
            else if(i>0) dp[i][0] += dp[i-1][0];
        }
        for(int i =0 ; i<m ; i++){
            if(s[0] == t[i]) dp[0][i] = 1;
            else if(i>0) dp[0][i] += dp[0][i-1];
        }
        for(int i = 1; i<n ; i++){
            for(int j = 1 ; j< m ; j++){
                if( s[i] == t[j] ){
                    dp[i][j] = max( 1+dp[i-1][j-1] , dp[i][j] );
                }
                else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
        // for(auto it: dp){
        //     for(auto x:it) cout<<x<<" ";cout<<endl;
        // }
        return dp[n-1][m-1];
    }
};