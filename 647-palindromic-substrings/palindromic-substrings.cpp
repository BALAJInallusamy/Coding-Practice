class Solution {
public:
    int countSubstrings(string s) {
        int left=0;
        int n=s.size(),ans=0;
        int i,j;
        ans+=n;
        for(left=0;left<n;left++){
            i=left-1;j=left+1;
            while(i>-1 && j<n){
                if(s[i]==s[j]) ans++,i--,j++;
                else break;
            }
            i=left;j=left+1;
            if(s[i]==s[j]){
                ans++;
                i=left-1;j=left+2;
                while(i>-1 && j<n){
                    if( s[i]==s[j]) ans++,i--,j++;
                    else break;
                }
            }
        }
        return ans;
    }
};
      


