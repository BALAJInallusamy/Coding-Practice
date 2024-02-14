class Solution {
public:
vector<int> rearrangeArray(vector<int>& nums) {
vector<int> pos;
vector<int> neg;
for(auto it:nums){
if(it>0) pos.push_back(it);
else neg.push_back(it);
}
for(int i=0,j=0,k=0;i<nums.size();i++){
i%2==0?nums[i]=pos[j++]:nums[i]=neg[k++];
}
return nums;
}
};