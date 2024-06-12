class Solution {
public:
    void sortColors(vector<int>& nums) {
        int r=0, w=0, b=0;
        for(auto it: nums){
            if(it==0) r++;
            else if(it==1) w++;
            else b++;
        }
        for(int i=0;i<nums.size();i++){
            
            if(r>0) nums[i]=0,r--;
            else if(w>0) nums[i]=1,w--;
            else nums[i]=2,b--;
        }
    }
};