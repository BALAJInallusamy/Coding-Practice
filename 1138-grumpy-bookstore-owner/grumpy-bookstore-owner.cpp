class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int n= customers.size();
        int l=0,r=0;
        int ans=0;
        for(int i=0;i<n;i++){
            if(grumpy[i]==0) ans+=customers[i];
        }
        int maxi=0;
        int temp=0;

        for(;r<minutes;r++){
                if(grumpy[r]==1) temp+=customers[r];
            }
        maxi=temp;
        while(r<n){
            if(grumpy[r]==1) temp+= customers[r];
            if(grumpy[l]==1) temp-= customers[l];
            r++;
            l++;
            maxi=max(temp,maxi);
        }
        return ans+maxi;
    }
};