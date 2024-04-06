class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<int> st;
        int n=s.size();
        for(int i=0;i<n;i++){
            if(s[i]==')' && st.empty()) s.erase(s.begin()+i,s.begin()+i+1),i--;
            else if(s[i]=='(') st.push(i);
            else if(s[i]==')') st.pop();
        }
        while(!st.empty()){
            int i=st.top();
            st.pop();
            s.erase(s.begin()+i,s.begin()+i+1);
        }
        return s;
    }
};