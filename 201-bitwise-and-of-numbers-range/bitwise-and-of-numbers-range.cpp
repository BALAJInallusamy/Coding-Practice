class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        int c = 0;
        while(left!=right){
            left>>=1;
            right>>=1;
            c++;
        }
        left<<=c;
        return left;
    }
};



// 1010 
// 1011