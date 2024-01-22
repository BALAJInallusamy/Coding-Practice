class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n=gas.size();
        int sum=0;
        for(int i=0;i<n;i++) gas[i]=gas[i]-cost[i], sum+=gas[i];
        if(sum<0) return -1;
        sum=0;
        int j,x;
        for(int i=0;i<n;i++){
            if(gas[i]>0){
                sum=0;
                j=i,x=n;
                while(x>0){
                    sum+=gas[(j++)%n];
                    if(sum<0){i=j-1; break;}
                    x--;
                }
            if(x==0) return i;
            }
        }
        return 0;
    }
};
