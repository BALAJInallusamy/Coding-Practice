class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n= cardPoints.size(), ans=0;
        int count=0, total=cardPoints[0];
        for(int i=1;i<n;i++){
            total+=cardPoints[i];
            cardPoints[i]+=cardPoints[i-1];
        }
        if(n==k) return total;
        for(int i=0;i<= k;i++){
            int sub= 0;
            if(i) sub=cardPoints[i+n -k-1]-cardPoints[i-1];
            else sub=cardPoints[i+n-k-1];
            ans=max(ans,total- sub);
        }
        return ans;
    }
};

// nums[l] + rec(l+1,r,k-1)
// nums[r] + rec(l,r-1,k-1)
// dp[l][r]= max(left,right)