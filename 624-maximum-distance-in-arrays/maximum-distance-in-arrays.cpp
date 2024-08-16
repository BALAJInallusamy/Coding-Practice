class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        multiset<int> s;
        for(auto it : arrays){
            int n  = it.size();
            int mini = it[0], maxi = it[n - 1];
            s.insert(mini); s.insert(maxi);
        }
        int ans = -1e9;
        for(auto it : arrays){
            int n  = it.size();
            int mini = it[0], maxi = it[n - 1];
            s.erase(s.find(mini));
            ans = max(ans, abs(maxi - *s.begin())); ans = max(ans, abs(maxi - *s.rbegin()));
            s.insert(mini);
            s.erase(s.find(maxi));
            ans = max(ans, abs(mini - *s.begin())); ans = max(ans, abs(mini - *s.rbegin()));
            s.insert(maxi);
        }
        return ans;
    }
};