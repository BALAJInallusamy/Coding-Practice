class Solution {
public:
    int videoStitching(vector<vector<int>>& clips, int time) {
        int n = clips.size();
        vector<int> dp(time+1,0);
        sort(clips.begin(),clips.end());

        for(int i = 0 ; i <n ; i ++){
            int start = min(clips[i][0],time);
            dp[start] = max(dp[start], min(clips[i][1],time));
        }
        int end = 0 , far = 0, count = 0;
        for(int i = 0 ; i< time+1 ; i++){
            if(end<i){
                if(far<=end) return -1;
                end = far;
                count++;
            }
            far = max(far, dp[i]);
        }
        return count;
    }
};


// 02 15 19 46 59 810
// 0 1 2 3 4 5 6 7 8 9 10
// 0 0