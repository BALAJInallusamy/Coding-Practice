class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n=matrix.size(), m=matrix[0].size();
        int top=0, down= n-1, left =0, right=m-1;
        vector<int> ans;
        while(top<=down && left<=right){
            
            for(int i=left;i<=right;i++) ans.push_back(matrix[top][i]);
            top++;
            if(top>down) break;
            for(int i=top;i<=down;i++) ans.push_back(matrix[i][right]);
            right--;
            if(right<left) break;
            for(int i=right;i>=left;i--) ans.push_back(matrix[down][i]);
            down--;
            if(down<top) break;
            for(int i=down;i>=top;i--) ans.push_back(matrix[i][left]);
            left++;
            if(right<left) break;

        }
        return ans;
    }
};