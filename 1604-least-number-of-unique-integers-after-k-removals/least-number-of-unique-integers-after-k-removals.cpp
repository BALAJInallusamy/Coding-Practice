class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int,int> mp;
        vector<int> nums;
        int n=0;
        for(auto it:arr){
            mp[it]++;
        }
        for(auto it:mp){
            n++;
            nums.push_back(it.second);
        }
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++){
            k-=nums[i];
            if(k<0) return n-i;
        }
        return 0;
    }
};
