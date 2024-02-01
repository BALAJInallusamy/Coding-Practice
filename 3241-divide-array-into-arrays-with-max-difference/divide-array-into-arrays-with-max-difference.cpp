class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        for(int i=0;i<nums.size();){
            vector<int> temp;
            for(int j=0;j<3;j++) temp.push_back(nums[i++]);
            if(temp[2]-temp[0]>k) return {};
            ans.push_back(temp);
        }
        return ans;
    }
};