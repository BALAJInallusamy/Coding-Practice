class Solution {
public:
    string rec(int i, int n, string a){
        if(i>n) return a;
        int m=a.size(),k=0,count=0,j=0;
        string x="";
        while(k<m && j<m){
            if(a[k]==a[j]) count++,j++;
            else x+=to_string(count)+a[k], k=j, count=0;
        }
        x+=to_string(count)+a[k];
        return rec(i+1,n,x);
    }
    string countAndSay(int n) {
        if(n==1) return "1";
        return rec(2,n,"1");
    }
};