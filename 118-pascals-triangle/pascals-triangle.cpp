class Solution {
public:
    vector<vector<int>> generate(int n) {
        vector<vector<int>> ans;
        for(int i=0;i<n;i++) ans.push_back(vector<int>(i+1,1));
        int m=1;
        while(m<n){
            for(int i=1;i<m;i++){
                ans[m][i]=ans[m-1][i]+ans[m-1][i-1];
            }
            m++;
        }
        return ans;
    }
};

// 1
// 1 1
// 1 2 1
// 1 3 3  1
// 1 4 6  4  1
// 1 5 10 10 5 1

// 0 1 2  3  4 5

//-1 0=>0
// 0 1=>1
// 1 2=>2
// 2 3=>3