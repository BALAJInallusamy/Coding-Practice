class Solution {
public:
    void rec(int i, int n, string prev,string& s, unordered_set<string>& st, vector<string>& ans){
        if(i==n) {
            ans.push_back(prev);
            return;
            }
        for(int k=i;k<n;k++){
            string temp=s.substr(i,k-i+1);
            if( st.find(temp)!=st.end() ){ 
                if(prev.size()==0) rec(k+1,n,temp,s,st,ans);
                else rec(k+1,n,prev+" "+temp,s,st,ans);
            }
        }
        return;
        
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> st(wordDict.begin(),wordDict.end());
        int n=s.size();
        vector<string> ans;
        rec(0,n,"",s,st,ans);
        return ans;
    }
};