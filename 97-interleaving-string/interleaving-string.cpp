class Solution {
public:
    
    int dp[101][101][201];
    bool rec(int i , int j , int k , int n , int m , string s1, string s2, string s3 ){
        if(i==n && j==m && k == n+m) return true;
        bool ans = 0;
        if(dp[i][j][k]!= -1) return dp[i][j][k];
        if(i == n){
            return s2.substr(j) == s3.substr(k);
        }
        else if(j == m){
            return s1.substr(i) == s3.substr(k);
        }
        if(s1[i] == s3[k]) {
            ans|= rec(i+1,j, k+1 , n , m, s1, s2, s3);
        }
        if(s2[j] == s3[k]){
            ans|= rec(i,j+1, k+1 , n , m, s1, s2, s3);
        }
        return dp[i][j][k] = ans;
    }
    bool isInterleave(string s1, string s2, string s3) {
        int n = s1.size() , m =s2.size() ;
        if(n+m != s3.size()) return false;
        memset(dp,-1,sizeof(dp));

        return rec(0,0,0,n,m,s1,s2,s3);
    }
};