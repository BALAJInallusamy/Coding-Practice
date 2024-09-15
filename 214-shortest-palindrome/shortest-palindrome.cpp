class Solution {
public:

    string shortestPalindrome(string s) {
        string t = s;
        reverse(t.begin(),t.end()); 
        string rev =t;
        if(s == t) return s;
        int m = s.size();

        t=s+ '&' + t;
        int n = t.size();
        vector<int> lps(n);

        int j = 0, i =1;
        while(i<n){
            if(t[i] == t[j]) lps[i] = ++j, i++;
            else{
                if(j){
                    j = lps[j-1];
                }
                else{
                    lps[i] = 0;
                    i++;
                }
            }
   
        }
        // for(auto it:t) cout<<it<<" ";
        // cout<<endl;
        // for(auto it:lps) {
        //     cout<<it<<" ";
        // }
        string ans =rev.substr(0,m-lps.back()) + s;
        
        return ans;
    }
};

//   aacecaa a
// a aacecaa
// 01200012
// aa