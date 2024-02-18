class Solution {
public:
    
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        unordered_set<string> st;
        int s=0,ans=0;
        string a="";
        for(auto it:arr1){
            a=to_string(it);
            s=a.size();
            for(int r=0;r<s;r++) st.insert(a.substr(0,r+1));
        }
        for(auto it:arr2){
            a=to_string(it);
            s=a.size();
            for(int r=0;r<s;r++){
                if(st.find(a.substr(0,r+1))!=st.end()) ans=max(ans,r+1); 
            }
        }
        return ans;
    }
};