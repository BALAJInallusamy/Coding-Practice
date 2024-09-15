class Solution {
public:
    string longestPrefix(string s) {
        int n = s.size();
        vector<int> lps(n);
        int j =0 , i = 1;
        string ans = "";
        while(i<n){
            if(s[i] == s[j]){
                j++;
                lps[i] = j;
                i++;
            }
            else{
                if(j) j = lps[j-1];
                else{
                    i++;
                }
            }
        }
        ans = s.substr(i-lps.back(),lps.back());
        return ans;
    }
};