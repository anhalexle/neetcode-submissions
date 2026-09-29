class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        // dp[i] = 1 + max(dp[j]) with j must valid: nums[j] > nums[i]
        vector<int> mem(nums.size(), -1); // -1 no compute
        int longest = 0;
        for (int i = 0; i < nums.size();i++)
        {
            longest = max(longest, dp(nums, i, mem));
        }
        return longest;
    }
private:
    int dp(vector<int>& nums, int index, vector<int>& mem)
    {
        if (mem[index] != -1) return mem[index];
        int longestLength = 1; // base case
        for (int j = index + 1; j < nums.size(); j++)
        {
            if (nums[j] > nums[index])
            {
                longestLength = max(longestLength, 1 + dp(nums, j, mem));
            }
        }
        mem[index] = longestLength;
        return longestLength;
    }
};
