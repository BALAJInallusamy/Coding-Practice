class Solution {
public:
    int inf = 1e9;
    int minDistance(string word1, string word2) {
        int n = word1.size(), m = word2.size();
        vector<vector<int>> dp(n, vector<int> (m,-1));
        function<int(int,int)> rec = [&] (int i , int j ){
            if(i==n && j == m) return 0;
            if(i == n) return m-j;
            if(j == m ) return n-i;
            if(dp[i][j]!= -1) return dp[i][j];
            int ans = 0;
            if(word1[i] != word2[j]){
                int toggle =  rec(i+1,j+1);
                int del = rec(i+1,j);
                int in = rec(i,j+1);
                ans = 1+ min({ toggle, del , in}); 
            }
            else{
                ans = rec(i+1,j+1);
            }
            return dp[i][j] = ans;
        };
        return rec(0,0);
    }
};