class Solution {
public:
    string minWindow(string s, string t) {
        int n=s.size(),k=t.size();
        string ans;
        unordered_map<char,int> mp2,mp1;
        for(int i=0;i<k;i++){
            mp2[t[i]]++;
        }
        int slow=0,high=0,count=0,mini=n+1;
        for(;high<n;high++){
            char c=s[high];
            if(mp2.find(c)!=mp2.end()){
                mp1[c]++;
                if(mp1[c]<=mp2[c]) count++;
            }
            if(count==k){
                while(mp2.find(s[slow])==mp2.end() || mp1[s[slow]]>mp2[s[slow]]){
                    mp1[s[slow]]--;
                    slow++;
                }
                if(high-slow+1<mini)
                mini=high-slow+1,
                ans=s.substr(slow,mini);
            }    
        }
    return ans;
    }
};