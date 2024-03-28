class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        int i=0;
        int j=0;
        int max_length=0;
        while(j<nums.size()) {
            mp[nums[j]]++;
            while(mp[nums[j]]>k) {
                mp[nums[i]]--;
                i++;
            }
            max_length=max(max_length,j-i+1);
            j++;


        }
        return max_length;
    }
};