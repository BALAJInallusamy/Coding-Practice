class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        int x = 0;

        while (left != right)
        {
            
            left >>= 1;
            right >>= 1;
            x++;
        }

        while (x)
        {
            left <<= 1;
            right <<= 1;
            x--;
        }

        return left;
    }
};