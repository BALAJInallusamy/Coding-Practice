class Solution {
public:
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {
        int lr =1 , td = 1;
        int c1 =1;
        

        sort(hBars.begin(),hBars.end());
        sort(vBars.begin(),vBars.end());
        
        int k = hBars.size(), l = vBars.size();
        if(k >= 1) lr = 2;
        if(l >= 1) td = 2;

        for(int i = 1 ;  i < k ; i++){
            if(hBars[i]- 1 != hBars[i-1]) c1 = 1;
            else{
                c1++;
                lr = max(c1+1,lr);
            }
        }
        c1= 1;
        for(int i = 1 ;  i < l ; i++){
            if(vBars[i]- 1 != vBars[i-1]) c1 = 1;
            else{
                c1++;
                td = max(c1+1,td);
            }
        }
        

        return min(lr,td)*min(lr,td);
    }
};

// 1 0 1
// 1 0 1 1