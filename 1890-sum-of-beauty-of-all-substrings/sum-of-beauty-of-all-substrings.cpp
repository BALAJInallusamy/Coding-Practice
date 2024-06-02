// class Solution {
// public:
//     int beautySum(string s) {
//         int n=s.size();
//         if(n==1) return 0;
//         vector<int> pre,hash(26);
//         for(auto it:s){
//             hash[it-'a']++;
//             pre.size()>0?pre.push_back(pre.back()+hash[it-'a']):pre.push_back(hash[it]-'a');
//         }

//         int ans=0;
//         for(int i=0;i<n-2;i++){
//             int maxi=pre[i];
//             if(i>0) maxi -= pre[i-1];
//             int mini=maxi;

//             for(int j=i+1;j<n;j++){
//                 min=min(pre[i])
               
//             }
//         }
//         return ans;
//     }
// };

// a a b c b a  a
// 1 3 4 5 7 10 14
// 

// 13457
// 22212
class Solution {
    public:
        int beauty(vector<int> &word){
            int mf=-1;
            int lf=1e9;
            for(int i=0; i<26; i++){
                mf=max(mf,word[i]);
                if(word[i]>=1){
                    lf=min(lf,word[i]);
                }
            }
            return mf-lf;
        }
        int beautySum(string s) {
            int result=0;
            for(int i=0; i<s.size(); i++){
                vector<int> word(26,0);
                for(int j=i; j<s.size(); j++){
                    word[s[j]-'a']++;
                    result=result+beauty(word);
                }
            }
            return result;

    }
};

