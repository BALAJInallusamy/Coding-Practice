class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> st;
        int n = s.size();
        int ans = 0;
        vector<int> hash(n+1);
        for(int i = 0 ; i < n ; i++){

            if(s[i] == '(') {st.push(i);}
            
            else{
                if(!st.empty()) {
                    int j = st.top();
                    st.pop();
                    hash[i+1] -= 1;
                    hash[j] +=1;
                }
                else continue;
            }
        }
        int count = hash[0];
        for(int i = 1 ; i< n; i++){
            hash[i] += hash[i-1];
            if(hash[i]>0) count ++,ans= max(ans,count);
            else count =0;
        }
        return ans;
    }
};