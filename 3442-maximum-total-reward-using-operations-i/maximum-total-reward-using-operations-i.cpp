int dp[2001][4000];
class Solution {
public:
    int rec(int i, int n, int reward, vector<int>& rewardValues){
        if(i == n ) return reward;
        if(dp[i][reward]!= -1) return dp[i][reward];
        int pick=0, np=0;
        if(rewardValues[i]> reward) pick+=rec(i+1,n,reward +rewardValues[i] , rewardValues);
        np= rec(i+1,n,reward,rewardValues);
        return dp[i][reward]=max(pick,np);

    }
    int maxTotalReward(vector<int>& rewardValues) {
        sort(rewardValues.begin(),rewardValues.end());
        int n=rewardValues.size();
        memset(dp,-1,sizeof(dp));

        return rec(0,n,0,rewardValues);
    }
};