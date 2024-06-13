int dp[1002][1002];
class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
       int n=nums1.size(), m=nums2.size();
       memset(dp,0,sizeof(dp));
       int ans=0;
       //if(nums1.back()== nums2.back()) dp[n-1][m-1]=1;

       for(int i=n-1;i>=0 ;i--){
        for(int j=m-1;j>=0 ;j--){

            if(nums1[i] != nums2[j]) dp[i][j]=0;
            else if(dp[i][j]!=0) continue;
            else{
                dp[i][j]=dp[i+1][j+1]+1;
                ans=max(dp[i][j],ans);
            }
        }
       } 
       return ans;
    }
};

// 1 2 1 1 3 2 1

// 3 2 1 2 1
//