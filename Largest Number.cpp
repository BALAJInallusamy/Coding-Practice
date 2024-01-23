class Solution {
public:
    string largestNumber(vector<int>& nums) {
        if(count(begin(nums), end(nums), 0)==nums.size()) return "0";
        sort(begin(nums), end(nums), [](int a, int b){
            string at = to_string(a);
            string bt = to_string(b);
            return at+bt>=bt+at;
        });
        string res = "";
        for(auto it : nums){
            res+=to_string(it);
        }
        return res;
    }
};
