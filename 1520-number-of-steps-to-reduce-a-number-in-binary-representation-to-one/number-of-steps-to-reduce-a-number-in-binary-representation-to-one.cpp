class Solution {
public:
    int numSteps(string s) {
        int n=s.size(),ans=0,r=0;
        for(int i=n-1;i>0;i--){
            if(r==0){
                if(s[i]=='1') r=1,ans+=2;
                else ans++;
            } 
            else{
                if(s[i]=='1') ans++,r=1;
                else ans+=2,r=1;
            }
        }
        if(s[0]=='1' && r==1) ans++;
        return ans;
    }
};