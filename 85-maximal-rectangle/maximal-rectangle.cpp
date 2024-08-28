class Solution {
public:
    int maximalRectangle(vector<vector<char>>& mat) {
        int n = mat.size(), m = mat[0].size();
        vector<int> h(m+1,0);
        int ans = 0;
        for(int k = 0 ; k <n ; k ++){
            stack<int> mon;
            mat[k].push_back(0);

            for(int i = 0 ; i<m+1 ; i++){
                
                h[i] = (mat[k][i] =='1') ? h[i] + 1 : 0;

                while( mon.size() && h[mon.top()] >= h[i]){
                    int top = mon.top();
                    mon.pop();
                    int size = mon.size()>0  ? mon.top(): -1;
                    ans = max(ans, h[top]*(i-size -1 ));
                
                }
                mon.push(i);
            }
            cout<<endl;
        }
        return ans;
    }
};

// h = 3 1 3 2 2
// -1 3 1
// 1 3 

