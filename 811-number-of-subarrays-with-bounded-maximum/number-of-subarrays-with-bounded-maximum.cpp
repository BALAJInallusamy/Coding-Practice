class Solution {
public:
    int numSubarrayBoundedMax(vector<int>& A, int L, int R) {
        int res = 0, heads = 0, tails = 0;
        for (int val : A) {
            if (L <= val && val <= R) {
                // val is a head. All tails promoted to heads
                heads+= tails + 1;
                tails = 0;
                res += heads;
            }
            else if (val < L) {
                // val is a tail, can extend existing subarrays
                tails++;
                res += heads;
            }
            else {
                // combo breaker
                heads = 0;
                tails = 0;
            }
        }
        return res;
    }
};