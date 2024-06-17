class Solution {
public:
    bool judgeSquareSum(int c) {
        int root=pow(c,0.5);
        if(root*root == c) return 1;
        for(int i=1;i<=root;i++){
            double b= pow(c- i*i,0.5);
            if(b == int(b)) return 1;
        }
        return false;
    }
};