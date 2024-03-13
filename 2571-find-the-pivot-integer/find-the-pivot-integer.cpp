class Solution {
public:
    int pivotInteger(int n) {
        int tot= n*(n+1)/2, sum=0 ;
        for(int i=1;i<=n;i++){
            sum += i;
            if(sum == tot - sum+ i)
                return i;
        }
        return -1;
    }
};