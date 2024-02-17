class Solution {
public:
    string lastNonEmptyString(string s) {
        //aabcbbca
        //a3 b3 c2
        unordered_map<char,int> mp;
        int maxi=0;
        for(auto it:s) mp[it]++,maxi=max(mp[it],maxi);
        
        string ans="";
        for(int i=s.size()-1;i>-1;i--){
            if(mp[s[i]]==maxi) ans+=s[i], mp[s[i]]=0;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};