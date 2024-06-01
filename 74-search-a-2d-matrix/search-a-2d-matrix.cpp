class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n=matrix.size(),m=matrix[0].size();
        int top=0,down=n-1,l=0,r=m-1;

        if(target>matrix[n-1][m-1]) return false;
        int m1,m2;
        while(top<=down){
            m1=(top+down)/2;
            if( matrix[m1][0] <= target && matrix[m1][m-1] >= target) break;
            else if( matrix[m1][m-1] < target) top=m1+1;
            else down=m1-1;
        }

        while(l<=r){
            m2=(l+r)/2;
            if(matrix[m1][m2]==target) return true;
            else if(matrix[m1][m2]< target) l=m2+1;
            else r=m2-1;
        }
        return false;
    }
};