class Solution {
public:
    int rec(int start, int n, vector<vector<int>>& split, vector<vector<int>>& dp, int k){

        if(start>=n ) return -1e9;
        if(k==0) return split[start][n-1];

        if(dp[start][k]!=-1) return dp[start][k];

        int ans=INT_MAX;
        for(int i=start; i<n; i++){
            
            int next= rec(i+1,n,split,dp,k-1);
            int cur= max( split[start][i], next );
            ans = min(ans , cur);
        }
        return dp[start][k]=ans;
    }
    int splitArray(vector<int>& nums, int k) {
        int n= nums.size();
        vector<vector<int>> split(n,vector<int> (n));

        for(int i=0;i<n;i++){
            split[i][i]=nums[i];
            for(int j=i+1;j<n;j++){
                split[i][j] = nums[j] + split[i][j-1];
            }
        }
        vector<vector<int>> dp(n,vector<int>(k,-1));


        
       int ans = rec(0,n,split,dp,k-1);

        for(auto it:dp){
            for(auto x:it){
                cout<<x<<" ";
            }
            cout<<endl;
        }
        return ans;
        
    }
};