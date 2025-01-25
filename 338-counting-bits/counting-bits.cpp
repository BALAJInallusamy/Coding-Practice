class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> nums(n+1);
        
        for(int i=0 ; i<= n && i<2; i++){
            nums[i]=i;
        }
        for(int i = 2 ; i<=n ; i*=2){
            for(int j=0; j<i && (j+i) <= n;j++){
                nums[i+j] = 1 + nums[j];
            }
        }
        return nums;
        // 00000
        // 00001
        // 00010
        // 00011
        // 00100
        // 00101
        // 00110
        // 00111

    }
};