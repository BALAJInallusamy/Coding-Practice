class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = 0, n = nums.size(), ans = -1e9;
        for(int i =0 ; i < n ; i++){
            if(sum + nums[i]>=0){
                sum+=nums[i];
                ans = max(sum,ans);
            }
            else{
                ans = max(ans,nums[i]);
                sum = 0;
            }
        }
        return ans;
    }
};