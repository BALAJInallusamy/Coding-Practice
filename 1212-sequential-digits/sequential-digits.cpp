class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> ans;
        int x,y,num;
        for(int i=1;i<9;i++){
            x=i+1;
            num=x+(i*10);
            while(num<=high){
                if(num>=low) ans.push_back(num);
                x=x+1;
                if(x==10) break;
                num=(num*10)+x;
            }
            
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};