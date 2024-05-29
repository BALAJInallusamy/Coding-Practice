class Solution {
public:
    int minMovesToMakePalindrome(string s) {
    int n=s.size();
    int p=0;
    int q=n-1;
    int ans=0;
    int y=-1;
    while(p<=q)
    {
        if(s[p]!=s[q])
        {
            int temp=q-1;
            while(s[temp]!=s[p])
                temp--;
            if(temp!=p)
            {
                for(int i=temp;i<q;i++)
                {
                    swap(s[i],s[i+1]);
                    ans++;
                }
            }
            else
            {
                y=p;
                q++;
            }
        }
        p++;
        q--;
    }
    if(y!=-1)                          //  If the frequency of a particular letter is odd
    {   int x=    s.size()/2-y;
    if(x<0) x=-x;                        
        ans+=x;     // This is the required swaps to bring that letter to the middle
    }
    return ans;
}
};