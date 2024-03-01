class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int o = 0 , n= s.size() , i= 0;
        for(auto it:s) o += (it=='1');
        o--;
        s[n-1] = '1';
        while(o--) s[i++] = '1';
        while(i<n-1) s[i++] = '0';
        return s;
    }
};