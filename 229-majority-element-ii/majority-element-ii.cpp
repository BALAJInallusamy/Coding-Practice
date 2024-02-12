class Solution {
public:
vector<int> majorityElement(vector<int>& nums) {
int one=1e9+1,two=1e9+1,n=nums.size()/3 , c1=0,c2=0;
for(int i=0;i<nums.size();i++){
if(!c1 && nums[i]!=two) one=nums[i],c1++;else if(nums[i]==one) c1++;else if(!c2 && nums[i]!=one) two=nums[i],c2++;else if(nums[i]==two) c2++;if(nums[i]!=one && c1>0 && nums[i]!=two) c1--;if(nums[i]!=two && c2>0 && nums[i]!=one) c2--;if(c1==0) one=1e9+1;if(c2==0) two=1e9+1; 
}
c1=0;c2=0;vector<int> ans;
for (auto it:nums){
if(it==two) c2++;
if(it==one) c1++;
}
if(c1>n) ans.push_back(one);
if(c2>n) ans.push_back(two);
return ans;
}
};

