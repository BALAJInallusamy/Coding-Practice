class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int> vec(n,1e9);
        vec[0] = 0 ;
        for(int i= 1 ; i< n ; i++){
            for(int j =i-1 ; j>=0 ; j--){
                if(nums[j]+j >= i)
                vec[i] = min(vec[i], vec[j]+1);
            }
        }

        return vec[n-1];
    }
};