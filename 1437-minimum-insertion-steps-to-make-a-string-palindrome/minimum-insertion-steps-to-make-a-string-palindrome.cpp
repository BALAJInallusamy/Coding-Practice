class Solution {
public:
    int minInsertions(string s) {
        string t = s;
        reverse(t.begin(),t.end());
        int n = s.size();
        vector<vector<int>> dp(n,vector<int>(n));

        if(s[0] == t[0]) dp[0][0] =1;
        for(int i = 1 ; i< n ; i++) {
            dp[i][0] = dp[i-1][0];
            if(s[i]==t[0]) dp[i][0] =1;
        }
        for(int i = 1 ; i< n ; i++) {
            dp[0][i] = dp[0][i-1];
            if(s[0]==t[i]) dp[0][i] =1;
        }

        for(int i = 1 ; i<n ; i++){
            for(int j = 1 ; j< n ; j++){
                if(s[i] == t[j]){
                    dp[i][j] = max(dp[i][j] , dp[i-1][j-1]+1);
                }
                else{
                    dp[i][j] = max(dp[i-1][j] , dp[i][j-1]);
                }
            }
        }
        // for(auto it: dp) {
        //     for (auto x : it) cout<<x<<" ";cout<<endl;
        // }
        return n - dp[n-1][n-1];
    }
};

// le et c od e
//  e do c te e l
//   l e e t c o d e
// e 0 1 1 1 1 1 1 1
// d 0 1 1 1 1 1 2 2
// o 0 1 1 1 1 2 2 2
// c 0 1 1 1 2 2 2 2
// t 0 1 
// e
// e
// l