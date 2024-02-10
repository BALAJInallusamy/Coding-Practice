class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int t) {
        int n=nums.size();
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
        for(int i=0;i<n-3;i++){
            if(i>0 && nums[i]==nums[i-1]) continue;
            for(int j=i+1;j<n-2;j++){
                if(j!=i+1 && nums[j]==nums[j-1]) continue;
                for(int k=j+1 , l=n-1; k<l; ){
                    long long sum=nums[i];
                    sum+=nums[j];
                    sum+=nums[k];
                    sum+=nums[l];
                    if(sum==t){ 
                        ans.push_back({nums[i],nums[j],nums[k],nums[l]});
                        l--;
                        k++;
                    while(k<l && k!=j+1 && nums[k]==nums[k-1]) k++;
                    while(k<l && l!=n-1 && nums[l]==nums[l+1]) l--;
                    }
                    else if(sum>t) l--;
                    else k++;
                    

                }
            }
        }
        return ans;
    }
};