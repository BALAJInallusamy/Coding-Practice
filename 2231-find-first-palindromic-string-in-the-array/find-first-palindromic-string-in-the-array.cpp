class Solution {
public:
bool rec(string s){
int r=s.size()-1;
int l=0;
while(l<=r){ if(s[l]==s[r]) l++,r--;
else return false;}
return true;
}
string firstPalindrome(vector<string>& words) {
for(int i=0;i<words.size();i++){
if(rec(words[i])) return words[i];
}
return "";
}
};