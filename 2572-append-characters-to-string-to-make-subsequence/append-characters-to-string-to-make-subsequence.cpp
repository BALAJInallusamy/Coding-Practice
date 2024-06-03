class Solution {
public:
    int appendCharacters(string s, string t) {
        int n=s.size(),m=t.size();
        int ans=m;
        for(int i=0,j=0;i<n && j<m ;i++){
            if(s[i]==t[j]) j++;
            ans=min(m-j,ans);
        }
    return ans;
    }
};