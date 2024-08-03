
class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> pre(n+1);
        vector<vector<int>> dp(k,vector<int> ( n , 1e9));
        for(int i =0 ;i<n ; i++ ){
            pre[i+1] = pre[i] + nums[i];
        }
        for(int j = 0 ; j< n ; j++){
            dp[0][j] = pre[j+1] - pre[0];
        }

        for(int m = 1; m < k ; m++){
            for(int i = m ; i< n ; i++){
                for(int j = m-1 ; j<i ; j++ ){

                    int sub = pre[i+1] - pre[j+1];
                    dp[m][i] = min( max(dp[m-1][j] , sub), dp[m][i] );

                }
            }
        }
        // for(auto it:dp){
        //     for(auto x : it) cout<<x<<" ";
        //     cout<<endl; 
        // }
        return dp[k-1][n-1];
    }
};

// dp[m][i] => minimum largest sum of m groups which end at i 
// 7 2 5 10 8
//   i
//  j