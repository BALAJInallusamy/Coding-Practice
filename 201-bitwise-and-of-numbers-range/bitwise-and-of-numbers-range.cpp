class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        
        if(left == right) return right;
        int lmsb=0;
        while(left>>lmsb){
            lmsb++;
        }
        int rmsb=0;
        while(right>>rmsb){
            rmsb++;
        }
        if(lmsb!=rmsb) return 0;
        lmsb--;
        int ans=0;
        while(lmsb>-1 && ((left>>lmsb & 1)  == ( right>>lmsb & 1))){
            ans+=(left>>lmsb & 1)<<lmsb--;
        }
        return ans;

    }
};


