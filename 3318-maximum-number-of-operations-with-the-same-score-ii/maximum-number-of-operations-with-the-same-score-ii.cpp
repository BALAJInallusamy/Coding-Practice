class Solution {
public:
    int dp[2000][2000];
    int rec(int score,int l, int r, int n,vector<int>& nums){
        if(l>=r) return 0;
        if(dp[l][r]!=-1) return dp[l][r];
        
        int one=0,two=0,three=0;
        
        if(l+1<=r && score== nums[l]+nums[l+1])
            one=1+rec(score,l+2,r,n,nums);
        
        if(score== nums[l]+nums[r])
            two=1+rec(score,l+1,r-1,n,nums); 
        
        if(l<=r-1 && score == nums[r]+nums[r-1])
            three=1+rec(score,l,r-2,n,nums);

        return dp[l][r]=max(one,max(two,three));  
         
    }
    int maxOperations(vector<int>& nums) {
        int n=nums.size();
        int s1=nums[1]+nums[0],s2=nums[0]+nums[n-1],s3=nums[n-2]+nums[n-1];
        if(n==2) return 1;
        int ans=0;
        memset(dp,-1,sizeof(dp));
        ans=max(ans,rec(s1,0,n-1,n,nums));
        memset(dp,-1,sizeof(dp));
        ans=max(ans,rec(s2,0,n-1,n,nums));
        memset(dp,-1,sizeof(dp));
        ans=max(ans,rec(s3,0,n-1,n,nums));
        
        
        return ans;
    }
};