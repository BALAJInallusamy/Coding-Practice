class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0, curr = prices[0];
        int n = prices.size();
        for(int i = 1 ; i < n ; i++){
            if(prices[i] < curr){
                curr = prices[i];
            }
            else ans = max(ans, prices[i]-curr);
        }
        return ans;
    }
};