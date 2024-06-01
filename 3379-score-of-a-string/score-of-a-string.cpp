class Solution {
public:
    int scoreOfString(string s) {
        int ans=0;
        for(int i=0;i<s.size();i++){
            ans+=i>0?abs(s[i]-s[i-1]):0;
        }
        return ans;
    }
};