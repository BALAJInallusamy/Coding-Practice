class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int x=0, n=nums.size() ;
        if(n==2) return nums;
        for(auto it:nums) x^=it;
        int a=0 , b=0, lower=0;
        while(( x & (1<<lower) )== 0){
            lower++;
        }
        cout<<x<<" "<<lower;
        for(int i=0; i<n; i++ ){
            if(( (nums[i]>>lower) &1 )==1) a^=nums[i];
            else b^=nums[i];
        }
        return {a,b};

    }
};
//101
//011
//110