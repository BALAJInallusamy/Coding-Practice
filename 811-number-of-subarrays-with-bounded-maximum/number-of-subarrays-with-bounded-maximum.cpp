class Solution {
public:
    int numSubarrayBoundedMax(vector<int>& nums, int left, int right) {
        int n = nums.size();
        int bad = -1, good = -1;
        int ans = 0;
        for(int i = 0 ; i<n ; i++){
            if(nums[i] > right ){
                bad = i;
            }
            if(nums[i] >= left && nums[i]<= right){
                good = i;
            }
            // cout<<good-bad<<" ";
            ans += max(0,good - bad);
        }
        return ans;
    }
};