class Solution {
public:
    int findTheWinner(int n, int k) {
        vector<int> s(n);
        iota(s.begin(),s.end(),1);
        int last = 0;
        k--;
        while(s.size()>1){
            int ind = (last+k)%(s.size());
            s.erase(s.begin()+ind);
            last = ind;
        }
        return s[0];
    }
};