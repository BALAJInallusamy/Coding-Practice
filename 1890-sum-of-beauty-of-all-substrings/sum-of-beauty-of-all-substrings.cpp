class Solution {
public:
    int beautySum(string s) {
        int n=s.size() , ans =0;
        for(int i=0;i<n;i++){
            vector<int> hash(26),freq(501);
            int mini=1, maxi=0;
            for(int j=i;j<n;j++){
                int c= s[j]-'a',f;
                f=++hash[c];
                maxi=max(f,maxi);

                freq[f]++;
                freq[f-1]--;
                if( f<mini ) mini=f;
                while(freq[mini]==0) mini++; 
                
                ans+=maxi-mini;
            }

        }
        return ans;
    }
};

// aabcbaa
// f[1]=1
// f[2]=2
// f[3]=
// f[4]=4