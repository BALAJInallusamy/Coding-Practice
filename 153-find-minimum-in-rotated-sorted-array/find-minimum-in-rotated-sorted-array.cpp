class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int l = 0, r = n-1, mid;
        int ans = nums[0];
        while(l<r){
            mid = (l+r)/2;
            ans = min(ans,nums[l]);

            if(nums[l]<nums[r]){
                break;
            }
            if(nums[mid]> nums[r]){
                l = mid+1;
                ans = min(ans,nums[r]);

            }
            else if(nums[mid]< nums[l]){
                r = mid-1;
            }
            ans = min(ans, nums[mid]);
        }
        return ans;
    }
};