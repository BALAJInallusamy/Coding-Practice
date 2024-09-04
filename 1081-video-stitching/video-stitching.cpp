class Solution {
public:
    int videoStitching(vector<vector<int>>& clips, int time) {
        int n = clips.size();
        vector<int> dp(time+1, n + 1);
        sort(clips.begin(),clips.end());
        dp[0] = 0;
        for(int i = 0 ; i<n ; i ++){
            for(int j = clips[i][0] +1 ; j<= min(clips[i][1],time) ; j++){
                dp[j] = min( dp[j] , dp[max(0,clips[i][0])] + 1);
            }
        }
        // for(auto it:dp) cout<<it<<" ";
        return dp[time] == n+1?-1:dp[time];
    }
};


// 0 2  