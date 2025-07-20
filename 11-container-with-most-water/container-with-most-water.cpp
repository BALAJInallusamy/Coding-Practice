class Solution {
public:
    int maxArea(vector<int>& nums) {
        int n = nums.size();
        int l = 0 , r= n-1;
        int ans = 0;
        while(l<=r){
            ans = max(ans, (r-l)*min(nums[l],nums[r]));
            if(nums[l]<=nums[r]) l++;
            else r--;
        }
        return ans;
    }
};