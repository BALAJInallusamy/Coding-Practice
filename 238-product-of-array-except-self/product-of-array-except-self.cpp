class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n= nums.size() , prod=1 , zeros=-1;
        vector<int> ans(n);
        for(int i=0;i<n;i++){
            if(nums[i] == 0 && zeros==-1) zeros=i;
            else if(nums[i] == 0 && zeros!=-1) return ans;
            else prod=prod*nums[i];
        }
        for(int i=0;i<n;i++){
            if(zeros==-1 ){
                ans[i] = prod/nums[i]; 
            }
            else{
                if(i==zeros) ans[i]=prod;
                else ans[i]=0;
            }
        }
        return ans;
    }
};