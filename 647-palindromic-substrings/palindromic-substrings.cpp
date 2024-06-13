int dp[1001];
class Solution {
public:
    bool count(string& s,int i, int j){
        int k=(i-j)/2;
        while(k>=0){
            if(s[j+k]!=s[i-k]) return 0;
            k--;
        }
        return true;
    }

    int countSubstrings(string s) {
        int n=s.size();
        memset(dp,0,sizeof(dp));
        for(int i=1;i<n;i++){
            
            dp[i]+=dp[i-1];

            for(int j=0;j<i;j++){

                if(s[j]!=s[i]) continue;
                else{
                    if(count(s,i,j)) dp[i]++;
                }
            }
        }
        return dp[n-1]+n;
    }
};