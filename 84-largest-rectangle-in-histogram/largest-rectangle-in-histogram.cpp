class Solution {
public:
    int largestRectangleArea(vector<int>& nums) {
        nums.push_back(0);
        int n = nums.size();
        stack<int> st;
        int l = 0 , r =0, ans = 0;
        while(r<n){
            if(st.size() ==0 ) st.push(r++);
            else if(nums[st.top()] < nums[r] ){
                st.push(r++);
            }
            else{
                int h = nums[st.top()];
                st.pop();
                int i = -1 ;
                if(st.size()) i = st.top();
                ans = max(ans, h*(r-i -1));
            }
        }
        return ans;
    }
};

// 3 4 5 6 4 3 2 1  = 18
// 1 2 3 4 5 6 7 8  