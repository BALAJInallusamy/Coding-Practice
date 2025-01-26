class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size();
        int ans =0;
        for(int i = 0 ; i< n ; i++){
            int l = i , r= i;
            while(l>-1 && r<n){
                if( s[l--] == s[r++]){
                    ans++;
                }
                else break;
            }
            if(i<n-1){
                l =i ; r = i+1;
            }
            while(l>-1 && r<n){
                if( s[l--] == s[r++]){
                    ans++;
                }
                else break;
            }
        }
        return ans;
    }
};