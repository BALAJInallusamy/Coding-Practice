class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> pre(n,1), suf(n,1);
        for(int i = 1 , j = n-2 ; i <n ; i++,j--){
            pre[i] = pre[i-1]*nums[i-1];
            suf[j] = suf[j+1]*nums[j+1];
        }
        // 1*1 1*2 1*
        for(int i = 0 ; i<n ; i++){
            // cout<<pre[i]<<" "<<suf[i]<<endl;
            nums[i] = pre[i]*suf[i];
        }
        return nums;
    }
};