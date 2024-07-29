class Solution {
public:
    int numTeams(vector<int>& nums) {
        int n = nums.size();
        int dp[n][3];
        memset(dp,0,sizeof(dp));

        for(int i =0 ; i<n ; i++) dp[i][0] = 1;

        for(int k =1 ;k< 3; k++){
            for(int i =0 ;i<n ; i++){
                for(int j=i-1 ; j >=0 ; j--){
                    if(nums[j] < nums[i]){
                        dp[i][k] += dp[j][k-1];
                    }
                }
            }
        }
        
        int ans = 0;
        for(int i =0 ;i<n ;i++) ans+= dp[i][2];
        memset(dp,0,sizeof(dp));

        for(int i =0 ; i<n ; i++) dp[i][0] = 1;

        for(int k =1 ;k< 3; k++){
            for(int i =0 ;i<n ; i++){
                for(int j=i-1 ; j >=0 ; j--){
                    if(nums[j] > nums[i]){
                        dp[i][k] += dp[j][k-1];
                    }
                }
            }
        }
        
        for(int i =0 ;i<n ;i++) ans+= dp[i][2];

        
        return ans;
    }
};

//  2 5 3 4 1
//  1 1 1 1 1
//  1 2 2 4 1

// 3=> 23, 3
// 4=> 234,34, 24,4

// 1 2 3 4
// 1 2 4 8 => (1234, 134, 234, 34, 124) + 14, 24, 4

// k =0
// 1 2 3 4
// 1 1 1 1
// k=1
//   12      3=> 12 13 23
// 0 1 2 3 => 14 24 34   
// k=2
// 0 0 1 3=> 1= 123, 3 = 124,234, 234

// 123
// 234
// 124
// 134