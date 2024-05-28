class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<int,int> hash;
        int n=s.size(), l=0,r=0, ans=0,count=0;
        while(l<=r && r<n){

            if(hash[s[r]]==0){ 
                ans=max(ans,r-l+1);
                ++hash[s[r++]];
                }

            else{
                --hash[s[l++]];
            }
        }
        return ans;
    }
};