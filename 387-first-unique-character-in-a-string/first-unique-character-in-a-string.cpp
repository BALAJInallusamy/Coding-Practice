class Solution {
public:
    int firstUniqChar(string s) {
        vector<int> mp(26);
        int n=s.size();
        for(int i=0;i<n;i++){ 
            mp[s[i]-'a']++;
            }
        for(int i=0;i<n;i++){
            if(mp[s[i]-'a']==1) return i;
        }
        return -1;
    }
};