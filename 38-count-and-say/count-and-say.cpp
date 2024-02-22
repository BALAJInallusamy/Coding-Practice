class Solution {
public:
    string countAndSay(int n) {
        string result = "1", curr;
        while(--n)
        {
            curr = "";
            for(int i = 0; i < result.length(); i++)
            {
                int cnt = 1;
                while(i < result.length()-1 && result[i] == result[i+1])
                {
                    cnt++;
                    i++;
                }

                curr +=  to_string(cnt) + result[i] ;
            }

            result = curr;
        }

        return result;
    }
};