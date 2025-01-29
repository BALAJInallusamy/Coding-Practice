class Solution {
public:
    vector<vector<int>> ans;
    void rec(int i, vector<int>& nums, int n, int tar , vector<int> ds){
        if(tar <=0 ) {
            ans.push_back(ds);
            return;
        }
        if(i == n) return;
        rec(i+1, nums, n , tar, ds);
        if(nums[i]<= tar) {
            ds.push_back(nums[i]);
            rec(i, nums,n, tar - nums[i] , ds);
        }
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int tar) {
        int n = nums.size();
        rec(0,nums,n,tar,{});
        return ans;
    }
};