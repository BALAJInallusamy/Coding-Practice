class Solution {
public:
    int repeatedStringMatch(string a, string b) {
        int n = a.size() , m = b.size();
        vector<int> start;

        if( m ==0 ) return 0;

        for(int i = 0 ;i<n ; i++){
            if(a[i] == b[0]) start.push_back(i);
        }

        if(start.size()==0) return -1;

        for(int k = 0 ; k< start.size() ; k++){

            int i = start[k];
            int j = 0;
            int count = 1;

            while( j< m && a[i] == b[j] ){
                i++;j++;
                i= i%n;
                if(j==m) return count;
                if( i == 0) count++;
            }
        }
        return -1;
    }
};