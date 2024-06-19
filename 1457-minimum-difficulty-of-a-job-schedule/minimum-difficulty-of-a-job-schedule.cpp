class Solution {
public:
    int minDifficulty(vector<int>& job, int d) {
        int n=job.size();
        if(d>n) return -1;
        int ans=job[0];
        vector<vector<int>> dp(d,vector<int> (n));
        dp[0][0]=job[0];

        for(int i=1;i<n;i++){
            dp[0][i]=max(job[i],dp[0][i-1]);
        }

        for(int i=1;i<d;i++){

            // j=> i-1 th cut ans
            for(int j=i-1;j<n;j++){ 
                //k => ith cut ans
                int temp= job[j+1];
                for(int k=j+1;k<n;k++){
                    temp= max(temp, job[k]);

                    if(dp[i][k] ==0 ) dp[i][k]= temp + dp[i-1][j];
                    else dp[i][k]= min( temp + dp[i-1][j] , dp[i][k]);

                }
            }
        }
        // for(auto it: dp) {
        //     for(auto x:it) cout<<x<<" ";
        //     cout<<endl;
        // }
        return dp[d-1][n-1];
    }
};

// 7 100 100 5
// 3