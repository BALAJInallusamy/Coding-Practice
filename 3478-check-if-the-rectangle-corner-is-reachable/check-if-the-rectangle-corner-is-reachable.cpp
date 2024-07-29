class Solution {
public:
    bool canReachCorner(int X, int Y, vector<vector<int>>& circles) {
        int n = circles.size();
        vector<int> all(n);
        vector<int> up(n),left(n),right(n),down(n),out(n);
        for(int i = 0 ;i<n ;i++) all[i]= i;
        
        function<void(int)> upf= [&] (int num){
            vector<int> it = circles[num];
            int r = it[2];
            int d = it[1] + r;
            if(d>= Y) up[num]++; 
        };
        function<void(int)>leftf = [&]  (int num){
            vector<int> it = circles[num];
            int r = it[2];
            int d = it[0] - r;
            if(d<=0 ) left[num]++; 
        };
        function<void(int)>  rightf = [&](int num){
            vector<int> it = circles[num];
            int r = it[2];
            int d = it[0] + r;
            if(d>= X) right[num]++; 
        };
        function<void(int)> downf = [&] (int num){
            vector<int> it = circles[num];
            int r = it[2];
            int d = it[1] - r;
            if(d <= 0) down[num]++; 
        };

        function<int(int)> find = [&](int i){
            if(i != all[i] ) all[i] = find(all[i]);
            return all[i];
        };

        function<void(int,int)> touch = [&](int i, int j){
            int r1 = circles[i][2], r2 = circles[j][2];
            double r = r1+r2;
            long long  sq= pow(circles[i][0]-circles[j][0],2) + pow(circles[i][1]-circles[j][1],2);
            double d = pow( sq,0.5 );
            if(d <= r ) {
                i = find(i);
                j = find(j);
                if(i!=j) all[j] = i;
            }
        };

        for(int i =0 ; i<n ; i++){
            if(out[i]) continue;
            upf(i);  leftf(i);    rightf(i);   downf(i);
            for(int j = i+1; j< n ;j++){
                if(out[j] ==0 ) touch(i,j);
            }
        }

        for( int i =0 ;i<n ; i++){
            int k = find(i);
            if(up[i]){
                for(int j =0 ; j<n ; j++){
                    if(up[j] ) continue;
                    if(find(j) == k) up[j]=1;
                }
            }
            if(down[i]){
                for(int j =0 ; j<n ; j++){
                    if(down[j]) continue;
                    if(find(j) == k) down[j]=1;
                }
            }if(left[i]){
                for(int j =0 ; j<n ; j++){
                    if(left[j]) continue;
                    if(find(j) == k) left[j]=1;
                }
            }if(right[i]){
                for(int j =0 ; j<n ; j++){
                    if(right[j]) continue;
                    if(find(j) == k) right[j]=1;
                }
            }
        }
        

        for(int i =0 ;i<n ; i++){
            if(up[all[i]] && (down[all[i]] || right[all[i]])) return false;
            if(left[all[i]] && (down[all[i]] || right[all[i]])) return false;
        }
        return true;
    }
};

