class Solution {
public:
    long long minDamage(int power, vector<int>& damage, vector<int>& health) {
        int n = damage.size();
        vector<vector<double>> nums(n);
        for(int i = 0 ; i< n ; i++){
            int time= (health[i] + power - 1)/power;
            nums[i]= { (double )damage[i]/time , double (i)};
        }
        sort(nums.rbegin(),nums.rend());
        long long ans = 0;
        int time = 0;
        for(int i = 0 ; i< n ; i++){
            int ind = nums[i][1];
            time+= (health[ind] + power - 1)/power;
            ans += damage[ind]*(time);
        }
        return ans;
    }
};