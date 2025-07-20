class Solution {
public:
    vector<vector<int>> ans;
    void rec(int i, int n, vector<int>& nums, vector<int> ds, int tar){
        if(tar<0) return;
        if(i==n) return;
        if(tar==nums[i]) {
            ds.push_back(nums[i]);
            ans.push_back(ds);
            return;
        }
        rec(i+1,n,nums,ds,tar);
        ds.push_back(nums[i]);
        rec(i,n,nums,ds,tar-nums[i]);
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        rec(0,nums.size(),nums,{},target);
        return ans;
    }
};