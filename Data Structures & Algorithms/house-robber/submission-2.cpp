class Solution {
public:
    int rob(vector<int>& nums) {
        // the equation here is f(i) = std::max(f(i + 1), nums[i] + f(i + 2))
        vector<int> mem(nums.size(), -1); // -1: no rob
        int max = 0;
        for (int index = 0; index < nums.size(); index++)
        {
            max = std::max(max, dp(nums, index, mem));
        }
        return max;
    }
private:
    int dp(vector<int>& nums, int index, vector<int>& mem)
    {
        if (index >= nums.size()) return 0;
        if (mem[index] != -1) return mem[index];

        mem[index] = std::max(dp(nums, index + 1, mem), nums[index] + dp(nums, index + 2, mem));
        return mem[index];
    }
};
