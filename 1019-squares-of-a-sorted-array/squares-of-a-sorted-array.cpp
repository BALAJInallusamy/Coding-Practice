class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int l=0,n=nums.size();int r=n-1;
        vector<int> ans(n);
        while(l<=r){
            if(abs(nums[l])>=abs(nums[r])) ans[r-l]=nums[l]*nums[l],l++;
            else ans[r-l]=nums[r]*nums[r],r--;
        }
        return ans;
    }
};