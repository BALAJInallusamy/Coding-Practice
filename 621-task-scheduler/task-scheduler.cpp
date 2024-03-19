class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char,int> mp;
        for(auto it:tasks) mp[it]++;
        int maxi=0,count=0;
        for(auto it:mp) {
            if(it.second>maxi) maxi=it.second,count=0;
            else if(it.second==maxi) count++;
        }
        int ans=(maxi-1)*n+count+maxi;
        if(ans<tasks.size()) ans=tasks.size();
        return ans;
    }
};

