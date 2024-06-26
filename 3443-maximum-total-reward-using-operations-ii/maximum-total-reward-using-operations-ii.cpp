class Solution {
public:
    int maxTotalReward(vector<int>& a) {
        int n = a.size();
        bitset<100000> cap;
        bitset<100000> v;
        v.set(0);

        sort(a.begin(), a.end());

        int now = 0;
        for (int num : a) 
        {
            while (now < num) 
            {
                cap.set(now);
                now++;
            }
            v |= (v & cap) << num;
        }

        for (int i = 99999; i >= 0; --i) 
        {
            if (v.test(i))
                return i;
        }

        return -1;
    }
};