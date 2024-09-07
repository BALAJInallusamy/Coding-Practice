class Solution {
public:
    int minOperations(vector<int>& A, int target) {
        vector<int> count(32,0);
        int n = A.size();
        int m = 0;
        long long s = 0;
        for(int i = 0 ; i< n ; i++){
            count[log2(A[i])]++;
            s+= A[i];
        }
        if(s<target) return -1;
        for(int i =0 ; i< 32 ; i++){
            if(count[i]) m = i;
        }

        int ans = 0;

        for(int i = 0 ; i< m+1; i++){

            // for(auto it: count) cout<<it<<" ";
            // cout<<endl;

            if((target & (1<<i)) != 0 ){

                if( count[i] > 0 ){
                    count[i]--;
                }
                else{
                    for(int j = i+1 ; j< m+1 ; j++){
                        ans++;
                        if(count[j] != 0){ 
                            count[j]--; 
                            break;
                        }
                        else{
                            count[j] = 1;
                        }
                    }
                }
            }
            count[i+1] += count[i]/2;
            count[i] -= ((int)(count[i]/2))*2;
        }
        return ans;
    }
};
//       368421
// 12 -> 001100
// 1 2 4 8 16 32
// 2 1 0 0 0 1
// 0 3 0 0 0 1
// 0 1 1 0 0 1
// 0 1 1 0 2 0
// 0 1 1 2 1 0

// 1 1 2 16 16
// 1 1 2 8 8 16

// 12 -> 4 4 4 , 1 1 2

// 100011
// 0= 1 1 =1 32 1