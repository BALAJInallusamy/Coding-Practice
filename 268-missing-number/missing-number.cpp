class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int all=0 ,x=0, n = nums.size();
        for(int i =1 ; i<= n ; i++){
            all^=i;
            x^=nums[i-1];
        }
        return x^all;
    }
};