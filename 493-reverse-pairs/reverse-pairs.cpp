class Solution {
public:
    int counter(int i, int mid, int j,vector<int>& nums){
        int count=0;
        int left=i;
        
        for(int r=mid+1;r<=j;r++){
            
            while(left<=mid && nums[left]<=2*1LL*nums[r]) left++;
            count+=mid-left+1;
        }
        sort(nums.begin()+i,nums.begin()+j+1);
        return count;
    }
    int rec(int i, int j, vector<int> &nums){
        
        int mid=(j+i)/2;
        if(i>=j) return 0;
        return rec(i,mid,nums)+ rec(mid+1,j,nums)+ counter(i,mid,j,nums);
    }
    int reversePairs(vector<int>& nums) {
        return rec(0,nums.size()-1,nums);
    }
};

//  12 23 31 51
//  1223  1135
//