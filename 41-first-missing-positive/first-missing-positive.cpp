class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        if (nums.empty()) return 1;

        int n = nums.size();

        // Step 1: Mark non-positive integers as out of range
        for (int i = 0; i < n; ++i) {
            if (nums[i] <= 0)
                nums[i] = n + 1;
        }

        // Step 2: Mark visited indices
        for (int i = 0; i < n; ++i) {
            int num = abs(nums[i]);
            if (num <= n) {
                nums[num - 1] = -abs(nums[num - 1]);
            }
        }

        // Step 3: Find the first missing positive integer
        for (int i = 0; i < n; ++i) {
            if (nums[i] > 0)
                return i + 1;
        }

        // If all positive integers are present, return the next integer
        return n + 1;
    }
};