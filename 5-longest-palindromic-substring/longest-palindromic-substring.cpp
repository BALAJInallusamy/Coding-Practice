class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.size();
        pair<int,int> ans={0,0};
        for(int i=0;i<n;i++){
            int l=i,r=i;
            while( l>-1 && r<n ){
                if( s[l]==s[r] ) {
                    if(ans.first<r-l+1) ans={r-l+1,l};
                    l--;
                    r++;
                    }
                else break;
            }
            l=i; r=i;

            if(i<n-1) r++;
            else break;

            while(l>-1 && r<n){
                if( s[l]==s[r] ) {
                    if(ans.first<r-l+1) ans={r-l+1,l};
                    l--;r++;
                    }
                else break;
            }
        }
        return s.substr(ans.second,ans.first);
    }
};